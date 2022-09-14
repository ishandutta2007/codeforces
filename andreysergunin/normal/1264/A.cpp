#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    int g = 1;

    for (int i = 1; i < n; ++i) {
        if (p[i] == p[i - 1]) {
            ++g;
        } else {
            break;
        }
    }

    int s = 1;
    for (int i = g + 1; i < n; ++i) {
        if (p[i] == p[i - 1]) {
            ++s;
        } else {
            if (s > g) {
                break;
            }
            ++s;
        }
    }


    int b = 1;
    int okb = -1;

    for (int i = g + s + 1; i < n; ++i) {
        if (p[i] == p[i - 1]) {
            ++b;
        } else {
            if (b > g && 2 * (g + s + b) <= n) {
                okb = b;
            }
            ++b;
        }
    }

    if (okb == -1) {
        cout << "0 0 0\n";
        return;
    }

    cout << g << " " << s << " " << okb << "\n";
}

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

    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}