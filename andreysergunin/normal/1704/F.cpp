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
void precalc();
 
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

    precalc();
 
    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }
 
#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}
 
// ----------------------------------------------------------------- 

vector<int> gr;

void precalc() {
    int n = 200;
    gr.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
        vector<int> arr;
        for (int j = 0; j + 2 <= i; ++j) {
            arr.push_back(gr[j] ^ gr[i - j - 2]);
        }
        sort(all(arr));
        unique(all(arr));
        for (int g = 0; g <= sz(arr); ++g) {
            if (g == sz(arr) || arr[g] != g) {
                gr[i] = g;
                break;
            }
        }
    }
}


void solve() {  
    int n;
    cin >> n;

    string s;
    cin >> s;
    int r = 0, b = 0;
    for (char c : s) {
        r += c == 'R';
        b += c == 'B';
    }
    if (r != b) {
        cout << (r > b ? "Alice\n" : "Bob\n");
        return;
    }

    int res = 0;
    int len = 1;
    for (int i = 1; i <= n; ++i) {
        if (i == n || s[i - 1] == s[i]) {
            res ^= len < sz(gr) ? gr[len] : gr[68 + len % 34];
            len = 1;
        } else {
            ++len;
        }
    }

    cout << (res ? "Alice\n" : "Bob\n");
}