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
const int N = 1003, K = 44;
const int xx[4] = {0, 1, 0, -1};
const int yy[4] = {1, 0, -1, 0};

int n, m, k;
int a[N][N];

vector<pair<int, int> > v[K];

int d[K][N][N];
bool c[N][N];
bool cc[K];
queue<pair<int, int> > q;

void bfs(int d[][N])
{
    while (!q.empty())
    {
        pair<int, int> t = q.front();
        q.pop();
        if (!cc[a[t.fi][t.se]])
        {
            cc[a[t.fi][t.se]] = true;
            for (int i = 0; i < v[a[t.fi][t.se]].size(); ++i)
            {
                pair<int, int> h = v[a[t.fi][t.se]][i];
                {
                    if (!c[h.fi][h.se])
                    {
                        c[h.fi][h.se] = true;
                        d[h.fi][h.se] = d[t.fi][t.se] + 1;
                        q.push(h);
                    }
                }
            }
        }
        for (int i = 0; i < 4; ++i)
        {
            pair<int, int> h = t;
            h.fi += xx[i];
            h.se += yy[i];
            if (1 <= h.fi && h.fi <= n && 1 <= h.se && h.se <= m)
            {
                if (!c[h.fi][h.se])
                {
                    c[h.fi][h.se] = true;
                    d[h.fi][h.se] = d[t.fi][t.se] + 1;
                    q.push(h);
                }
            }
        }
    }
}

void solv()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            v[a[i][j]].push_back(m_p(i, j));
        }
    }

    for (int u = 1; u <= k; ++u)
    {
        memset(c, false, sizeof c);
        memset(cc, false, sizeof cc);
        cc[u] = true;
        for (int i = 0; i < v[u].size(); ++i)
        {
            c[v[u][i].fi][v[u][i].se] = true;
            q.push(v[u][i]);
        }
        bfs(d[u]);
    }

    int qq;
    cin >> qq;
    while (qq--)
    {
        int x1, y1_, x2, y2;
        cin >> x1 >> y1_ >> x2 >> y2;
        int ans = abs(x1 - x2) + abs(y1_ - y2);
        for (int u = 1; u <= k; ++u)
            ans = min(ans, d[u][x1][y1_] + 1 + d[u][x2][y2]);
        cout << ans << "\n";
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}