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
    string s;
    cin >> s;

    vector<int> b(2 * n + 1);
    for (int i = 0; i < 2 * n; ++i) {
        b[i + 1] = b[i] + (s[i] == '(' ? 1 : -1);
    }

    int d = b[2 * n] / 2;
    vector<int> pref(2 * n + 1), suff(2 * n + 1);
    pref[0] = true;
    for (int i = 1; i <= 2 * n; ++i) {
        pref[i] = pref[i - 1] & (b[i] >= 0);
    }
    suff[2 * n] = true;
    for (int i = 2 * n - 1; i >= 0; --i) {
        suff[i] = suff[i + 1] & (b[i] >= 0);
    }

    if (pref[2 * n]) {
        cout << 0 << "\n";
        return;
    }

    int max_pos = max_element(all(b)) - b.begin();

    int u = 0, v = 2 * n;

    for (int i = 0; i <= 2 * n; ++i) {
        if (pref[i]) {
            if (b[u] < b[i]) {
                u = i;
            }
        }
        if (suff[i]) {
            if (b[v] < b[i]) {
                v = i;
            }
        }
    }

    if (b[u] + b[v] >= b[max_pos]) {
        cout << 1 << "\n";
        cout << u + 1 << " " << v << "\n";
        return;
    }


    cout << 2 << "\n";
    cout << 1 << " " << max_pos << "\n";
    cout << max_pos + 1 << " " << 2 * n << "\n";
}