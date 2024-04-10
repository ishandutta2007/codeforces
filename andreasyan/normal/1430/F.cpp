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
const int N = 2003;
const ll INF = 1000000009000000009;

int n, k;
int l[N], r[N], a[N];

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> l[i] >> r[i] >> a[i];

    /*vector<pair<pair<int, int>, ll> > v;
    for (int i = 1; i <= n; ++i)
    {
        if (l[i] == r[i] && l[i - 1] == l[i])
        {
            v.back().se += a[i];
            if (v.back().se >= k)
            {
                cout << "-1\n";
                return;
            }
        }
        else
            v.push_back(m_p(m_p(l[i], r[i]), a[i]));
    }

    n = sz(v);
    for (int i = 1; i <= n; ++i)
    {
        l[i] = v[i - 1].fi.fi;
        r[i] = v[i - 1].fi.se;
        a[i] = v[i - 1].se;
    }*/

    map<int, int> dp;
    map<int, int> ndp;
    dp[0] = k;
    for (int i = 1; i <= n; ++i)
    {
        ndp.clear();
        for (auto it = dp.begin(); it != dp.end(); ++it)
        {
            int x = a[i];
            if (x > it->se)
            {
                x -= it->se;
                if (x / k + !!(x % k) <= r[i] - l[i])
                    ndp[it->fi + x / k + !!(x % k)] = max(ndp[it->fi + x / k + !!(x % k)], (k - (x % k)) % k);
                if (i < n)
                {
                    if (x / k + !!(x % k) + 1 <= r[i] - l[i] || (x / k + !!(x % k) == r[i] - l[i] && r[i] < l[i + 1]))
                        ndp[it->fi + x / k + !!(x % k) + 1] = max(ndp[it->fi + x / k + !!(x % k) + 1], k);
                }
            }
            else
            {
                ndp[it->fi] = max(ndp[it->fi], it->se - x);
                if (i < n)
                {
                    if (l[i] < l[i + 1])
                        ndp[it->fi + 1] = max(ndp[it->fi + 1], k);
                }
            }
        }
        dp = ndp;
    }

    ll ans = INF;
    for (auto it = dp.begin(); it != dp.end(); ++it)
        ans = min(ans, it->fi * 1LL * k + (k - it->se));

    if (ans == INF)
        cout << "-1\n";
    else
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
    //scanf("%d", &tt);
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}