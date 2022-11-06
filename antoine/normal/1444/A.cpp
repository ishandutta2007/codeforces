#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define DBG(v) cerr << #v << " = " << (v) << endl;

vector<pair<ll, int>> getFact(ll x) {
    assert(x > 0);
    vector<pair<ll, int>> v;
    for (ll i = 2; i * i <= x; ++i)
        if (x % i == 0) {
            v.emplace_back(i, 1);
            for (x /= i; x % i == 0; x /= i)
                v.back().second++;
        }
    if (x != 1)
        v.emplace_back(x, 1);

    return v;
}

ll f() {
    ll p, q;
    cin >> p >> q;
    if(p%q)
        return p;
    auto fact = getFact(q);
    ll ans = 0;
    for(auto e : getFact(q)) {
        assert(e.second > 0);
        ll x = p;
        while(x % e.first == 0)
            x /= e.first;
        for(int i = 0; i < e.second - 1; ++i)
            x *= e.first;
        ans = max(ans, x);
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int t;cin >> t;
    while(t--) {
        ll res=  f();
        cout << res << '\n';
    }

    return 0;
}