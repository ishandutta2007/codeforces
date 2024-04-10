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
    int n, m;
    cin >> n >> m;
    vector<string> ans(n, string(m, '0'));
    if (n % 2 && m % 2) {
        for (int i = 0; i < n; i += 2) {
            ans[i][0] = ans[i][m - 1] = '1';
        }
        for (int i = 0; i < m; i += 2) {
            ans[0][i] = ans[n - 1][i] = '1';
        }
    } else if (n % 2 == 0 && m % 2 == 0) {
        for (int i = 2; i < n; i += 2) {
            ans[i][0] = '1';
        }
        for (int i = 1; i < n - 1; i += 2) {
            ans[i][m - 1] = '1';
        }

        for (int i = 1; i < m - 1; i += 2) {
            ans[0][i] = '1';
        }
        for (int i = 2; i < m; i += 2) {
            ans[n - 1][i] = '1';
        }
    } else if (n % 2 == 1 && m % 2 == 0) {
        for (int i = 2; i < n; i += 2) {
            ans[i][0] = '1';
        }
        for (int i = 0; i < n - 1; i += 2) {
            ans[i][m - 1] = '1';
        }

        for (int i = 1; i < m; i += 2) {
            ans[0][i] = '1';
        }
        for (int i = 0; i < m; i += 2) {
            ans[n - 1][i] = '1';
        }
    } else if (n % 2 == 0 && m % 2 == 1) {
        swap(n, m);
        ans = vector<string>(n, string(m, '0'));
        for (int i = 2; i < n; i += 2) {
            ans[i][0] = '1';
        }
        for (int i = 0; i < n - 1; i += 2) {
            ans[i][m - 1] = '1';
        }

        for (int i = 1; i < m; i += 2) {
            ans[0][i] = '1';
        }
        for (int i = 0; i < m; i += 2) {
            ans[n - 1][i] = '1';
        }

        swap(n, m);
        vector<string> real_ans(n, string(m, '0'));
        forn (i, 0, n) {
            forn (j, 0, m) {
                real_ans[i][j] = ans[j][i];
            }
        }
        swap(ans, real_ans);
    }
    forn (i, 0, n) {
        cout << ans[i] << "\n";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}