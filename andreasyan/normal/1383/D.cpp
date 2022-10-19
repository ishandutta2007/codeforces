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
const int N = 255;
const int xx[4] = {0, 1, 0, -1};
const int yy[4] = {1, 0, -1, 0};

int n, m;
int a[N][N];

set<int> s, t;

int ans[N][N];
int q[N][N];

queue<pair<int, int> > v;

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    }

    for (int i = 1; i <= n; ++i)
    {
        int maxu = 0;
        for (int j = 1; j <= m; ++j)
            maxu = max(maxu, a[i][j]);
        t.insert(maxu);
    }
    for (int j = 1; j <= m; ++j)
    {
        int maxu = 0;
        for (int i = 1; i <= n; ++i)
            maxu = max(maxu, a[i][j]);
        s.insert(maxu);
    }

    int x = n + 1;
    int y = m + 1;
    for (int u = n * m; u >= 1; --u)
    {
        pair<int, int> uu;
        if (t.find(u) != t.end() && s.find(u) != s.end())
        {
            --x;
            --y;
            uu = m_p(x, y);
        }
        else if (t.find(u) != t.end())
        {
            --x;
            uu = m_p(x, y);
        }
        else if (s.find(u) != s.end())
        {
            --y;
            uu = m_p(x, y);
        }
        else
        {
            uu = v.front();
            v.pop();
        }

        ans[uu.fi][uu.se] = u;
        for (int k = 0; k < 4; ++k)
        {
            int hx = uu.fi + xx[k];
            int hy = uu.se + yy[k];
            ++q[hx][hy];
            if (!ans[hx][hy] && q[hx][hy] == 2)
                v.push(m_p(hx, hy));
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            cout << ans[i][j] << ' ';
        cout << "\n";
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
        solv();
    return 0;
}