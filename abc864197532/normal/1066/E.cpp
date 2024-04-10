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
const int mod = 998244353, abc = 864197532, N = 200005, K = 111;

lli pw[N];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    pw[0] = 1;
    for (int i = 1; i < N; ++i) pw[i] = (pw[i - 1] << 1) % mod;
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    reverse(all(s));
    while (s.length() < t.length()) s += '0';
    reverse(all(s));
    reverse(all(t));
    while (s.length() > t.length()) t += '0';
    reverse(all(t));
    n = s.length();
    lli ans = 0, now = 0;
    for (int i = 0; i < n; ++i) {
        now += t[i] == '1';
        if (s[i] == '1') (ans += pw[n - i - 1] * now) %= mod;
    }
    cout << ans << endl;
}