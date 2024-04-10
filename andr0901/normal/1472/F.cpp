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
    int m, n;
    cin >> m >> n;
    map<int, map<int, int>> obstacles;
    set<int> interesting;
    forn (i, 0, n) {
        int x, y;
        cin >> x >> y, --x;
        x = 1 - x;
        obstacles[x][y] = true;
        interesting.insert(y);
    }
    interesting.insert(m);
    vector<vector<int>> dp(2, vector<int> (2, false));
    dp[1][1] = true;
    int lst = 0;
    for (int i : interesting) {
        if ((i - 1) % 2 != lst % 2) {
            vector<vector<int>> new_dp(2, vector<int> (2, false));
            new_dp[0][0] = new_dp[1][1] = (dp[0][0] | dp[1][1]);
            new_dp[0][1] = dp[1][0];
            new_dp[1][0] = dp[0][1];
            dp = new_dp;
        }
        vector<vector<int>> new_dp(2, vector<int> (2, false));
        if (!obstacles[0][i] && !obstacles[1][i]) {
            new_dp[0][0] = new_dp[1][1] = (dp[0][0] | dp[1][1]);
            new_dp[0][1] = dp[1][0];
            new_dp[1][0] = dp[0][1];
        } else if (obstacles[0][i] && !obstacles[1][i]) {
            new_dp[1][0] |= dp[1][1];
            new_dp[1][0] |= dp[0][0];
            new_dp[1][1] |= dp[1][0];
        } else if (!obstacles[0][i] && obstacles[1][i]) {
            new_dp[0][1] |= dp[1][1];
            new_dp[0][1] |= dp[0][0];
            new_dp[1][1] |= dp[0][1];
        } else if (obstacles[0][i] && obstacles[1][i]) {
            new_dp[1][1] |= dp[0][0];
            new_dp[1][1] |= dp[1][1];
        }
        dp = new_dp;
        lst = i;
        cerr << lst << ": " << dp[0][0] << dp[0][1] << dp[1][0] << dp[1][1] << "\n"; 
    }
    cerr << "\n";
    cout << (dp[1][1] ? "YES" : "NO") << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}