#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;


const int MAXN = 5005;
const int MAXM = MAXN + MAXN;

pair <int, int> a[MAXN];
vector < pair < int, int > > g[MAXN];
int n, m;

int last[MAXN];
int next[MAXM], dest[MAXM], cnt[MAXM];
int ans[MAXN];


int dfs(int x, int p, int c)
{
    for (int i = last[x]; i; i = next[i])
        if (dest[i] != p)
            dfs(dest[i], x, cnt[i]);

    if (p)
    {
        int a[MAXN];
        int k = 0;

        sort(g[x].begin(), g[x].end());
        reverse(g[x].begin(), g[x].end());

        for (int i = 0; g[x].size() || k; i++)
        {
            while (g[x].back().first == i)
            {
                a[k++] = g[x].back().second;
                g[x].pop_back();
            }

            int l = min(c, k);
            partial_sort(a, a + l, a + k);

            for (int j = 0; j < l; j++)
                g[p].push_back(make_pair(i + 1, a[j]));

            memmove(a, a + l, (k - l + 1) * sizeof(a[0]));
            k -= l;
        }
    }
    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a, a + n);

    for (int i = 0; i < n; i++)
        g[a[i].second + 1].push_back(make_pair(0, i));

    for (int i = 1; i < n; i++)
    {
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);


        dest[i] = y;
        cnt[i] = c;
        next[i] = last[x];
        last[x] = i;

        dest[i + n] = x;
        cnt[i + n] = c;
        next[i + n] = last[y];
        last[y] = i + n;
    }

    dfs(1, 0, 0);


    for (int i = 0; i < (int)g[1].size(); i++)
        ans[ a[ g[1][i].second ].second ] = g[1][i].first;

    for (int i = 0; i < n; i++)
    {
        if (i) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}