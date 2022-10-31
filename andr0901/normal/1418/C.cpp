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

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector <int> a(n + 1);
    forn (i, 1, n + 1)
        cin >> a[i];
    vector <vector <int>> dp(n + 1, vector <int> (2, INF));
    dp[0][0] = 0;
    forn (i, 1, n + 1) {
        chkmin(dp[i][0], min(dp[i - 1][1], i - 2 < 0 ? INF : dp[i - 2][1]));
        chkmin(dp[i][1], min(dp[i - 1][0] + a[i],
                             i - 2 < 0 ? INF : dp[i - 2][0] + a[i] + a[i - 1]));
    }
    cout << min(dp[n][0], dp[n][1]) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
       cin >> t;
       while (t --> 0)
           solve();   
    return 0;
}