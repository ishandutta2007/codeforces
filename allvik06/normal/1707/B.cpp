#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <random>

using namespace std;
#define int long long

void make_oper(map <int, int>& d) {
    map <int, int> flex;
    for (auto i : d) {
        if (i.second > 1) flex[0] += i.second - 1;
    }
    int prev = -1;
    for (auto i : d) {
        if (prev == -1) {
            prev = i.first;
            continue;
        }
        flex[i.first - prev]++;
        prev = i.first;
    }
    d = flex;
    map <int, int>().swap(flex);
}

inline void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    map <int, int> d;
    for (int i : a) ++d[i];
    for (int _ = 0; _ < n - 1; ++_) make_oper(d);
    for (auto i : d) cout << i.first << "\n";
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t;
        cin >> t;
        while (t--) {
            solve();
        }
    } else {

    }
}

/*

 */