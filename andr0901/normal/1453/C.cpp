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
    int n;
    cin >> n;
    vector <string> a(n);
    cin >> a;
    vector <vector <vector <int>>> r(10, vector <vector <int>> (n)), c(10, vector <vector <int>> (n));
    vector <int> mx_x(10, -1), mx_y(10, -1), mn_x(10, 1e9), mn_y(10, 1e9);
    forn (i, 0, n) {
        forn (j, 0, n) {
            a[i][j] -= '0';
            r[a[i][j]][i].pb(j);
            c[a[i][j]][j].pb(i);
            chkmin(mn_x[a[i][j]], i);
            chkmax(mx_x[a[i][j]], i);
            chkmin(mn_y[a[i][j]], j);
            chkmax(mx_y[a[i][j]], j);
        }
    }
    forn (i, 0, 10) {
        int ans = 0;
        forn (j, 0, n) {
            if (r[i][j].size() > 0) { 
                chkmax(ans, (r[i][j].back() - r[i][j][0]) * max(j, n - 1 - j));           
                chkmax(ans, max(r[i][j].back(), n - 1 - r[i][j][0]) * max(abs(j - mn_x[i]), abs(j - mx_x[i])));
            }
            if (c[i][j].size() > 0) { 
                chkmax(ans, (c[i][j].back() - c[i][j][0]) * max(j, n - 1 - j));           
                chkmax(ans, max(c[i][j].back(), n - 1 - c[i][j][0]) * max(abs(j - mn_y[i]), abs(j - mx_y[i])));
            }
        }
        cout << ans << " ";
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