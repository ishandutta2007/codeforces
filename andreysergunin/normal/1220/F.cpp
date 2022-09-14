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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);
    

vector<int> get(vector<int> a) {
    vector<pii> st;
    int mx = 0;

    vector<int> res = {0};

    int n = sz(a);

    for (int i = 0; i < n; ++i) {
        int cur = 1;

        while (sz(st) > 0 && st.back().first > a[i]) {
            cur = max(cur, st.back().second + 1);
            if (sz(st) > 1) {
                int k = sz(st);
                st[k - 2].second = max(st[k - 2].second, st[k - 1].second + 1);
            }
            st.pop_back();
        }

        st.push_back({a[i], cur});
        mx = max(mx, sz(st) + cur - 1);
        res.push_back(mx);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 

    int n;
    cin >> n;
    vector<int> p(n);

    int pos = 0;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        if (p[i] == 1) {
            pos = i;
        }
    }

    vector<int> a;
    for (int i = (pos + 1) % n; i != pos; i = (i + 1) % n) {
        a.push_back(p[i]);
    }

    vector<int> f = get(a);
    reverse(all(a));
    vector<int> g = get(a);

    // for (int el : f) {
    //     cout << el << " ";
    // }
    // cout << endl;

    // for (int el : g) {
    //     cout << el << " ";
    // }
    // cout << endl;

    int k = 0;
    for (int i = 1; i <= n - 1; ++i) {
        if (max(f[k], g[n - 1 - k]) > max(f[i], g[n - 1 - i])) {
            k = i;
        }
    }

    int to = n - 1 - k;

    int res = max(f[k], g[n - 1 - k]) + 1;

    cout << res << " " << (pos >= to ? pos - to : n - (to - pos)) << endl;



#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}