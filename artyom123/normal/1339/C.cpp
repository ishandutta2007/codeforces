#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back

const int INF = 1e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &c : a) cin >> c;
        int mx = -INF, cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt = max(cnt, mx - a[i]);
            mx = max(mx, a[i]);
        }
        if (cnt == 0) {
            cout << 0 << "\n";
            continue;
        }
        for (int ans = 0; ; ans++) {
            cnt -= (1 << ans);
            if (cnt <= 0) {
                cout << ans + 1 << "\n";
                break;
            }
        }
    }
    return 0;
}