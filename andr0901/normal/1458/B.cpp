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

constexpr int N = 205, INF = 1e8;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector <pii> a(n);
    forn (i, 0, n) {
        cin >> a[i].fs >> a[i].sc;
        a[i].fs *= 2, a[i].sc *= 2;
    }
    vector <vector <int>> odd(n + 2, vector <int> (N * N + N, -INF));
    vector <vector <int>> even(n + 2, vector <int> (N * N + N, -INF));
    even[0][0] = 0;
    forn (i, 0, n) {
        auto [cap, s] = a[i];
        if (i % 2 == 1) {
            forn (i, 0, n + 1) {
                forn (j, 0, N * N) {
                    chkmax(even[i + 1][j + s], odd[i][j] + cap);
                    chkmax(even[i][j + s / 2], odd[i][j]);
                }
            }
        } else {
            forn (i, 0, n + 1) {
                forn (j, 0, N * N) {
                    chkmax(odd[i + 1][j + s], even[i][j] + cap);
                    chkmax(odd[i][j + s / 2], even[i][j]);
                }
            }
        }
        /*forn (i, 0, n + 1)
            cerr << dp[i] << "\n";
        cerr << "---\n";*/
    }
    auto dp = (n % 2 ? odd : even);
    forn (i, 1, n + 1) {
        int ans = 0;
        forn (j, 0, N * N)
            chkmax(ans, min(dp[i][j], j));
        cout << 1.0 * ans / 2 << "\n";
    }
    return 0;
}