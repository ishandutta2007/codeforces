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
    map<pii, int> angle;
    forn (i, 0, n) {
        vector<int> cur(4);
        cin >> cur;
        cur[0] -= cur[2], cur[1] -= cur[3];
        int g = gcd(abs(cur[0]), abs(cur[1]));
        cur[0] /= g, cur[1] /= g;
        angle[{cur[0], cur[1]}]++;
    }
    long long ans = 0;
    for (auto [fs, sc] : angle) {
        int x = sc;
        int y = angle[{-fs.fs, -fs.sc}];
        ans += 1LL * x * y;
    }
    cout << ans / 2 << "\n";
    cerr << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}