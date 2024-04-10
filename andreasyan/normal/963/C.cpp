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
const ll INF = 1000000009003;

ll gcd(ll x, ll y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n;
map<ll, vector<pair<ll, ll> > > v;

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        ll w, h, c;
        cin >> w >> h >> c;
        //swap(w, h);
        v[w].push_back(m_p(h, c));
    }

    bool z = true;
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        sort(all(it->se));
        if (sz(it->se) != sz(v.begin()->se))
        {
            z = false;
            break;
        }
        for (int i = 0; i < it->se.size(); ++i)
        {
            if (it->se[i].fi != v.begin()->se[i].fi)
            {
                z = false;
                break;
            }
        }
        if (!z)
            break;

        for (int i = 0; i < it->se.size(); ++i)
        {
            if (it->se[0].se * (long double)v.begin()->se[i].se != it->se[i].se * (long double)v.begin()->se[0].se)
            {
                z = false;
                break;
            }
        }
        if (!z)
            break;
    }

    if (!z)
    {
        cout << "0\n";
        return;
    }

    ll ans = 0;
    for (int i = 0; i < v.begin()->se.size(); ++i)
        ans = gcd(ans, v.begin()->se[i].se);
    ll cans = ans;

    vector<pair<ll, int> > p;
    for (ll i = 2; i * i <= ans; ++i)
    {
        if (ans % i == 0)
        {
            p.push_back(m_p(i, 0));
            while (ans % i == 0)
            {
                ans /= i;
                p.back().se++;
            }
        }
    }
    if (ans > 1)
        p.push_back(m_p(ans, 1));
    ans = cans;

    vector<int> pp;
    pp.assign(sz(p), 0);
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (it == v.begin())
            continue;
        for (int i = 0; i < it->se.size(); ++i)
        {
            for (int j = 0; j < p.size(); ++j)
            {
                int qb = 0;
                ll u = v.begin()->se[i].se;
                while (u % p[j].fi == 0)
                {
                    u /= p[j].fi;
                    ++qb;
                }

                int qi = 0;
                u = it->se[i].se;
                while (u % p[j].fi == 0)
                {
                    u /= p[j].fi;
                    ++qi;
                }

                pp[j] = max(pp[j], qb - qi);
            }
        }
    }

    ll yans = 1;
    for (int j = 0; j < p.size(); ++j)
    {
        yans *= max(0, p[j].se - pp[j] + 1);
    }
    cout << yans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}