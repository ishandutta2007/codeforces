#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())
 
using namespace std;
 
const int maxn = 509;
int n, m;
bool a[maxn][maxn];
 
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int e = 0; e < m; e++) {
            if (s[e] != '.')
                a[i][e] = 1;
            else
                a[i][e] = 0;
        }
    }
    int u = 1;
    if (n % 3 == 1)
        u = 0;
    for (int i = u; i < n; i += 3) {
        for (int e = 0; e < m; e++)
            a[i][e] = 1;
        if (i + 3 < n) {
            if (a[i + 1][m - 2] || a[i + 2][m - 2]) {
                a[i + 1][m - 2] = 1;
                a[i + 2][m - 2] = 1;
            } else {
                a[i + 1][m - 1] = 1;
                a[i + 2][m - 1] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int e = 0; e < m; e++) {
            if (a[i][e])
                cout << "X";
            else
                cout << ".";
        }
        cout << "\n";
    }
}
 
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}