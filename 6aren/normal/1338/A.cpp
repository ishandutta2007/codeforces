#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> up(n + 1);
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        up[1] = 0;
        for (int i = 2; i <= n; i++) {
            up[i] = max(0LL, a[i - 1] + up[i - 1] - a[i]);
        }
        int res = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = 31; j >= 0; j--) {
                if (bit(up[i], j)) res = max(res, j);
            }
        }
        cout << res + 1 << '\n';
    }
    return 0;
}