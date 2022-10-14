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
const int mod = 1e9 + 7, abc = 864197532, N = 1000087, logN = 17, K = 333;

int pre[101][101][20];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, c;
    cin >> n >> q >> c;
    for (int i = 0, x, y, s; i < n; ++i) {
        cin >> x >> y >> s;
        for (int t = 0; t <= c; ++t) {
            pre[x][y][t] += s;
            s++;
            if (s > c) s = 0;
        }
    }
    for (int t = 0; t <= c; ++t) {
        for (int i = 1; i <= 100; ++i) {
            for (int j = 1; j <= 100; ++j) {
                pre[i][j][t] += pre[i - 1][j][t] + pre[i][j - 1][t] - pre[i - 1][j - 1][t];
            }
        }
    }
    while (q--) {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        t %= (c + 1);
        cout << pre[x2][y2][t] - pre[x1 - 1][y2][t] - pre[x2][y1 - 1][t] + pre[x1 - 1][y1 - 1][t] << endl;
    }
}