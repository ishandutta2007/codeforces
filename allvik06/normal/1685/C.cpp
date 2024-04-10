#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <bitset>
#include <chrono>
#include <cmath>
#include <set>
#include <queue>
#include <array>
#include <map>
#include <iomanip>
#include <random>

using namespace std;
const int INF = 1e9;

inline void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = -1, r = -1;
    vector <int> bal(2 * n + 1);
    for (int i = 0; i < 2 * n; ++i) {
        bal[i + 1] = bal[i];
        if (s[i] == '(') ++bal[i + 1];
        else --bal[i + 1];
    }
    for (int i = 0; i < 2 * n; ++i) {
        if (bal[i + 1] < 0 && l == -1) {
            l = i;
        }
        if (bal[i + 1] < 0) {
            r = i;
        }
    }
    if (l == -1) {
        cout << "0\n";
        return;
    }
    int mx_l = -INF, mx_r = -INF, mx_mid = 0;
    for (int i = 0; i <= l; ++i) {
        mx_l = max(mx_l, bal[i]);
    }
    for (int i = r; i < 2 * n; ++i) {
        mx_r = max(mx_r, bal[i + 1]);
    }
    for (int i = l; i <= r; ++i) {
        mx_mid = max(mx_mid, bal[i]);
    }
    if (mx_mid <= mx_l + mx_r) {
        cout << "1\n";
        for (int i = 0; i <= l; ++i) {
            if (bal[i] == mx_l) {
                cout << i + 1 << " ";
                break;
            }
        }
        for (int i = r; i < 2 * n; ++i) {
            if (bal[i + 1] == mx_r) {
                cout << i + 1 << "\n";
                break;
            }
        }
        return;
    }
    int p_max = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (bal[i + 1] > bal[p_max + 1]) p_max = i;
    }
    cout << "2\n" << 1 << " " << p_max + 1 << "\n" << p_max + 2 << " " << 2 * n << "\n";
}

signed main(){
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

/*

 */