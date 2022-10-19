#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define int long long

main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int a[10];
        for (int i = 0; i < 3; i++) {
            cin >> a[i];
        }
        sort(a, a + 3);
        int res = 0;
        int v = a[2] - a[1];
        res += min(v, a[0]);
        a[0] -= min(v, a[0]);
        v -= min(v, a[0]);
        a[2] -= v;
        if (a[0] == 0) {
            res += a[1];
        } else {
            int t = a[0] / 2;
            res += 2 * t;
            res += a[1] - t;
        }
        cout << res << '\n';
    }
    return 0;
}