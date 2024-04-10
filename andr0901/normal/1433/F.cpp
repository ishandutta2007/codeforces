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

constexpr int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector <int>> a(n, vector <int> (m));
    cin >> a;
    vector <int> d(k, -INF);
    d[0] = 0;
    forn (i, 0, n) {
        vector <vector <int>> dp(m / 2 + 1, vector <int> (k, -INF));
        dp[0][0] = 0;
        forn (j, 0, m) {
            vector <vector <int>> new_dp = dp;
            forn (prev, 0, m / 2)
                forn (prev_r, 0, k)
                    chkmax(new_dp[prev + 1][(prev_r + a[i][j]) % k], dp[prev][prev_r] + a[i][j]); 
            dp = new_dp;
        }
        cerr << dp << "\n";
        vector <int> ans(k, -INF);
        forn (j, 0, k)
            forn (r, 0, m / 2 + 1)
                chkmax(ans[j], dp[r][j]);
        vector <int> new_d = d;
        forn (prev, 0, k)
            forn (nxt, 0, k)
                chkmax(new_d[(prev + nxt) % k], d[prev] + ans[nxt]);
        d = new_d;
    }
    cout << d[0];
    return 0;
}