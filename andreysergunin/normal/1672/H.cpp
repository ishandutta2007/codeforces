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
    // cin >> tests;
 
    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }
 
#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}
 
// ----------------------------------------------------------------- 

struct BIT {    
    BIT() = default;
    BIT(int n) {
        arr.assign(n, 0);
    }
 
    void update(int i, int val) {
        for (; i < sz(arr); i |= (i + 1)) {
            arr[i] += val;
        }
    }
 
    int get(int i) {
        int res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) {
            res += arr[i];
        }
        return res;
    }

    int get(int i, int j) {
        return get(j - 1) - get(i - 1);
    }
 
    vector<int> arr;
};


void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;  

    array<BIT, 2> bit = {BIT(n - 1), BIT(n - 1)};

    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == s[i + 1]) {
            bit[s[i] - '0'].update(i, 1);
        }
    }

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        cout << max(bit[0].get(l, r), bit[1].get(l, r)) + 1 << endl;
    }


}