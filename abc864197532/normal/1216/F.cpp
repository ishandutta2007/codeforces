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

struct Seg {
    int l, r, m;
    lli mn;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), mn(1ll << 60) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
    }
    void pull() {mn = min(ch[0]->mn, ch[1]->mn);}
    void set(int p, lli v) {
        if (r - l == 1) mn = v;
        else ch[p >= m]->set(p, v), pull();
    }
    lli query(int a, int b) {
        if (a <= l && r <= b) return mn;
        lli ans = 1ll << 60;
        if (a < m) ans = min(ans, ch[0]->query(a, b));
        if (m < b) ans = min(ans, ch[1]->query(a, b));
        return ans;
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    string s;
    cin >> n >> k >> s;
    s = "$" + s;
    vector <lli> dp(n + 1, 1ll << 60);
    dp[0] = 0;
    vector <pii> range[n + 1];
    for (int i = 1; i <= n; ++i) if (s[i] == '1') {
        int l = max(1, i - k) - 1, r = min(i + k, n);
        range[r].eb(l, i);
    }
    Seg root(0, n + 1);
    root.set(0, 0);
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + i;
        for (pii a : range[i]) {
            dp[i] = min(dp[i], a.Y + root.query(a.X, i));
        }
        root.set(i, dp[i]);
    }
    cout << dp[n] << endl;
}