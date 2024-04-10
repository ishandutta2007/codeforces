#include <cstdio>
#include <algorithm>

#define I first
#define J second

using namespace std;

const int MAXN = 5005;
const int MAXX = 10001;
const int MOD = 1000000007;

pair <int, int> last[MAXX], next[MAXN][MAXN];
int prev[MAXN], f[MAXN];

int x[MAXN], y[MAXN];
int n, m;

int UPD(int x)
{
    if (x == prev[x]) return x;
    int res = UPD(prev[x]);
    f[x] ^= f[prev[x]];
    prev[x] = res;
    return res;
}


int UNION(int x, int y)
{
//    printf("u: %d %d\n", x, y);

    int rx = UPD(x);
    int ry = UPD(y);

    if (rx == ry)
        return f[x] ^ f[y]? 0 : -1;

    prev[ry] = rx;
    f[ry] = f[x] ^ f[y] ^ 1;
    m--;
    return 1;
}


long long powmod(int a, int b, int m)
{
    if (b == 0) return 1;
    long long res = powmod(a, b >> 1, m);
    res = res * res % m;
    return b & 1? res * a % m : res;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &x[i], &y[i]);

    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            int d = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            next[i][j] = last[d];
            last[d] = make_pair(i, j);
        }

    for (int i = 1; i <= n; i++)
    {
        prev[i] = i;
        f[i] = 0;
    }

    int ans = 0;
    m = n;
    for (int i = MAXX - 1; i >= 0; i--)
    {
        bool f = true;
        int k = m;
        for (pair <int, int> j = last[i]; j != make_pair(0, 0) && f; j = next[j.I][j.J])
            f = UNION(j.I, j.J) >= 0;

        if (!f)
        {
            ans = i;
            m = k;
            break;
        }
    }
    printf("%d\n", ans);
    printf("%d\n", powmod(2, m, MOD));
    return 0;
}