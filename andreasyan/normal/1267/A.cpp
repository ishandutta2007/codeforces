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

void solv()
{
    int n;
    vector<pair<ll, ll> > v;

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        ll l, r, t;
        cin >> l >> r >> t;
        l += t;

        v.push_back(m_p(l, t));
        v.push_back(m_p(r + 1, -t));
    }

    sort(all(v));

    vector<ll> l, r, t;

    multiset<ll> s;
    for (int i = 0; i < sz(v); ++i)
    {
        if (v[i].se > 0)
            s.insert(v[i].se);
        else
            s.erase(s.find(-v[i].se));

        if (!s.empty())
        {
            if (v[i].fi < v[i + 1].fi)
            {
                l.push_back(v[i].fi);
                r.push_back(v[i + 1].fi - 1);
                t.push_back(*s.begin());
            }
        }
    }

    vector<ll> p;
    p.push_back(r[0] - t[0] + 1);
    for (int i = 1; i < sz(t); ++i)
        p.push_back(max(p.back(), r[i] - t[i] + 1));

    ll ans = 0;
    ll x = r.back();
    for (int i = sz(t) - 1; i >= 0; --i)
    {
        if (x < l[i])
            continue;

        x = min(x, r[i]);

        ll q = (x - l[i] + 1) / t[i];

        ans += q;
        x -= q * t[i];

        if (x >= l[i])
        {
            if (i == 0 || p[i - 1] < x - t[i] + 1)
            {
                ++ans;
                x -= t[i];
            }
        }
    }

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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}