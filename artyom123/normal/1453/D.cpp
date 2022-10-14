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
        ll k;
        cin >> k;
        if (k % 2 == 1) {
            cout << -1 << "\n";
            continue;
        }
        vector<int> ans;
        for (int i = 1; i < 60; i++) {
            if (k & (1LL << i)) {
                if (i == 1) {
                    ans.pb(1);
                } else {
                    ans.pb(1);
                    ans.pb(1);
                    for (int j = 0; j < i - 2; j++) ans.pb(0);
                }
            }
        }
        cout << ans.size() << "\n";
        for (auto &c : ans) cout << c << " ";
        cout << "\n";
    }
    return 0;
}