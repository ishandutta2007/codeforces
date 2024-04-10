#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> cnt(n + 1);
        for (int i = 1; i <= n; i++) {
            int u; cin >> u;
            cnt[u]++;
        }
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            if (cnt[i]) v.pb(cnt[i]);
        }
        sort(all(v));
        int ans = n;
        for (int s = 1; s <= v[0]; s++) {
            bool ok = 1;
            int tmp = 0;
            for (int e : v) {
                int tmpans = 1e9;
                int l = 1, r = e;
                while (r >= l) {
                    int mid = (l + r) / 2;
                    if (e / mid >= s) {
                        if (e / mid == s || (e / mid == s + 1 && e % mid == 0)) {
                            tmpans = mid;
                            r = mid - 1;
                        } else l = mid + 1;
                    } else r = mid - 1;
                }
                if (tmpans == 1e9) ok = 0;
                else tmp += tmpans;
            }
            if (ok == 0) continue;
            ans = min(tmp, ans);
        }
        cout << ans << '\n';
    }
    return 0;
}