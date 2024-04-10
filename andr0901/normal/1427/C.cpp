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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int r, n;
    cin >> r >> n;
    vector <vector <int>> a(n, vector <int> (3));
    cin >> a;
    vector <int> dp(n, 1);
    vector <int> sf(n, 1);
    for (int i = n - 2; i >= 0; --i) {
        forn (j, i + 1, n) {
            if (abs(a[i][1] - a[j][1]) +
                abs(a[i][2] - a[j][2]) <=
                a[j][0] - a[i][0]) {
                chkmax(dp[i], dp[j] + 1);
            }
            if (a[j][0] - a[i][0] > 2 * r) {
                chkmax(dp[i], sf[j] + 1);
                break;
            }
        }
        sf[i] = max(sf[i + 1], dp[i]);
    }
    cerr << dp << "\n";
    int ans = 0;
    forn (i, 0, n)
        if (abs(a[i][1] - 1) +
            abs(a[i][2] - 1) <=
                a[i][0])
            chkmax(ans, dp[i]);
    cout << ans;
    return 0;
}