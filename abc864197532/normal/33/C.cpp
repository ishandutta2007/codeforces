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
const int mod = 1e9 + 7, abc = 864197532, N = 5001, K = 111;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int val[n];
    for (int i = 0; i < n; ++i) cin >> val[i];
    int pre[n + 1], suf[n + 1];
    pre[0] = 0;
    for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + val[i - 1];
    int al = pre[n];
    for (int i = 1; i <= n; ++i) pre[i] = min(pre[i], pre[i - 1]);
    suf[n] = 0;
    for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + val[i];
    for (int i = n - 1; i >= 0; --i) suf[i] = min(suf[i], suf[i + 1]);
    int ans = al;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, al - (pre[i] + suf[i]) * 2);
    }
    cout << ans << endl;
}