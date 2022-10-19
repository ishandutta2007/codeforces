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
#define int long long
const int INF = 1e9;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int sum = 0;
    for (int i : a) sum += i;
    int l = 0, r = INF;
    while (r - l > 1) {
        int m = (l + r) / 2;
        int cur = 0;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            cur += m;
            if (a[i] > cur) {
                ok = false;
                break;
            }
            cur -= a[i];
        }
        if (!ok) l = m;
        else r = m;
    }
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        if (x <= l) cout << "-1\n";
        else cout << (sum + x - 1) / x << "\n";
    }
}

/*

 */