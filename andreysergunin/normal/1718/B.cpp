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
    // freopen("input.txt", "r", stdin);
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
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (ll &x : a) {
        cin >> x;
        sum += x;
    }
    vector<ll> f = {1, 1};
    int k = 2;
    for (; f.back() - 1 < sum; ++k) {
        f.push_back(f[k - 1] + f[k - 2]);
    }

    if (f.back() - 1 != sum) {
        cout << "No\n";
        return;
    }

    bool found = false;

    function<void(int, int)> brute = [&](int t, int last) {
        if (t == -1) {
            found = true;
            return;
        }
        ll maxx = *max_element(all(a));
        for (int i = 0; i < n; ++i) {
            if (a[i] == maxx && a[i] >= f[t] && last != i) {
                a[i] -= f[t];
                brute(t - 1, i);
                a[i] += f[t];    
                return;
            }
        }
    };

    brute(k - 3, -1);

    cout << (found ? "Yes\n" : "No\n");
}