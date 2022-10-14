#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;
const int mod = 1e9 + 7;

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
        vector<int> ans;
        while (1) {
            vector<int> usd(n + 1);
            for (auto &c : a) usd[c] = 1;
            int MEX = 0;
            while (usd[MEX]) MEX++;
            if (MEX < n) {
                a[MEX] = MEX;
                ans.pb(MEX);
                continue;
            }
            bool f = true;
            for (int i = 0; i < n; i++) {
                if (a[i] == i) continue;
                f = false;
                ans.pb(i);
                a[i] = n;
                break;
            }
            if (f) break;
        }
        cout << ans.size() << "\n";
        for (auto &c : ans) cout << c + 1 << " ";
        cout << "\n";
    }
    return 0;
}