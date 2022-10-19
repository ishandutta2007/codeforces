#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;

int n, m;
vector<int> g[N], rg[N];

int d[N];
bool c[N];
void bfs()
{
    for (int x = 1; x <= n; ++x)
    {
        c[x] = false;
        d[x] = 0;
    }

    queue<int> q;

    c[1] = true;
    d[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (!c[h])
            {
                c[h] = true;
                d[h] = d[x] + 1;
                q.push(h);
            }
        }
    }
}

int ans[N];

void solv()
{
    scanf("%d%d", &n, &m);

    for (int x = 1; x <= n; ++x)
    {
        g[x].clear();
        rg[x].clear();
    }

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        rg[y].push_back(x);
    }

    bfs();
    vector<pair<int, int> > v;
    for (int x = 1; x <= n; ++x)
        v.push_back(m_p(d[x], x));
    sort(all(v));
    reverse(all(v));

    for (int i = 0; i < n; ++i)
    {
        int x = v[i].second;
        ans[x] = d[x];
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (d[h] > d[x])
                ans[x] = min(ans[x], ans[h]);
            else
                ans[x] = min(ans[x], d[h]);
        }
    }

    for (int x = 1; x <= n; ++x)
        printf("%d ", ans[x]);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}