#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second
#define pb emplace_back
#define all(x) (x).begin(), (x).end()

const int INF = 1e9 + 1;
const int mod = 1e9;

mt19937 gen(time(0));

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> gr(n);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y; x--; y--;
            gr[y].pb(x);
        }
        vector<int> ans;
        vector<int> usd(n);
        for (int i = 0; i < n; i++) {
            for (auto &from : gr[i]) usd[i] = max(usd[i], usd[from] + 1);
            if (usd[i] == 2) {
                ans.pb(i);
                usd[i] = -1;
            }
        }
        cout << ans.size() << "\n";
        for (auto &c : ans) cout << c + 1 << " ";
        cout << "\n";
    }
    return 0;
}