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

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, len = n;
    cin >> n >> m;
    for (int i = 0, l, r; i < m; ++i) {
        cin >> l >> r, l--;
        len = min(len, r - l);
    }
    cout << len << endl;
    for (int i = 0; i < n; ++i) {
        cout << i % len << ' ';
    }
    cout << endl;
}