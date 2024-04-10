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
    int n, u, r, d, l;
    cin >> n >> u >> r >> d >> l;
    forn (mask, 0, 1 << 4) {
        int ur = ((mask >> 0) & 1);
        int rd = ((mask >> 1) & 1);
        int dl = ((mask >> 2) & 1);
        int lu = ((mask >> 3) & 1);
        int cur_u = u - lu - ur;
        int cur_r = r - ur - rd;
        int cur_d = d - rd - dl;
        int cur_l = l - dl - lu;
        if (0 <= cur_u && cur_u <= n - 2 &&
            0 <= cur_r && cur_r <= n - 2 &&
            0 <= cur_d && cur_d <= n - 2 &&
            0 <= cur_l && cur_l <= n - 2) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}