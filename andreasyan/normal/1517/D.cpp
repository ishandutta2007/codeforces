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
const int N = 503, K = 25, INF = 1000000009;
const int xx[4] = {0, 0, 1, -1};
const int yy[4] = {1, -1, 0, 0};

int n, m, k;
int d1[N][N];
int d2[N][N];
int dd[N][N][4];

vector<pair<int, int> > v[K];

int d[N][N];

int minu[N][N];

void solv()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < m; ++j)
            cin >> d1[i][j];
    }
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            cin >> d2[i][j];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            dd[i][j][0] = d1[i][j];
            dd[i][j][1] = d1[i][j - 1];
            dd[i][j][2] = d2[i][j];
            dd[i][j][3] = d2[i - 1][j];
        }
    }

    if (k % 2 == 1)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                cout << "-1 ";
            }
            cout << "\n";
        }
        return;
    }

    v[0].push_back(m_p(0, 0));
    for (int i = 1; i <= k + 2; ++i)
    {
        for (int j = 0; j < v[i - 1].size(); ++j)
        {
            int x = v[i - 1][j].fi;
            int y = v[i - 1][j].se;
            for (int u = 0; u < 4; ++u)
            {
                int hx = x + xx[u];
                int hy = y + yy[u];
                v[i].push_back(m_p(hx, hy));
            }
        }
        sort(all(v[i]));
        vector<pair<int, int> > vv;
        for (int j = 0; j < v[i].size(); ++j)
        {
            if (!j || v[i][j] != v[i][j - 1])
                vv.push_back(v[i][j]);
        }
        v[i] = vv;
    }

    k /= 2;
    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= m; ++y)
        {
            for (int j = 0; j < v[k + 1].size(); ++j)
            {
                int ux = x + v[k + 1][j].fi;
                int uy = y + v[k + 1][j].se;
                if (!(0 <= ux && ux <= n + 1 && 0 <= uy && uy <= m + 1))
                    continue;
                d[ux][uy] = INF;
            }
            for (int j = 0; j < v[k + 2].size(); ++j)
            {
                int ux = x + v[k + 2][j].fi;
                int uy = y + v[k + 2][j].se;
                if (!(0 <= ux && ux <= n + 1 && 0 <= uy && uy <= m + 1))
                    continue;
                d[ux][uy] = INF;
            }

            d[x][y] = 0;
            for (int i = 1; i <= k / 2 + k % 2; ++i)
            {
                for (int j = 0; j < v[i].size(); ++j)
                {
                    int ux = x + v[i][j].fi;
                    int uy = y + v[i][j].se;
                    if (!(1 <= ux && ux <= n && 1 <= uy && uy <= m))
                        continue;
                    d[ux][uy] = INF;
                    for (int t = 0; t < 4; ++t)
                    {
                        int hx = ux + xx[t];
                        int hy = uy + yy[t];
                        d[ux][uy] = min(d[ux][uy], d[hx][hy] + dd[ux][uy][t]);
                    }
                }
            }

            minu[x][y] = INF;
            for (int j = 0; j < v[k / 2 + k % 2].size(); ++j)
            {
                int ux = x + v[k / 2 + k % 2][j].fi;
                int uy = y + v[k / 2 + k % 2][j].se;
                if (!(1 <= ux && ux <= n && 1 <= uy && uy <= m))
                    continue;
                minu[x][y] = min(minu[x][y], d[ux][uy]);
            }
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= m; ++y)
        {
            for (int j = 0; j < v[k + 1].size(); ++j)
            {
                int ux = x + v[k + 1][j].fi;
                int uy = y + v[k + 1][j].se;
                if (!(0 <= ux && ux <= n + 1 && 0 <= uy && uy <= m + 1))
                    continue;
                d[ux][uy] = INF;
            }
            for (int j = 0; j < v[k + 2].size(); ++j)
            {
                int ux = x + v[k + 2][j].fi;
                int uy = y + v[k + 2][j].se;
                if (!(0 <= ux && ux <= n + 1 && 0 <= uy && uy <= m + 1))
                    continue;
                d[ux][uy] = INF;
            }

            d[x][y] = 0;
            for (int i = 1; i <= k / 2; ++i)
            {
                for (int j = 0; j < v[i].size(); ++j)
                {
                    int ux = x + v[i][j].fi;
                    int uy = y + v[i][j].se;
                    if (!(1 <= ux && ux <= n && 1 <= uy && uy <= m))
                        continue;
                    d[ux][uy] = INF;
                    for (int t = 0; t < 4; ++t)
                    {
                        int hx = ux + xx[t];
                        int hy = uy + yy[t];
                        d[ux][uy] = min(d[ux][uy], d[hx][hy] + dd[ux][uy][t]);
                    }
                }
            }

            int ans = INF;
            for (int j = 0; j < v[k / 2].size(); ++j)
            {
                int ux = x + v[k / 2][j].fi;
                int uy = y + v[k / 2][j].se;
                if (!(1 <= ux && ux <= n && 1 <= uy && uy <= m))
                    continue;
                ans = min(ans, (d[ux][uy] + minu[ux][uy]) * 2);
            }
            cout << ans << ' ';
        }
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
    {
        solv();
    }
    return 0;
}