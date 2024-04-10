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

int cost(int x, int y) {
    return  (((x >> 2) & 1) != (((y >> 2) & 1))) +
            (((x >> 1) & 1) != (((y >> 1) & 1))) + 
            ((x & 1) != (y & 1));
}

int count(int x) {
    return __builtin_popcount(x);
}

int count_two(int x) {
    return count(x) - ((x >> 2) & 1);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <char>> a(n, vector <char> (m));
    cin >> a;
    if (n > m) {
        swap(n, m);
        vector <vector <char>> b(n, vector <char> (m));
        forn (i, 0, n)
            forn (j, 0, m)
                b[i][j] = a[j][i];
        a = b;
    }
    if (n > 3)
        return cout << -1, 0;
    if (n == 1)
        return cout << 0, 0;
    forn (i, 0, n)
        forn (j, 0, m)
            a[i][j] -= '0';
    if (n == 2) {
        vector <vector <int>> dp(m + 1, vector <int> (4, 1e9));
        dp[0][0] = 0;
        forn (i, 0, m) {
            int cur = (a[0][i] << 1) + a[1][i];
            forn (j, 0, 4) {
                forn (k, 0, 4) {
                    if (!i || (count(j) + count(k)) % 2)
                        chkmin(dp[i + 1][k],
                               dp[i][j] + cost(cur, k));
                }
            }
            cerr << dp[i] << "\n";
        }
        cout << *min_element(all(dp[m]));
        return 0;
    }
    if (n == 3) {
        vector <vector <int>> dp(m + 1, vector <int> (8, 1e9));
        dp[0][0] = 0;
        forn (i, 0, m) {
            int cur = (a[0][i] << 2) + (a[1][i] << 1) + a[2][i];
            forn (j, 0, 8) {
                forn (k, 0, 8) {
                    if (!i || (count(j >> 1) + count(k >> 1)) % 2 &&
                        (count_two(j) + count_two(k)) % 2)
                        chkmin(dp[i + 1][k],
                               dp[i][j] + cost(cur, k));
                }
            }
            cerr << dp[i] << "\n";
        }
        cout << *min_element(all(dp[m]));
        return 0;
    }
    return 0;
}