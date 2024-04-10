#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> a(n);
        for (auto &c : a) {
            cin >> c;
            for (auto &l : c) l -= '0';
        }
        for (int d = 0; d < 10; d++) {
            ll ans = 0;
            ///   
            int mni = INF, mxi = -INF;
            for (int i = 0; i < n; i++) {
                for (auto &c : a[i]) {
                    if (c == d) {
                        mni = min(mni, i);
                        mxi = max(mxi, i);
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                vector<int> pos;
                for (int j = 0; j < n; j++) {
                    if (a[i][j] == d) pos.pb(j);
                }
                if ((int)pos.size() >= 2) {
                    ans = max(ans, (ll)(pos.back() - pos[0]) * (ll)max(n - 1 - i, i));
                }
                if (pos.empty()) continue;
                ans = max(ans, (ll)max(pos.back(), n - 1 - pos[0]) * (ll)max(i - mni, mxi - i));
            }
            ///   
            int mnj = INF, mxj = -INF;
            for (int j = 0; j < n; j++) {
                for (int i = 0; i < n; i++) {
                    if (a[i][j] == d) {
                        mnj = min(mnj, j);
                        mxj = max(mxj, j);
                    }
                }
            }
            for (int j = 0; j < n; j++) {
                vector<int> pos;
                for (int i = 0; i < n; i++) {
                    if (a[i][j] == d) pos.pb(i);
                }
                if ((int)pos.size() >= 2) {
                    ans = max(ans, (ll)(pos.back() - pos[0]) * (ll)max(n - 1 - j, j));
                }
                if (pos.empty()) continue;
                ans = max(ans, (ll)max(pos.back(), n - 1 - pos[0]) * (ll)max(j - mnj, mxj - j));
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
    return 0;
}