#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const ll MxN = 5009;
pair<ll, ll> dp[2][MxN + 9];

struct S {
    ll t = 0, x = 0;

    bool operator<(const S &other) const {
        return t < other.t;
    }

    bool canReach(const S &other) const {
        assert(t < other.t);
        return llabs(t - other.t) >= llabs(x - other.x);
    }
};

bool contains(const pair<ll, ll> p, ll x) {
    return p.first <= x && x <= p.second;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int n;
    cin >> n;
    vector<S> a(n + 1);
    a[0].t = a[0].x = 0;
    for (ll i = 1; i <= n; ++i)
        cin >> a[i].t >> a[i].x;

    assert(is_sorted(a.begin(), a.end()));

    const ll Inf = (ll) 1e17;

    for (int i = n; i >= 0; --i) {
        for (int j = i; j <= n; ++j) {
            pair<ll, ll> &res = dp[i&1][j] = {Inf, -Inf};


            // ! base case

            if (j >= i + 2) {
                const pair<ll, ll> &p = dp[~i&1][j];
                if (!contains(p, a[i + 1].x))
                    continue;
                const ll dt = a[i + 1].t - a[i].t;
                res = {a[i + 1].x - dt, a[i + 1].x + dt};
                continue;
            }

            if (j == i + 1) {
                pair<ll, ll> &p = dp[~i&1][j];
                if (p.first > p.second)
                    continue;
                const ll dt = a[i + 1].t - a[i].t;
                res = pair<ll, ll>{p.first - dt, p.second + dt};
                continue;
            }

            if (i == n) {
                res = {-Inf, Inf};
                continue;
            }

            for (int k = i + 1; k <= n; ++k) {
                ll dt;
                if(k == i + 1) {
                    if(dp[~i&1][k].first > dp[~i&1][k].second)
                        continue;
                    dt = contains(dp[~i&1][k], a[i + 1].x) ? 0 : min(llabs(a[i + 1].x - dp[~i&1][k].first),
                                                                               llabs(a[i + 1].x - dp[~i&1][k].second));
                } else {
                    if (!contains(dp[~i&1][k], a[i + 1].x))
                        continue;
                    dt = llabs(a[i+1].x - a[k].x);
                }
                const ll ddt = a[i + 1].t - a[i].t - dt;
                if (ddt < 0)
                    continue;
                const pair<ll, ll> res_upd = {a[k].x - ddt, a[k].x + ddt};
                res.first = min(res.first, res_upd.first);
                res.second = max(res.second, res_upd.second);
            }
        }
    }

    cout << (contains(dp[0][0], 0) ? "YES" : "NO");

    return 0;
}