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
const int N = 200005, INF = 1000000009;

int n;
int a[N];

pair<ll, ll> b[N];

int q;
vector<pair<int, int> > h;

ll yans[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int xx;
    cin >> xx;
    for (int i = 2; i <= n; ++i)
    {
        cin >> xx;
        a[i] -= xx;
    }

    b[1] = m_p(0, 1);
    for (int i = 2; i <= n; ++i)
        b[i] = m_p(a[i], 0);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + i; j <= n; j += i)
        {
            b[j].fi -= b[i].fi;
            b[j].se -= b[i].se;
        }
    }

    ll x = -INF;
    ll ans = 0;
    vector<ll> v;
    for (int i = 1; i <= n; ++i)
    {
        ans += abs(b[i].fi + b[i].se * x);
        if (b[i].se == -1)
        {
            v.push_back(b[i].fi);
        }
        else if (b[i].se == 1)
        {
            v.push_back(-b[i].fi);
        }
    }
    sort(all(v));

    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        cin >> xx;
        xx = a[1] - xx;
        h.push_back(m_p(xx, i));
    }
    sort(all(h));

    int j = 0;
    ll pans = -sz(v);
    for (int i = 0; i < q; ++i)
    {
        while (j < sz(v) && v[j] <= h[i].fi)
        {
            ans += pans * (v[j] - x);
            x = v[j];
            pans += 2;
            ++j;
        }
        ans += pans * (h[i].fi - x);
        x = h[i].fi;

        yans[h[i].se] = ans;
    }

    for (int i = 1; i <= q; ++i)
        cout << yans[i] << "\n";
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