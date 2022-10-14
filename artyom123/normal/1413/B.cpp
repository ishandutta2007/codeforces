#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define ld long double
#define pb emplace_back
#define pii pair<int, int>

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        vector<int> b(n * m + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                b[a[i][j]] = i;
            }
        }
        for (int j = 0; j < m; j++) {
            vector<int> now(n);
            bool f = false;
            for (auto &c : now) {
                cin >> c;
                if (c == a[0][0]) f = true;
            }
            if (!f) continue;
            for (auto &c : now) {
                for (auto &l : a[b[c]]) {
                    cout << l << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}