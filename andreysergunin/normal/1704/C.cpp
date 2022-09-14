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
    int len, n;
    cin >> len >> n;
    vector<int> arr(n);
    for (int &x : arr) {
        cin >> x;
    }
    sort(all(arr));
    vector<int> diffs;
    for (int i = 0; i + 1 < n; ++i) {
        diffs.emplace_back(arr[i + 1] - arr[i] - 1);
    }
    diffs.emplace_back(arr[0] + len - arr[n - 1] - 1);

    sort(all(diffs));

    int step = 0;

    int alive = 0;
    for (int i = n - 1; i >= 0; --i) {
        int l = diffs[i];
        if (l <= 2 * step) {
            break;
        } else if (l <= 2 * step + 2) {
            ++alive;
            ++step;
        } else {
            alive += l - (2 * step + 1);
            step += 2;
        }
    }

    cout << len - alive << endl;

}