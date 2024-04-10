#pragma GCC optimize("Ofast", "unroll-loops")

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>
#include <chrono>
#include <climits>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using ull = unsigned long long;
using Complex = complex<double>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
// mt19937 rnd(1);

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> a(n);
    vector<int> last(10, -1);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
        last[a[i]] = i;
    }

    for (int i = 0; i <= 8; ++i) {
        last[i + 1] = max(last[i], last[i + 1]);
    }



    for (int k = 0; k < 10; ++k) {
        vector<int> c(n, 2);

        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] < k) {
                c[i] = 1;
            } else if (a[i] == k && (k == 0 || last[k - 1] < i)) {
                c[i] = 1;
            }
        }

        vector<int> x;
        for (int i = 0; i < n; ++i) {
            if (c[i] == 1) {
                x.push_back(a[i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (c[i] == 2) {
                x.push_back(a[i]);
            }
        }

        for (int i = 0; i < n - 1;  ++i) {
            ok &= x[i] <= x[i + 1];
        }

        if (ok) {
            for (int i = 0; i < n; ++i) {
                cout << c[i];
            }
            cout << endl;
            return;
        }
    }
    cout << "-" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif  
        
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        solve();
    }



#ifdef LOCAL
    cerr << "Time: " << ld(clock()) / CLOCKS_PER_SEC << endl;
#endif
}