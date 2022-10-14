#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << endl;\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 100005, logN = 18, K = 600, C = 100, M = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    string s[n];
    fop (i,0,n) cin >> s[i];
    int pre[n][m + 1];
    fop (i,0,n) pre[i][0] = 0;
    fop (i,0,n) fop (j,0,m) pre[i][j + 1] = pre[i][j] + (s[i][j] == '*');
    int ans = 0;
    fop (i,0,n) fop (j,0,m) if (s[i][j] == '*') {
        ans++;
        int k = 1;
        while (true) {
            int row = i + k, l = j - k, r = j + k + 1;
            if (row >= n || l < 0 || r > m) break;
            if (pre[row][r] - pre[row][l] == r - l) ans++;
            else break;
            k++;
        }
    }
    cout << ans << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}