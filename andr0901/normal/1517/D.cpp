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
    if (k % 2) {
        forn (i, 0, n) {
            forn (j, 0, m) {
                cout << "-1 ";
            }
            cout << "\n";
        }
        return 0;
    }
    k /= 2;
    vector<vector<int>> hor(n, vector<int>(m - 1));
    cin >> hor;
    vector<vector<int>> ver(n - 1, vector<int>(m));
    cin >> ver;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, INF)));
    forn (i, 0, n) {
        forn (j, 0, m) {
            dp[i][j][0] = 0;
        }
    }
    forn (len, 1, k + 1) {
        forn (i, 0, n) {
            forn (j, 0, m) {
                if (i - 1 >= 0) {
                    chkmin(dp[i][j][len], dp[i - 1][j][len - 1] + ver[i - 1][j]);
                }
                if (i + 1 < n) {
                    chkmin(dp[i][j][len], dp[i + 1][j][len - 1] + ver[i][j]);
                }
                if (j - 1 >= 0) {
                    chkmin(dp[i][j][len], dp[i][j - 1][len - 1] + hor[i][j - 1]);
                }
                if (j + 1 < m) {
                    chkmin(dp[i][j][len], dp[i][j + 1][len - 1] + hor[i][j]);
                }
            }
        }
    }
    forn (i, 0, n) {
        forn (j, 0, m) {
            cout << dp[i][j][k] * 2 << " ";
        }
        cout << "\n";
    }
    return 0;
}