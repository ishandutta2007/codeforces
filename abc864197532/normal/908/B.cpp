#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl;
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
const int mod = 1e9 + 7, abc = 864197532, N = 100087, logN = 17, K = 333;

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; ++i) cin >> s[i];
    vector <int> p(4);
    iota(all(p), 0);
    string t;
    cin >> t;
    int ans = 0;
    do {
        int x, y;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (s[i][j] == 'S') x = i, y = j;
            }
        }
        bool is = false;
        for (char c : t) {
            x += dx[p[c - '0']];
            y += dy[p[c - '0']];
            if (x >= n || x < 0 || y >= m || y < 0) {is = false; break;}
            if (s[x][y] == '#') {is = false; break;}
            if (s[x][y] == 'E') {is = true; break;}
        }
        ans += is;
    } while (next_permutation(all(p)));
    cout << ans << endl;
}