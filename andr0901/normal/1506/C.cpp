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
    string a, b;
    cin >> a >> b;
    int ans = 1e9;
    forn (l1, 0, sz(a)) {
        forn (r1, l1 - 1, sz(a)) {
            forn (l2, 0, sz(b)) {
                int r2 = r1 - l1 + l2;
                if (!(-1 <= r2 && r2 < sz(b))) {
                    continue;
                }
                cerr << l1 << " " << r1 << "  " << l2 << " " << r2 << "\n";
                bool equal = true;
                for (int i = l1, j = l2; i <= r1; ++i, ++j) {
                    if (a[i] != b[j]) {
                        equal = false;
                        break;
                    }
                }
                if (equal) {
                    cerr << "eq: " << l1 << " " << r1 << "  " << l2 << " " << r2 << "\n";
                    cerr << "\n";
                    chkmin(ans, sz(a) - (r1 - l1 + 1) +
                                sz(b) - (r2 - l2 + 1));
                }
            }
        }
    }
    cerr << "\n";
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