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

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<int> b(n), c(n);
    cin >> b >> c;
    long long ans = 0, cur_len = 0;
    forn (i, 1, n) {
        if (b[i] > c[i])
            swap(b[i], c[i]);
        if (b[i] == c[i]) {
            cur_len = 2;
        } else {
            if (i == 1) {
                cur_len = 2 + c[i] - b[i];
            } else {
                cur_len += b[i] - 1;
                cur_len += a[i - 1] - c[i];
                cur_len += 2;
                chkmax(cur_len, c[i] - b[i] + 2);
            }
        }
        chkmax(ans, cur_len + a[i] - 1);
        cerr << cur_len << "\n";
    }
    cerr << "\n";
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}