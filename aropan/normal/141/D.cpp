#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;


const int MAXN = 3 * 100007;
const int MAXM = MAXN * 3;

const int INF = (int)2e+9;

int X[MAXN];
int x[MAXN], d[MAXN], t[MAXN], p[MAXN];
int n, m, k;
int L;

int f[MAXN];
int last[MAXN];
int next[MAXM], dest[MAXM], dist[MAXM], print[MAXM];

int prev[MAXN], g[MAXN];

priority_queue < pair <int, int> > h;


int addedge(int x, int y, int d, int p = 0)
{
    k++;
    dest[k] = y;
    dist[k] = d;
    next[k] = last[x];
    print[k] = p;
    last[x] = k;
}


int add(int x, int d, int p = -1, int e = 0)
{
    if (f[x] <= d) return 0;
    f[x] = d;
    prev[x] = p;
    g[x] = e;
    h.push(make_pair(-d, x));
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    scanf("%d %d", &n, &L);


    X[m++] = 0;
    X[m++] = L;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &x[i], &d[i], &t[i], &p[i]);
        if (x[i] - p[i] < 0) continue;
        if (x[i] + d[i] > L) continue;

        X[m++] = x[i] - p[i];
        X[m++] = x[i] + d[i];
    }

    sort(X, X + m);
    m = unique(X, X + m) - X;

    for (int i = 1; i < m; i++)
    {
        addedge(i, i + 1, X[i] - X[i - 1]);
        addedge(i + 1, i, X[i] - X[i - 1]);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &x[i], &d[i], &t[i], &p[i]);
        if (x[i] - p[i] < 0) continue;
        if (x[i] + d[i] > L) continue;

        int st = lower_bound(X, X + m, x[i] - p[i]) - X + 1;
        int fn = lower_bound(X, X + m, x[i] + d[i]) - X + 1;

        addedge(st, fn, p[i] + t[i], i + 1);
    }


    for (int i = 1; i <= m; i++)
        f[i] = INF;

    add(1, 0);

    while (h.size())
    {
        int
            d = -h.top().first,
            x = h.top().second;
        h.pop();

        if (f[x] < d) continue;


        for (int i = last[x]; i; i = next[i])
            add(dest[i], d + dist[i], x, print[i]);
    }
    printf("%d\n", f[m]);

    vector <int> ans;
    int x = m;
    while (x != -1)
    {
        if (g[x]) ans.push_back(g[x]);
        x = prev[x];
    }

    reverse(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
        printf("%d\n", ans[i]);
    return 0;
}