#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 1e9 + 7, abc = 864197532, N = 51, K = 111;

map <pii, bool> dp;
pii val[20];
int n, d;

bool solve(int x, int y) {
    if (x * x + y * y > d * d) return true;
    if (dp.count({x, y})) return dp[{x, y}];
    for (int i = 0; i < n; ++i) {
        if (!solve(x + val[i].X, y + val[i].Y)) {
            return dp[{x, y}] = true;
        }
    }
    return dp[{x, y}] = false;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, y;
    cin >> x >> y >> n >> d;
    for (int i = 0, a, b; i < n; ++i) {
        cin >> a >> b;
        val[i] = mp(a, b);
     }
    cout << (solve(x, y) ? "Anton" : "Dasha") << endl;
}