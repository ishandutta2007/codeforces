#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;


const int MAXN = 100007;
const int MAXM = 100007 << 1;
const int INF = (int)2e+9;


int n, m, l;
int last[MAXN];
int next[MAXM], dest[MAXM], dist[MAXM];
int f[MAXN];
int s;
priority_queue < pair <int, int> > h;


int add(int x, int d)
{
    if (f[x] <= d) return 0;
    f[x] = d;
    h.push(make_pair(-d, x));
    return 0;
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= m; i++)
    {
        int x, y, d;
        scanf("%d %d %d", &x, &y, &d);

        dest[i] = y;
        dist[i] = d;
        next[i] = last[x];
        last[x] = i;

        dest[i + m] = x;
        dist[i + m] = d;
        next[i + m] = last[y];
        last[y] = i + m;
    }
    scanf("%d", &l);

    for (int i = 1; i <= n; i++)
        f[i] = INF;

    add(s, 0);
    while (h.size())
    {
        int
            x = h.top().second,
            d = -h.top().first;
        h.pop();
        if (f[x] != d) continue;

        for (int i = last[x]; i; i = next[i])
            add(dest[i], d + dist[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (f[i] == l)
            ans++;

    for (int i = 1; i <= n; i++)
    {
        if (f[i] >= l) continue;

        for (int j = last[i]; j; j = next[j])
        {
            int x = dist[j] - (l - f[i]);
            if (x <= 0) continue;

            x += f[dest[j]];
            if (x < l || x == l && i > dest[j]) continue;
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}