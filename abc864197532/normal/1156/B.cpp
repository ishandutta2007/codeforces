#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define ld long double
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
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 200000, logN = 17, K = 350;

lli dp[10][18][1024], dp2[10][18][1024];

lli modpow(lli a, int b) {
	lli ans = 1;
	for (; b; b >>= 1, a = a * a % mod) {
		if (b & 1) ans = ans * a % mod;
	}
	return ans;
}

void solve() {
	string s;
	cin >> s;
	vector <int> ch, cnt(26, 0);
	sort(all(s));
	for (char c : s) {
		if (!cnt[c - 'a']) ch.pb(c - 'a');
		cnt[c - 'a']++;
	}
	sort(all(ch));
	string ans = "No answer";
	if (ch.size() == 1) {
		ans = s;
	} else if (ch.size() == 2) {
		if (ch[0] + 1 != ch[1]) ans = s;
	} else if (ch.size() == 3) {
		if (ch[0] + 1 != ch[1]) ans = string(cnt[ch[2]], 'a' + ch[2]) + string(cnt[ch[0]], 'a' + ch[0]) + string(cnt[ch[1]], 'a' + ch[1]);
		if (ch[1] + 1 != ch[2]) ans = string(cnt[ch[1]], 'a' + ch[1]) + string(cnt[ch[2]], 'a' + ch[2]) + string(cnt[ch[0]], 'a' + ch[0]);
	} else {
		while (true) {
			random_shuffle(all(ch));
			bool is = true;
			fop (i,0,ch.size() - 1) if (abs(ch[i] - ch[i + 1]) == 1) is = false;
			if (is) break;
		}
		ans = "";
		for (int i : ch) ans += string(cnt[i], 'a' + i);
	}
	cout << ans << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}