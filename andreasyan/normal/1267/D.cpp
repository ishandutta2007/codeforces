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
const int N = 303;

int n;
int a[N];
int t[N];

bool c[8][8];
vector<int> v[8][8];

int u[8];

vector<pair<int, int> > ans;
int on[N];

bool so(const pair<int, int>& a, const pair<int, int>& b)
{
    return (a.fi & a.se) > (b.fi & b.se);
}
void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            int x;
            cin >> x;
            a[i] += (1 << j) * x;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            int x;
            cin >> x;
            t[i] += (1 << j) * x;
        }
    }

    for (int i = 1; i <= n; ++i)
        v[a[i]][t[i]].push_back(i);

    for (int x = 0; x < 8; ++x)
    {
        for (int y = 0; y < 8; ++y)
        {
            if (v[x][y].empty())
                continue;
            if (x == 0)
            {
                c[x][y] = true;
                continue;
            }
            for (int i = 0; i < sz(v[x][y]) - 1; ++i)
            {
                ans.push_back(m_p(v[x][y][i], v[x][y][i + 1]));
            }
            on[v[x][y].back()] = 1;
        }
    }

    vector<pair<int, int> > h;
    for (int x = 0; x < 8; ++x)
    {
        for (int y = 0; y < 8; ++y)
        {
            h.push_back(m_p(x, y));
        }
    }
    sort(all(h), so);

    c[7][7] = true;
    u[7] = v[7][7].back();
    while (1)
    {
        bool z = false;

        //111111111111111111111111111111111111111
        for (int i = 0; i < sz(h); ++i)
        {
            int x = h[i].fi;
            int y = h[i].se;
            {
                if (v[x][y].empty())
                    continue;
                if (c[x][y])
                    continue;

                for (int xx = 0; xx < 8; ++xx)
                {
                    if (u[xx] && xx == x)
                    {
                        ans.push_back(m_p(u[xx], v[x][y][0]));
                        c[x][y] = true;
                        u[(x & y)] = v[x][y].back();
                        z = true;
                        break;
                    }
                }
                if (z)
                    break;
            }
            if (z)
                break;
        }
        if (z)
            continue;

        //222222222222222222222222222222222222222222222222
        for (int i = 0; i < sz(h); ++i)
        {
            int x = h[i].fi;
            int y = h[i].se;
            {
                if (v[x][y].empty())
                    continue;
                if (c[x][y])
                    continue;

                for (int xx = 0; xx < 8; ++xx)
                {
                    for (int yy = xx + 1; yy < 8; ++yy)
                    {
                        if (u[xx] && u[yy] && (xx | yy) == x)
                        {
                            ans.push_back(m_p(u[xx], v[x][y][0]));
                            ans.push_back(m_p(u[yy], v[x][y][0]));
                            c[x][y] = true;
                            u[(x & y)] = v[x][y].back();
                            z = true;
                            break;
                        }
                    }
                    if (z)
                        break;
                }
                if (z)
                    break;
            }
            if (z)
                break;
        }
        if (z)
            continue;

        //333333333333333333333333333333333333333333333333333
        for (int i = 0; i < sz(h); ++i)
        {
            int x = h[i].fi;
            int y = h[i].se;
            {
                if (v[x][y].empty())
                    continue;
                if (c[x][y])
                    continue;

                for (int xx = 0; xx < 8; ++xx)
                {
                    for (int yy = xx + 1; yy < 8; ++yy)
                    {
                        for (int zz = yy + 1; zz < 8; ++zz)
                        {
                            if (u[xx] && u[yy] && u[zz] && (xx | yy | zz) == x)
                            {
                                ans.push_back(m_p(u[xx], v[x][y][0]));
                                ans.push_back(m_p(u[yy], v[x][y][0]));
                                ans.push_back(m_p(u[zz], v[x][y][0]));
                                c[x][y] = true;
                                u[(x & y)] = v[x][y].back();
                                z = true;
                                break;
                            }
                        }
                        if (z)
                            break;
                    }
                    if (z)
                        break;
                }
                if (z)
                    break;
            }
            if (z)
                break;
        }

        if (!z)
            break;
    }

    for (int x = 0; x < 8; ++x)
    {
        for (int y = 0; y < 8; ++y)
        {
            if (!v[x][y].empty())
            {
                if (!c[x][y])
                {
                    cout << "Impossible\n";
                    return;
                }
            }
        }
    }

    assert(sz(ans) <= 264);
    cout << "Possible\n";
    for (int i = 1; i <= n; ++i)
        cout << on[i] << ' ';
    cout << "\n";
    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i)
        cout << ans[i].fi << ' ' << ans[i].se << "\n";
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