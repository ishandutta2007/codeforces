#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define test(args...) abc("[" + string(#args) + "]", args)
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
const int mod = 1e9 + 7, N = 5001, logN = 20, K = 111;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <vector <bool>> ans(n, vector <bool> (m, false));
    for (int i = 0; i < m; i += 2) ans[0][i] = ans[n - 1][m - i - 1] = true;
    for (int i = (m & 1 ? 0 : 2); i + 2 < n; i += 2) ans[i][m - 1] = ans[i][0] = true;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        cout << ans[i][j];
        if (j == m - 1) cout << endl;
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}