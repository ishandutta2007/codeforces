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
    vector <vector <int>> a(n, vector <int> (m));
    cin >> a;
    long long ans = 0;
    for (int i = 0, j = n - 1; i <= j; ++i, --j)
        for (int k = 0, l = m - 1; k <= l; ++k, --l) {
            vector <int> vals = {a[i][k]};
            if (i != j)
                vals.pb(a[j][k]);
            if (k != l) {
                vals.pb(a[i][l]);
                if (i != j)
                    vals.pb(a[j][l]);
            }
            cerr << sz(vals) << " ";
            long long mn = 1e18;
            forn (i, 0, sz(vals)) {
                long long cnt = 0;
                forn (j, 0, sz(vals))
                    cnt += abs(vals[i] - vals[j]);
                chkmin(mn, cnt);
            }
            ans += mn;
        }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}