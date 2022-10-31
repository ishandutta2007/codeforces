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
    int n, x;
    cin >> n >> x;
    vector <int> a(n);
    cin >> a;
    vector <vector <int>> b(x);
    int s = 0;
    b[0].pb(0);
    forn (i, 1, n + 1) {
        s = (s + a[i - 1]) % x;
        b[s].pb(i);
    }
    int ans = -1;
    forn (i, 0, x) {
        int fs = -1;
        forn (j, 0, sz(b[i]))
            if (b[i][j] != j) {
                fs = j;
                break;
            }
        cerr << i << " " << fs << ": " << b[i] << "\n";
        if (fs != -1)
            chkmax(ans, b[i].back() - fs);
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