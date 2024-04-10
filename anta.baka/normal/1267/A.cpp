#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define any kek
bool any(ll l, ll r, multiset<ll>& xs) {
    auto it = xs.upper_bound(l);
    if (it != xs.end() && *it < r) {
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    multiset<pair<ll, int>> evs;
    multiset<ll> ops;
    vector<ll> from(n), to(n), len(n);
    for (int i = 0; i < n; i++) {
        ll a, b, t;
        cin >> a >> b >> t;
        ops.insert(a + t);
        from[i] = a;
        to[i] = b;
        len[i] = t;
        evs.insert({ a, +i + 1 });
        evs.insert({ b, -i - 1 });
    }
    multiset<pair<ll, ll>> lens;
    ll t = 0;
    ll ans = 0;
    for (auto ev : evs) {
        if (t < ev.first) {
            if (!lens.empty()) {
                ll cnt = (ev.first - t) / lens.begin()->first;
                ans += cnt;
                t += lens.begin()->first * cnt;
            } else {
                t = ev.first;
            }
        }
        while (!lens.empty() && lens.begin()->second < t) {
            lens.erase(lens.begin());
        }
        if (ev.second > 0) {
            if (t < ev.first) {
                if (!lens.empty() && !any(t, t + lens.begin()->first, ops)) {
                    ans++;
                    t += lens.begin()->first;
                } else {
                    t = ev.first;
                }
            }
            lens.insert({ len[ev.second - 1], to[ev.second - 1] - len[ev.second - 1] });
            ops.erase(ops.find(ev.first + len[ev.second - 1]));
        } else {
            auto it = lens.find({ len[-ev.second - 1], to[-ev.second - 1] - len[-ev.second - 1] });
            if (it != lens.end()) {
                lens.erase(it);
            }
        }
    }
    cout << ans << endl;
}