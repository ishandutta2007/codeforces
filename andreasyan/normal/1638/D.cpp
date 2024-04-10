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
const int N = 1003;

int n, m;
int a[N][N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];

    queue<pair<pair<int, int>, int> > q;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            bool z = true;
            for (int di = 0; di < 2; ++di)
            {
                for (int dj = 0; dj < 2; ++dj)
                {
                    if (a[i + di][j + dj] != a[i][j])
                        z = false;
                }
            }
            if (z)
                q.push(m_p(m_p(i, j), a[i][j]));
        }
    }

    vector<pair<pair<int, int>, int> > ans;
    while (!q.empty())
    {
        int x = q.front().fi.fi;
        int y = q.front().fi.se;
        int c = q.front().se;
        q.pop();

        if (a[x][y] == 0 && a[x + 1][y] == 0 && a[x][y + 1] == 0 && a[x + 1][y + 1] == 0)
            continue;

        ans.push_back(m_p(m_p(x, y), c));

        for (int dx = 0; dx < 2; ++dx)
        {
            for (int dy = 0; dy < 2; ++dy)
            {
                a[x + dx][y + dy] = 0;
            }
        }

        for (int hx = max(1, x - 1); hx <= min(n - 1, x + 2); ++hx)
        {
            for (int hy = max(1, y - 1); hy <= min(m - 1, y + 2); ++hy)
            {
                int z = 0;
                for (int dx = 0; dx < 2; ++dx)
                {
                    for (int dy = 0; dy < 2; ++dy)
                    {
                        if (a[hx + dx][hy + dy] == 0)
                            continue;
                        if (z == 0)
                        {
                            z = a[hx + dx][hy + dy];
                            continue;
                        }
                        if (a[hx + dx][hy + dy] != z)
                            z = -1;
                    }
                }

                if (z > 0)
                    q.push(m_p(m_p(hx, hy), z));
            }
        }
    }
    reverse(all(ans));

    bool z = true;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j])
                z = false;
        }
    }

    if (z)
    {
        cout << sz(ans) << "\n";
        for (int i = 0; i < sz(ans); ++i)
            cout << ans[i].fi.fi << ' ' << ans[i].fi.se << ' ' << ans[i].se << "\n";
    }
    else
        cout << "-1\n";
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