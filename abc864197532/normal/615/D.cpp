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
const int mod = 1e9 + 7, abc = 864197532, N = 200087, K = 111;

lli modpow(lli a, lli b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

lli cnt[N], pre[N], suf[N];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0, p; i < n; ++i) cin >> p, cnt[p]++;
    lli ans = 1;
    for (int i = 0; i < N; ++i) pre[i] = suf[i] = cnt[i] + 1;
    for (int i = 2; i < N; ++i) pre[i] = pre[i] * pre[i - 1] % (mod - 1);
    for (int i = N - 2; i >= 2; --i) suf[i] = suf[i] * suf[i + 1] % (mod - 1);
    for (int i = 2; i < N; ++i) if (cnt[i]) {
        ans = ans * modpow(i, (cnt[i] * (cnt[i] + 1) / 2) % (mod - 1) * pre[i - 1] % (mod - 1) * suf[i + 1] % (mod - 1)) % mod;
    }
    cout << ans << endl;
}