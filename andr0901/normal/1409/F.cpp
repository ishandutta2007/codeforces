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

void solve() {
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    vector <vector <int>> dp(k + 2, vector <int> (n + 1, -1e9));
    dp[0][0] = 0;
    forn (i, 0, n) {
        vector <vector <int>> new_dp = dp;
        forn (prev_k, 0, k + 1) {
            forn (prev_pref, 0, n + 1) {
                chkmax(new_dp[prev_k + (a[i] != b[1])][prev_pref], dp[prev_k][prev_pref] + prev_pref);
                chkmax(new_dp[prev_k + (a[i] != b[0])][prev_pref + 1], dp[prev_k][prev_pref] + (b[0] == b[1] ? prev_pref : 0));
                 // cerr << dp[prev_k][prev_pref] << " ";
            }
             // cerr << "\n";
        }
        swap(dp, new_dp);
    }
    int ans = 0;
    forn (i, 0, k + 1)
        forn (j, 0, n + 1)
            chkmax(ans, dp[i][j]);
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t --> 0)
        solve();   
    return 0;
}