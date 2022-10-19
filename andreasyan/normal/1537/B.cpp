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

int n, m, x, y;

ll dist(pair<int, int> a, pair<int, int> b)
{
    return abs(a.fi - b.fi) + abs(a.se - b.se);
}

void solv()
{
    cin >> n >> m >> x >> y;
    vector<pair<int, int> > v;
    v.push_back(m_p(1, 1));
    v.push_back(m_p(1, m));
    v.push_back(m_p(n, m));
    v.push_back(m_p(n, 1));
    ll ans = 0;
    for (int i = 0; i < sz(v); ++i)
    {
        for (int j = 0; j < sz(v); ++j)
        {
            ans = max(ans, dist(m_p(x, y), v[i]) +
                            dist(m_p(x, y), v[j]) +
                            dist(v[i], v[j]));
        }
    }

    //cout << ans << "\n";

    for (int i = 0; i < sz(v); ++i)
    {
        for (int j = 0; j < sz(v); ++j)
        {
            if (ans == dist(m_p(x, y), v[i]) +
                            dist(m_p(x, y), v[j]) +
                            dist(v[i], v[j]))
                            {
                                cout << v[i].fi << ' ' << v[i].se << ' ' << v[j].fi << ' ' << v[j].se << "\n";
                                return;
                            }
        }
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}