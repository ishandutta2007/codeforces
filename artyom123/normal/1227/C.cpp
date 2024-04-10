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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<pii> ans;
        string t = "";
        for (int i = 0; i < k - 1; i++) {
            t += '(';
            t += ')';
        }
        int cnt = (s.size() - t.size()) / 2;
        for (int i = 0; i < cnt; i++) t += '(';
        for (int i = 0; i < cnt; i++) t += ')';
        for (int i = 0; i < n; i++) {
            if (s[i] == t[i]) continue;
            int r = -1;
            for (int j = i + 1; j < n; j++) {
                if (s[j] == t[i]) {
                    r = j;
                    break;
                }
            }
            ans.pb(i, r);
            reverse(s.begin() + i, s.begin() + r + 1);
        }
        cout << ans.size() << "\n";
        for (auto &c : ans) cout << c.fi + 1 << " " << c.se + 1 << "\n";
    }
    return 0;
}