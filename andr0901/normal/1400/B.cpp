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
    int x, y;
    cin >> x >> y;
    int cnt_a, cnt_b;
    cin >> cnt_a >> cnt_b;
    int a, b;
    cin >> a >> b;
    if (a > b) {
        swap(a, b);
        swap(cnt_a, cnt_b);
    }
    int ans = 0;
    forn (i, 0, cnt_a + 1) {
        int rest_x = x - a * i;
        if (rest_x < 0)
            break;
        int j = (cnt_a - i);
        int rest_y = y - a * j;
        if (rest_y < 0)
            j = y / a;
        rest_y = y - a * j;
        int cur_b = min(cnt_b, rest_x / b + rest_y / b);
        chkmax(ans, i + j + cur_b);
    }
    cout << ans << "\n";
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}