#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;
#define int long long

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n), b(n);
        map <int, int> da;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ++da[a[i]];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        sort(b.rbegin(), b.rend());
        bool ok = true;
        for (int i : b) {
            if (da[i] > 0) --da[i];
            else if (da[i - 1] > 0) {
                --da[i - 1];
            } else {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

/*

 */