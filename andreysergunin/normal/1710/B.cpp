#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
 
void solve();
 
int task;
 
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;  
 
    int tests = 1;
    cin >> tests;
 
    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }
 
#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}
 
// ----------------------------------------------------------------- 

void solve() {  
    int n;
    ll threshold;
    cin >> n >> threshold;
    vector<pll> s(n);
    vector<pll> events;
    for (auto &[x, p] : s) {
        cin >> x >> p;
        events.emplace_back(x - p, 1);
        events.emplace_back(x, -2);
        events.emplace_back(x + p, 1);
    }

    sort(all(events));

    ll der = 0;
    ll height = 0;
    ll last = -1e9;
    ll max_sum = -1e18, min_diff = 1e18;
    for (int i = 0; i < sz(events); ) {
        int j = i;
        height += (events[i].first - last) * der;
        last = events[i].first;
        for (; j < sz(events) && events[j].first == events[i].first; ++j) {
            der += events[j].second;
        }
        ll x = events[i].first;
        ll y = height;
        // cerr << x << " " << y << endl;
        if (y > threshold) {
            max_sum = max(max_sum, x + y - threshold);
            min_diff = min(min_diff, x - y + threshold);
        }
        i = j;
    }

    // cerr << min_diff << " " << max_sum << endl;

    string res = "";
    for (auto &[x, p] : s) {
        res += (max_sum <= x + p && x - p <= min_diff ? '1' : '0');
    }
    cout << res << endl;

}