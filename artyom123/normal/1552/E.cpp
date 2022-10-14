#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double
#define mp make_pair
#define ull unsigned long long

const int INF = 1e9 + 1;
const ll INFLL = (ll)1e18 + 1;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t = 1;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n * k);
        for (auto &c : a) {
            cin >> c;
            c--;
        }
        vector<vector<int>> gist(n);
        for (int i = 0; i < n * k; i++) {
            gist[a[i]].pb(i);
        }
        vector<pii> ans(n);
        vector<int> usd(n);
        for (int c = 0; c < n; c += k - 1) {
            int c2 = min(c + k - 2, n - 1);
            vector<pair<pii, int>> b;
            for (int i = c; i <= c2; i++) {
                for (int j = 0; j + 1 < k; j++) {
                    b.pb(make_pair(gist[i][j + 1], gist[i][j]), i);
                }
            }
            sort(all(b));
            int mx = -1;
            for (auto &c : b) {
                if (usd[c.se]) continue;
                if (c.fi.se < mx) continue;
                usd[c.se] = 1;
                ans[c.se] = {c.fi.se, c.fi.fi};
                mx = max(mx, c.fi.fi);
            }
        }
        for (auto &c : ans) cout << c.fi + 1 << " " << c.se + 1 << "\n";
    }
    return 0;
}