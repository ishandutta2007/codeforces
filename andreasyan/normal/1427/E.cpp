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
const ll INF = 1000000009000000009;

vector<pair<ll, pair<bool, pair<ll, ll> > > > ans;

void rec(ll x)
{
    vector<ll> v;
    v.push_back(x);
    unordered_set<ll> s;
    s.insert(x);

    set<pair<ll, pair<bool, pair<ll, ll> > > > t;
    t.insert(m_p(x + x, m_p(false, m_p(x, x))));

    int q = 0;
    while (1)
    {
        ++q;
        pair<ll, pair<bool, pair<ll, ll> > > u = *t.begin();

        ans.push_back(u);

        ll minu = u.fi;
        t.erase(t.begin());
        s.insert(minu);

        for (int i = 0; i < sz(v); ++i)
        {
            if (s.find((minu + v[i])) == s.end())
                t.insert(m_p((minu + v[i]), m_p(false, m_p(minu, v[i]))));
            if (s.find((minu ^ v[i])) == s.end())
                t.insert(m_p((minu ^ v[i]), m_p(true, m_p(minu, v[i]))));
        }
        if (s.find(minu + minu) == s.end())
            t.insert(m_p(minu + minu, m_p(false, m_p(minu, minu))));

        v.push_back(minu);

        if (minu == 1)
        {
            //cout << "OK\n";
            //cout << sz(v) << "\n";
            cout << sz(ans) << "\n";
            for (int i = 0; i < sz(ans); ++i)
            {
                if (ans[i].se.fi == false)
                    cout << ans[i].se.se.fi << " + " << ans[i].se.se.se << "\n";
                else
                    cout << ans[i].se.se.fi << " ^ " << ans[i].se.se.se << "\n";
            }
            return;
        }

        if (q >= 100)
        {
            vector<ll> vv;
            for (int i = 0; i < sz(v); ++i)
            {
                if (v[i] % 2 == 1 && v[i] != x)
                    vv.push_back(v[i]);
            }
            if (sz(vv) >= 1)
            {
                ll minu = vv[(rnf() % sz(vv))];
                //cout << minu << endl;
                rec(minu);
                return;
            }
        }
    }
}

void solv()
{
    ll x;
    cin >> x;

    rec(x);
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