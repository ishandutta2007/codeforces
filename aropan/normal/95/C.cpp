#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 1111;
const int MAXM = 2222;

const long long INF = (long long)1e+18;

int n, m, st, fn;
int last[MAXN];
int next[MAXM], dest[MAXM], dist[MAXM];
int c[MAXN], t[MAXN];

int a[MAXN][MAXN];
long long d[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    scanf("%d  %d", &st, &fn);
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);


        dest[i] = y;
        dist[i] = z;
        next[i] = last[x];
        last[x] = i;

        dest[i + m] = x;
        dist[i + m] = z;
        next[i + m] = last[y];
        last[y] = i + m;
    }

    for (int i = 1; i <= n; i++)
        scanf("%d %d", &t[i], &c[i]);


    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            d[j] = INF;
        d[i] = 0;

        priority_queue < pair <long long, int>, vector < pair <long long, int> >, greater < pair <long long, int> > > h;
        h.push(make_pair(0LL, i));

        while (h.size())
        {
            int x = h.top().second;
            long long l = h.top().first;
            h.pop();
            if (l > t[i]) break;
            if (l > d[x]) continue;

            for (int j = last[x]; j; j = next[j])
            {
                if (l + dist[j] < d[dest[j]])
                {
                    d[dest[j]] = l + dist[j];
                    h.push(make_pair(d[dest[j]], dest[j]));
                }
            }
        }

        for (int j = 1; j <= n; j++)
            a[i][j] = t[i] >= d[j];
    }
    
    priority_queue < pair <long long, int>, vector < pair <long long, int> >, greater < pair <long long, int> > > h;
    
    for (int i = 1; i <= n; i++)
        d[i] = INF;
    d[st] = 0;
    h.push(make_pair(0LL, st));

    while (h.size())
    {
        int x = h.top().second;
        long long l = h.top().first;
        h.pop();
        if (l > d[x]) continue;
        for (int i = 1; i <= n; i++)
            if (a[x][i] && l + c[x] < d[i])
            {
                d[i] = l + c[x];
                h.push(make_pair(d[i], i));
            }
    }

    printf("%I64d\n", d[fn] == INF? -1 : d[fn]);
    return 0;
}