#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
// using ld = long double; 
using ld = __float128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;

void solve();

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

void solve() {  
    int n;
    cin >> n;
    n += 2;
    vector<string> mes(n);
    mes[0] = "unlock";
    for (int i = 1; i < n - 1; ++i) {
        cin >> mes[i];
    }
    mes[n - 1] = "lock";

    set<int> changes;
    set<int> good;

    for (int i = 0; i < n; ++i) {
        if (mes[i] == "lock" || mes[i] == "unlock") {
            changes.insert(i);
        }
        if (i + 1 < n && mes[i] == "unlock" && mes[i + 1] != "lock" && mes[i + 1] != "unlock") {
            good.insert(i);
        }
    }

    auto get = [&]() -> string {
        if (good.empty()) {
            return "blue";
        }
        int pos = *(--good.end());
        return mes[*(changes.upper_bound(pos)) - 1];
    };

    cout << get() << endl;

    int q;
    cin >> q;
    while (q--) {
        int i;
        string s;
        cin >> i >> s;

        if (mes[i] == "lock" || mes[i] == "unlock") {
            changes.erase(i);
        }
        if (mes[i - 1] == "unlock" && mes[i] != "lock" && mes[i] != "unlock") {
            good.erase(i - 1);
        }
        if (i + 1 < n && mes[i] == "unlock" && mes[i + 1] != "lock" && mes[i + 1] != "unlock") {
            good.erase(i);
        }


        mes[i] = s;

        if (mes[i] == "lock" || mes[i] == "unlock") {
            changes.insert(i);
        }
        if (mes[i - 1] == "unlock" && mes[i] != "lock" && mes[i] != "unlock") {
            good.insert(i - 1);
        }
        if (i + 1 < n && mes[i] == "unlock" && mes[i + 1] != "lock" && mes[i + 1] != "unlock") {
            good.insert(i);
        }
        cout << get() << endl;
    }
}