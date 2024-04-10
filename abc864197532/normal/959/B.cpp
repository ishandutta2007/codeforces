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
const int mod = 1e9 + 7, abc = 864197532, N = 3000005, logN = 20, K = 333;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    map <string, int> m1;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        m1[s] = i;
    }
    vector <int> a(n), rt(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0, sz, x; i < m; ++i) {
        cin >> sz >> x, --x;
        rt[x] = x;
        for (int j = 1, y; j < sz; ++j) {
            cin >> y, --y;
            rt[y] = x;
            a[x] = min(a[x], a[y]);
        }
    }
    lli ans = 0;
    for (int i = 0; i < k; ++i) {
        cin >> s;
        ans += a[rt[m1[s]]];
    }
    cout << ans << endl;
}