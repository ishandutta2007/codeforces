//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}
 
const int MOD = 1e9 + 7;
const int M = 2e5 + 50;

vector<vector<vector<int>>> dp;
 
void solve() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    while (n) {
        int d = n % 10;
        forn (i, 0, 10) {
            ans = (ans + dp[d][m][i]) % MOD;    
        }
        n /= 10;
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    dp.resize(10, vector<vector<int>>(M, vector<int>(10)));
    forn (d, 0, 10) {
        dp[d][0][d] = 1;
        forn (i, 1, M) {
            dp[d][i][0] = dp[d][i][1] = dp[d][i - 1][9];
            forn (j, 1, 10) {
                dp[d][i][j] = (dp[d][i][j] + dp[d][i - 1][j - 1]) % MOD; 
            }
        }
    }
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}