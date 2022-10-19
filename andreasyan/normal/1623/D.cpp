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
const int M = 1000000007;

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int n, m, bx, by, kx, ky, p;

void solv()
{
    cin >> n >> m >> bx >> by >> kx >> ky >> p;
    p = (p * 1LL * ast(100, M - 2)) % M;

    int x = bx, y = by;
    int dx = 1, dy = 1;
    set<pair<pair<int, int>, pair<int, int> > > c;
    vector<pair<pair<int, int>, pair<int, int> > > v;
    vector<int> sv, cv;
    while (1)
    {
        if (c.find(m_p(m_p(x, y), m_p(dx, dy))) != c.end())
        {
            for (int i = 0; i < sz(v); ++i)
            {
                if (v[i] == m_p(m_p(x, y), m_p(dx, dy)))
                {
                    for (int j = 0; j < i; ++j)
                    {
                        if (v[j].fi.fi == kx || v[j].fi.se == ky)
                            sv.push_back(1);
                        else
                            sv.push_back(0);
                    }
                    for (int j = i; j < sz(v); ++j)
                    {
                        if (v[j].fi.fi == kx || v[j].fi.se == ky)
                            cv.push_back(1);
                        else
                            cv.push_back(0);
                    }
                    break;
                }
            }
            break;
        }
        c.insert(m_p(m_p(x, y), m_p(dx, dy)));
        v.push_back(m_p(m_p(x, y), m_p(dx, dy)));
        if (!(1 <= x + dx && x + dx <= n))
            dx *= -1;
        if (!(1 <= y + dy && y + dy <= m))
            dy *= -1;
        x += dx;
        y += dy;
    }

    int ans = 0;
    int pp = 1;
    for (int i = 0; i < sz(sv); ++i)
    {
        if (sv[i])
        {
            int spp = pp;
            pp = (pp * 1LL * p) % M;
            ans = (ans + sv[i] * i * 1LL * pp) % M;
            pp = (spp * 1LL * (1 - p + M)) % M;
        }
    }
    int spp = pp;

    int yans = 0;
    pp = 1;
    for (int i = 0; i < sz(cv); ++i)
    {
        if (cv[i])
        {
            int spp = pp;
            pp = (pp * 1LL * p) % M;
            yans = (yans + cv[i] * (sz(sv) + i) * 1LL * pp) % M;
            pp = (spp * 1LL * (1 - p + M)) % M;
        }
    }

    int t = (yans + pp * 1LL * sz(cv)) % M;
    t = (t * 1LL * ast((1 - pp + M) % M, M - 2)) % M;

    ans = (ans + t * 1LL * spp) % M;

    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}