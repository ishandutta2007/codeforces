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

int n, m;
int a[N];

vector<pair<int, int> > b;

bool so(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.se < b.se)
        return true;
    if (a.se > b.se)
        return false;
    return a.fi > b.fi;
}

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);

    b.clear();

    {
        set<pair<int, int> > ss;
        for (int i = 0; i < m; ++i)
        {
            int l, r;
            cin >> l >> r;
            int j = lower_bound(a + 1, a + n + 1, l) - a;
            if (1 <= j && j <= n && l <= a[j] && a[j] <= r)
                continue;
            if (ss.find(m_p(l, r)) != ss.end())
                continue;
            ss.insert(m_p(l, r));
            b.push_back(m_p(l, r));
        }
        sort(all(b), so);

        vector<pair<int, int> > bb;
        int maxu = -INF;
        for (int i = 0; i < b.size(); ++i)
        {
            if (b[i].fi > maxu)
            {
                bb.push_back(b[i]);
                maxu = b[i].fi;
            }
        }
        b = bb;
    }

    a[n + 1] = INF;

    vector<pair<int, int> > l;
    vector<pair<int, int> > r;
    int j = 0;
    while (j < sz(b) && b[j].se < a[1])
    {
        r.push_back(b[j++]);
    }

    vector<ll> dp0;
    dp0.push_back(0);
    for (int i = 0; i < r.size(); ++i)
        dp0.push_back(INF * 1LL * INF);

    for (int i = 1; i <= n; ++i)
    {
        swap(l, r);
        r.clear();
        while (j < sz(b) && b[j].se < a[i + 1])
        {
            r.push_back(b[j++]);
        }

        ll min1 = INF * 1LL * INF;
        for (int i = 0; i < sz(l); ++i)
        {
            ll t = -l[i].se + dp0[i];
            min1 = min(min1, t);
        }

        ll min2 = INF * 1LL * INF;
        for (int i = 0; i < sz(l); ++i)
        {
            ll t = -l[i].se - l[i].se + dp0[i];
            min2 = min(min2, t);
        }

        vector<ll> dp1;
        for (int j = 0; j <= r.size(); ++j)
        {
            if (j == 0)
            {
                dp1.push_back(dp0.back());
                for (int k = 0; k < sz(l); ++k)
                {
                    dp1.back() = min(dp1.back(), a[i] - l[k].se + dp0[k]);
                }
            }
            else
            {
                dp1.push_back(dp0.back() + r[j - 1].fi - a[i]);
                dp1.back() = min(dp1.back(), r[j - 1].fi + r[j - 1].fi - a[i] + min1);
                dp1.back() = min(dp1.back(), r[j - 1].fi + a[i] + min2);
            }
        }

        dp0 = dp1;

        /*for (int i = 0; i < sz(dp0); ++i)
            cout << dp0[i] << ' ';
        cout << "\n";*/
    }

    cout << dp0.back() << "\n";
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
        solv();
    return 0;
}