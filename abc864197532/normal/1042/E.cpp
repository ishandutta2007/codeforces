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
const int mod = 998244353, abc = 864197532, N = 402, logN = 17, K = 333, INF = 5e8;

struct pos {
    int x, y, val;
    bool operator < (const pos &o) const {
        return val < o.val;
    }
};

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <pos> v;
    for (int i = 0; i < n; ++i) {
        for (int j = 0, x; j < m; ++j) {
            cin >> x;
            v.pb({i, j, x});
        }
    }
    sort(all(v));
    n = v.size();
    vector<lli> dp(n, 0), sx = {0}, sy = {0}, sumx = {0}, sumy = {0}, pre = {0};
    for (int i = 0, j = 0; i < n; ++i) {
        sx.pb((sx.back() + v[i].x * v[i].x) % mod);
        sy.pb((sy.back() + v[i].y * v[i].y) % mod);
        sumx.pb((sumx.back() + v[i].x) % mod);
        sumy.pb((sumy.back() + v[i].y) % mod);
        for (; j < i && v[j].val < v[i].val; ++j);
        dp[i] = (pre[j] + sx[j] - sumx[j] * v[i].x * 2 + 1ll * v[i].x * v[i].x * j + sy[j] - sumy[j] * v[i].y * 2 + 1ll * v[i].y * v[i].y * j) % mod * modpow(j, mod - 2) % mod;
        if (dp[i] < 0) dp[i] += mod;
        pre.pb((pre.back() + dp[i]) % mod);
    }
    int r, c;
    cin >> r >> c, --r, --c;
    for (int i = 0; i < n; ++i) if (v[i].x == r && v[i].y == c) {
        cout << dp[i] << endl;
    }
}