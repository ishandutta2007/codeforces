// #pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
 
void solve();
 
int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(14) << fixed;
    cerr << setprecision(14) << fixed;
 
    int tests = 1;
    // cin >> tests;
 
    while (tests--) {
       solve();
    }
 
#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}
 
// ----------------------------------------------------------------- 

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<int> used(m);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        ++used[arr[i] % m];
        if (used[arr[i] % m] >= 2) {
            cout << 0 << endl;
            return;
        }
    }

    int res = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int x = abs(arr[i] - arr[j]) % m;
            res *= x;
            res %= m;
        }
    }

    cout << res << endl;


}