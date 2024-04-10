#include <cstdio>
#include <algorithm>

using namespace std;


#define T first
#define P second

const int MAXN = 1000;
const int MAXM = 123;
const int MOD = 12345;

int f[26], cnt = 1;
pair <int, int> b[MAXN];
int a[MAXN];
int d[MAXM][MAXM], e[MAXM][MAXM];
long long n;
int m, c;

int multi(int a[MAXM][MAXM], int b[MAXM][MAXM])
{
    int c[MAXM][MAXM];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
        {
            long long res = 0;
            for (int k = 0; k < m; k++)
                res += a[i][k] * b[k][j];
            c[i][j] = res % MOD;
        }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = c[i][j];
    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    scanf("%I64d %d\n", &n, &c);
    m = 1;
    for (int i = 0; i < c; i++)
    {
        char c;
        int p;
        scanf("%c %d\n", &c, &p);
        b[i] = make_pair(c - 'A', p);
    }
    sort(b, b + c);
    c = unique(b, b + c) - b;

    for (int i = 0; i < c; i++)
    {
        m *= b[i].P;
        f[b[i].T] = cnt;
    }

    for (int i = 0, x; i < m; i++)
    {
        x = i;
        for (int j = 0; j < c; j++)
        {
            a[j] = x % b[j].P;
            x /= b[j].P;
        }

        for (int j = 0; j < 26; j++)
            if (f[j] == cnt)
            {
                x = 0;
                for (int k = c - 1; k >= 0; k--)
                    (x *= b[k].P) += (a[k] + (b[k].T == j)) % b[k].P;
                d[i][x]++;
            }
    }

    for (int i = 0; i < m; i++)
        e[i][i] = 1;
    
    while (n)
    {
        if (n & 1) multi(e, d);
        if (n >>= 1) multi(d, d);
    }


    int ans = 0;
    for (int i = 0, x; i < m; i++)
    {
        cnt++;
        x = i;
        for (int j = 0; j < c; j++)
        {
            if (x % b[j].P == 0)
                f[b[j].T] = cnt;

            x /= b[j].P;
        }


        bool flag = true;
        for (int j = 0; j < 26 && flag; j++) 
            flag = f[j] == 0 || f[j] == cnt;

        if (flag)
            (ans += e[0][i]) %= MOD;
    }
    printf("%d\n", ans);
    return 0;
}