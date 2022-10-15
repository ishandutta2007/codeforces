#include <cstdio>
#include <queue>

using namespace std;


const int MAXN = 3003;
const int MAXM = 20002 << 1;
const int MAXK = 100001;

int elast[MAXN];
int enext[MAXM], edest[MAXM];
int last[MAXN][MAXN];
int next[MAXK], dest[MAXK];
int f[MAXN][MAXN];
int c[MAXN];
int n, m, k;
int ans;

queue < pair <int, int> > q;

int add(int x, int y, int p)
{
    if (f[x][y]) return 0;
    if (y == n) ans = x;
    f[x][y] = p;
    q.push(make_pair(x, y));
    return 0;
}

int rec(int x, int y, int d)
{
    if (f[x][y] == -1)
    {
        printf("%d\n", d);
        printf("%d", y);
        return 0;
    }
    rec(f[x][y], x, d + 1);
    printf(" %d", y);
    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        edest[i] = y;
        enext[i] = elast[x];
        elast[x] = i;

        edest[i + m] = x;
        enext[i + m] = elast[y];
        elast[y] = i + m;
    }
    for (int i = 1; i <= k; i++)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);

        dest[i] = z;
        next[i] = last[x][y];
        last[x][y] = i;
    }

    add(1, 1, -1);
    int cnt = 0;
    while (q.size() && ans == 0)
    {
        int 
            x = q.front().first,
            y = q.front().second;
        q.pop();

        cnt++;
        for (int i = last[x][y]; i; i = next[i])
            c[dest[i]] = cnt;

        for (int i = elast[y]; i; i = enext[i])
            if (c[edest[i]] != cnt)
                add(y, edest[i], x);
    }
    if (ans == 0)
        printf("-1");
    else
        rec(ans, n, 0);
    printf("\n");
    return 0;
}