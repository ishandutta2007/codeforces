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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        for (int i = 0; i < n; i++) {
            int x = min(a[i], k);
            a[i] -= x;
            a.back() += x;
            k -= x;
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
}