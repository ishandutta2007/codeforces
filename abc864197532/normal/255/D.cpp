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
const int mod = 1e9 + 7, abc = 864197532, N = 100001, K = 111;

lli ask(lli x, lli y, lli t, lli n) {
    lli ans = t * (t + 1) / 2 * 4 + 1;
    if (x + t - 1 >= n) {
        lli a = x + t - n;
        ans -= a * a;
    }
    if (x - t <= 0) {
        lli a = t - x + 1;
        ans -= a * a;
    }
    if (y + t - 1 >= n) {
        lli a = y + t - n;
        ans -= a * a;
    }
    if (y - t <= 0) {
        lli a = t - y + 1;
        ans -= a * a;
    }
    lli cur = x + y + t;
    if (cur >= 2 * n + 2) {
        lli a = cur - 2 * n - 2 + 1;
        ans += a * (a + 1) / 2;
    }
    x = n + 1 - x;
    cur = x + y + t;
    if (cur >= 2 * n + 2) {
        lli a = cur - 2 * n - 2 + 1;
        ans += a * (a + 1) / 2;
    }
    y = n + 1 - y;
    cur = x + y + t;
    if (cur >= 2 * n + 2) {
        lli a = cur - 2 * n - 2 + 1;
        ans += a * (a + 1) / 2;
    }
    x = n + 1 - x;
    cur = x + y + t;
    if (cur >= 2 * n + 2) {
        lli a = cur - 2 * n - 2 + 1;
        ans += a * (a + 1) / 2;
    }
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    lli n, x, y, c;
    cin >> n >> x >> y >> c;
    lli l = -1, r = n * 2;
    while (r - l > 1) {
        lli mid = l + r >> 1;
        if (ask(x, y, mid, n) < c) l = mid;
        else r = mid;
    }
    cout << r << endl;
}