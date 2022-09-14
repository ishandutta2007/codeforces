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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    map<int, int> lf, rg;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        if (!lf.count(a[i])) {
            lf[a[i]] = n;
            rg[a[i]] = 0;
        }
        lf[a[i]] = min(lf[a[i]], i);
        rg[a[i]] = max(rg[a[i]], i + 1);
    }

    vector<pii> e;

    for (auto el : lf) {
        e.push_back({el.second, 1});
    }
    for (auto el : rg) {
        e.push_back({el.second, -1});
    }

    sort(all(e));

    int bal = 0;

    vector<int> x = {0};

    for (auto el : e) {
        bal += el.second;
        if (bal == 0) {
            x.push_back(el.first);
        }
    }

    int res = 0;
    for (int i = 0; i + 1 < sz(x); ++i) {
        map<int, int> mapa; 
        for (int j = x[i]; j < x[i + 1]; ++j) {
            ++mapa[a[j]];
        }
        int maxx = 0;
        for (auto el : mapa) {
            maxx = max(maxx, el.second);
        }
        res += x[i + 1] - x[i] - maxx;
    }

    cout << res << endl;


    


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif  

    int tests = 1;
    // cin >> tests;
    for (int test = 0; test < tests; ++test) {
        solve();
    }

    
#ifdef LOCAL
    cerr << "Time: " << ld(clock()) / CLOCKS_PER_SEC << endl;
#endif
}