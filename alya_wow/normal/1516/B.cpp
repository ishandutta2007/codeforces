#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int main() {
#ifdef BZ
    freopen("../a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int w = 0;
        bool is = 0;
        for (int &i : a) {
            cin >> i;
            w ^= i;
        }
        int x = w;
        int l = n, r = -1;
        w = 0;
        for (int i = 0; i < n; i++) {
            w ^= a[i];
            if (w == x) {
                l = i;
                break;
            }
        }
        w = 0;
        for (int i = n - 1; i >= 0; i--) {
            w ^= a[i];
            if (w == x) {
                r = i;
                break;
            }
        }
        if (x == 0 || l < r)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}