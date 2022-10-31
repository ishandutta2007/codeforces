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

vector <int> dx = {1, 0, -1, -1, 0, 1};
vector <int> dy = {1, 1, 0, -1, -1, 0};

pair <int, int> solve_equation(int a, int b, int c, int d, int e, int f) {
    if (a * e - d * b == 0 || a == 0)
        return {INT_MAX, INT_MAX};
    int y = (a * f - c * d) / (a * e - d * b);
    int x = (c - b * y) / a;
    return {x, y};
}

void solve() {
    int x, y;
    cin >> x >> y;
    vector <int> c(6);
    cin >> c;
    long long ans = 2e18;
    forn (i, 0, 6)
        forn (j, 0, 6)
            if (i != j) {
                auto [moves_i, moves_j] = solve_equation(dx[i], dx[j], x, dy[i], dy[j], y);
                if (moves_i != INT_MAX && moves_i >= 0 && moves_j >= 0) {
                    cerr << i << " " << j << ": " << moves_i << " " << moves_j << "\n";;
                    chkmin(ans, 1LL * moves_i * c[i] +
                                1LL * moves_j * c[j]);
                }
            }
    cerr << "kek ";
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