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
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    map<int, vector<int>> mapa;
    set<int> setik;
    for (int i = 0; i < n; ++i) {
        setik.insert(a[i]);
        mapa[a[i]].push_back(i);
    }   

    vector<int> res(n);
    while (!setik.empty()) {
        vector<int> arr;
        vector<int> to_del;
        for (int val : setik) {
            arr.push_back(mapa[val].back());
            mapa[val].pop_back();
            if (mapa[val].empty()) {
                to_del.push_back(val);
            }
        }
        for (auto val : to_del) {
            setik.erase(val);
        }

        for (int i = 0; i < sz(arr); ++i) {
            res[arr[i]] = a[arr[(i + 1) % sz(arr)]];
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

}