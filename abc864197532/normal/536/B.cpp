#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 2000, logN = 17, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    lli a[26];
    fop (i,0,26) a[i] = uniform_int_distribution<int>(1, x - 1)(rng);
	int n, q;
    string s;
    cin >> n >> q >> s;
    int m = s.length();
    string t = s;
    reverse(all(t));
    lli pre[m + 1], suf[m + 1], now = 1;
    pre[0] = suf[0] = 0;
    fop (i,1,m + 1) {
    	pre[i] = ((pre[i - 1] * x) + a[s[i - 1] - 'a']) % mod;
    	suf[i] = (suf[i - 1] + a[t[i - 1] - 'a'] * now) % mod;
    	now = now * x % mod;
	}
	now = 0;
	lli ans = 1;
	vector <int> cnt(n + 1, false);
	while (q--) {
		int x;
		cin >> x;
		if (now < x) {
			for (int i = x; i < x + m; ++i) cnt[i] = true;
			now = x + m - 1;
		} else {
			if (pre[now - x + 1] == suf[now - x + 1]) {
				for (int i = now + 1; i < x + m; ++i) cnt[i] = true;
				now = x + m - 1;
			} else {
				ans = 0;
			}
		}
	}
	fop (i,1,n + 1) if (!cnt[i]) ans = ans * 26 % mod;
	cout << ans << endl;
}