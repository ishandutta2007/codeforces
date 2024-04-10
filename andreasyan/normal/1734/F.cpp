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

map<pair<pair<ll, ll>, bool>, ll> mp;
ll rec(ll l, ll r, bool z)
{
    if (l == 0)
    {
        if (z)
            return r + 1;
        return 0;
    }

    if (mp.find(m_p(m_p(l, r), z)) != mp.end())
        return mp[m_p(m_p(l, r), z)];

    //if (l == r || (rnd() % 2))
    {
        for (ll i = 0; ; ++i)
        {
            if (r < (1LL << i))
            {
                ll m = (1LL << (i - 1));
                if (l >= m)
                    return mp[m_p(m_p(l, r), z)] = rec(l - m, r - m, (z ^ true));
                return mp[m_p(m_p(l, r), z)] = rec(l, m - 1, z) + rec(m - l, r - l, (z ^ true));
            }
        }
    }
    //else
    {
        for (ll i = 0; ; ++i)
        {
            if (r - l < (1LL << i))
            {
                ll m = (1LL << (i - 1));
                return rec(l, l + m - 1, z) + rec(l + m, r, (z ^ true));
            }
        }
    }
}

void solv()
{
    ll n, m;
    cin >> n >> m;
    cout << rec(n, n + m - 1, false) << "\n";
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