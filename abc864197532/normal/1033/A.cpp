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
const int mod = 1e9 + 7, abc = 864197532, Doludu = 123, N = 1001, logN = 18;

bool vis[N][N];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b, --a, --b;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        if (i == a || j == b) vis[i][j] = true;
        if (i - j == a - b) vis[i][j] = true;
        if (i + j == a + b) vis[i][j] = true;
    }
    cin >> a >> b, --a, --b;
    queue <pii> q;
    q.emplace(a, b);
    vis[a][b] = true;
    while (!q.empty()) {
        tie(a, b) = q.front(); q.pop();
        for (int i = -1; i <= 1; ++i) for (int j = -1; j <= 1; ++j) {
            int na = a + i, nb = b + j;
            if (0 <= na && na < n && 0 <= nb && nb < n && !vis[na][nb]) {
                q.emplace(na, nb);
                vis[na][nb] = true;
            }
        }
    }
    cin >> a >> b, --a, --b;
    cout << (vis[a][b] ? "YES\n" : "NO\n");
}