#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;

void solve() {
    int n, d, m;
    cin >> n >> d >> m;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    vector<int> bad, good;
    for (auto &c : a) {
        if (c > m) bad.pb(c);
        else good.pb(c);
    }
    sort(all(good));
    reverse(all(good));
    sort(all(bad));
    reverse(all(bad));
    vector<ll> pr((int)good.size() + 1);
    for (int i = 1; i <= (int)good.size(); i++) pr[i] = pr[i - 1] + good[i - 1];
    ll ans = pr.back();
    ll now = 0;
    for (int cntb = 1; cntb <= (int)bad.size(); cntb++) {
        now += bad[cntb - 1];
        ll cntg = n - 1 - (ll)(cntb - 1) * (d + 1);
        if (cntg < 0) break;
        ans = max(ans, now + pr[min((ll)pr.size() - 1, cntg)]);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}