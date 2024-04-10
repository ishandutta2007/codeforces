#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);

    int ntest;
    cin >> ntest;

    while (ntest--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &e : a) cin >> e;
        vector<int> cnt(n + 2, 0);
        for (int e : a) cnt[e]++;
        int mx = 0;
        for (int i = 0; i <= n; i++) mx = max(mx, cnt[i]);
        if (mx > n - n / 2) {
            cout << - 1 << '\n';
            continue;
        }
        vector<vector<int>> segs;
        vector<int> cur;
        for (int i = 0; i < n; i++) {
            if (i == 0 || a[i] != a[i - 1]) cur.push_back(a[i]);
            else {
                // cout i << ' ';
                segs.push_back(cur);
                cur.clear();
                cur.push_back(a[i]);
            }
        }
        // cout << endl;
        segs.push_back(cur);
        cnt.clear();
        cnt.resize(n + 2, 0);
        for (auto e : segs) {
            cnt[e[0]]++;
            cnt[e.back()]++;
        }
        mx = 0;
        for (int i = 0; i <= n; i++) mx = max(mx, cnt[i]);
        int rem = 2 * segs.size() - mx;
        
        int ans = 0;
        ans += (int) segs.size() - 1;
        if (rem < segs.size() - 1) ans += (int) segs.size() - 1 - rem;
        cout << ans << '\n';
        
    }

    return 0;
}