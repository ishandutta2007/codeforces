#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <iomanip>
#include <bitset>
#include <random>
#include <ctime>
#include <string_view>
 
using namespace std;
 
#define ll long long
#define fi first
#define se second
#define ld long double
#define pb emplace_back
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define mp make_pair
 
const int INF = 1e9 + 10;

struct Fenwick {
	vector<ll> f;

	Fenwick(int n) {
		f.resize(n);
	}

	void incr(int x, ll d) {
		for (; x < f.size(); x |= (x + 1)) f[x] += d;
	}
	
	ll get(int x) {
		ll ans = 0;
		for (; x >= 0; x = (x & (x + 1)) - 1) ans += f[x];
		return ans;
	}
	
	ll get(int l, int r) {
		return get(r) - get(l - 1);
	}
};

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> val(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		val[i] = a[i];
		a[i] = a[i] - i - 1;
	}
	vector<vector<int>> dp(n, vector<int>(2));
	vector<int> id(n, -1);
	int r = 0;
	ll ans = 0;
	ll sum_l = 0;
	for (int l = 0; l < n; l++) {
		if (r < l) r = l;
		while (r + 1 < n && a[r + 1] + l >= 0) r++;
		dp[l][0] = r;
		ans += r;
		ans -= (l - 1);
	}
	r = 0;
	int bad_id = -1;
	for (int l = 0; l < n; l++) {
		if (r < l) r = l;
		if (bad_id != -1) {
			if (a[bad_id] + l >= 0) bad_id = -1;
		}
		while (r + 1 < n) {
			if (a[r + 1] + l >= 0) r++;
			else if (bad_id == -1) bad_id = ++r;
			else break;
		}
		id[l] = bad_id;
		dp[l][1] = r;
	}
	vector<vector<pii>> b(n);
	for (int i = 0; i < n; i++) {
		if (id[i] != -1) {
			b[id[i]].pb(-(a[id[i]] + i), dp[i][1] - dp[i][0]);
		}
	}
	vector<vector<ll>> pr(n);
	for (auto &c : b) sort(all(c));
	for (int i = 0; i < n; i++) {
		pr[i].resize(b[i].size() + 1);
		for (int j = 0; j < b[i].size(); j++) {
			pr[i][j + 1] = pr[i][j] + b[i][j].se;
		}
	}
	int q;
	cin >> q;
	vector<ll> output(q, -1);
	vector<pair<pair<int, int>, int>> kek;
	for (int i = 0; i < q; i++) {
		int pos, x;
		cin >> pos >> x; pos--;
		int d = abs(val[pos] - x);
		ll ansd = 0;
		if (val[pos] < x) {
			auto ind = upper_bound(all(b[pos]), mp(d + 1, -1)) - b[pos].begin();
			ansd = pr[pos][ind];
			output[i] = ans + ansd;
		} else if (val[pos] > x) {
			kek.pb(mp(pos, x), i);
		} else {
			output[i] = ans;
		}
	}
	sort(all(kek));
	Fenwick sum(n);
	Fenwick cnt(n);
	reverse(all(kek));
	vector<pii> lol(n);
	for (int i = 0; i < n; i++) lol[i] = mp(dp[i][0], i);
	sort(all(lol));
	reverse(all(lol));
	int j = 0;
	for (auto &c : kek) {
		while (j < n && lol[j].fi >= c.fi.fi) {
			cnt.incr(lol[j].se, 1);
			sum.incr(lol[j].se, lol[j].fi);
			j++;
		}
		int pos = c.fi.fi;
		int x = c.fi.se;
		int d = x - val[pos];
		int lool = a[pos] + d;
		// l + lool < 0 - bad
		// l < -lool
		if (-lool <= 0) {
			output[c.se] = ans;
			continue;
		}
		output[c.se] = ans - sum.get(0, -lool - 1) + cnt.get(0, -lool - 1) * (pos - 1);
	}
	for (auto &c : output) cout << c << "\n";
}

int main()
{
	#ifdef LOCAL
		freopen("input", "r", stdin);
		freopen("output", "w", stdout);
	#else
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	#endif
	int t = 1;
	while (t--) solve();
	return 0;
}