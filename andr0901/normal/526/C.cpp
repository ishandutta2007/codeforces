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

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int c;
    vector <int> h(2);
    vector <int> w(2);
    cin >> c >> h >> w;
    auto get_by_x = [&](int x) {
        int y = (c - x * w[0]) / w[1];
        return x * h[0] + y * h[1];
    };
    auto get_by_y = [&](int y) {
        int x = (c - y * w[1]) / w[0];
        return x * h[0] + y * h[1];
    };
    const int INF = 1e7;
    int ans = 0;
    forn (i, 0, min(INF, c / w[0] + 1))
        chkmax(ans, get_by_x(i));
    forn (i, 0, min(INF, c / w[1] + 1))
        chkmax(ans, get_by_y(i));
    cout << ans;
    return 0;
}