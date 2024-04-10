#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);

    int ntest;
    cin >> ntest;
    
    while (ntest--) {
        int n, w;
        cin >> n >> w;
        vector<ii> a(n);
        for (ii &e : a) cin >> e.x;
        for (int i = 0; i < n; i++) {
            a[i].y = i + 1;
        }
        sort(a.rbegin(), a.rend());
        int cur = 0;
        vector<int> ans;
        for (ii e : a) {
            if (cur + e.x <= w) {
                cur += e.x;
                ans.push_back(e.y);
            }
        }
        if (cur < (w + 1) / 2) {
            cout << -1 << '\n';
        } else {
            cout << ans.size() << '\n';
            for (int e : ans) cout << e << ' ';
            cout << '\n';
        }
    }

    return 0;
}