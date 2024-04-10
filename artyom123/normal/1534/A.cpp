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
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (auto &c : a) cin >> c;
        vector<string> b(n, string(m, '.'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) % 2 == 0) b[i][j] = 'R';
                else b[i][j] = 'W';
            }
        }
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '.') continue;
                if (a[i][j] != b[i][j]) ok = 0;
            }
        }
        if (!ok) {
            ok = 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if ((i + j) % 2 == 0) b[i][j] = 'W';
                    else b[i][j] = 'R';
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i][j] == '.') continue;
                    if (a[i][j] != b[i][j]) ok = 0;
                }
            }
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (auto &c : b) cout << c << "\n";
    }
    return 0;
}