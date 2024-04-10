#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
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
const int mod = 998244353, x = 864197532, N = 500001, logN = 17;


int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector <bool> is(n, false);
    fop (i,0,n) {
    	if (s[i] != s[(i + n - 1) % n] && s[i] != s[(i + 1) % n]) {
    		is[i] = true;
		}
	}
	if (accumulate(all(is), 0) == n) {
		int ro = k & 1;
		if (ro) {
			fop (i,0,n) s[i] = 'B' + 'W' - s[i];
		}
		cout << s << endl;
		return 0;
	}
	vector <vector <int>> seg;
	for (int l = 0; l < n;) {
		if (!is[l]) {
			l++;
		} else {
			int r = l + 1;
			while (r < n && is[r]) r++;
			vector <int> tmp;
			for (int i = l; i < r; ++i) tmp.pb(i);
			seg.pb(tmp);
			l = r;
		}
	}
	if (is[0] && is[n - 1] && seg.size() > 1) {
		vector <int> tmp;
		for (int i : seg.back()) {
			tmp.pb(i);
		}
		for (int i : seg[0]) {
			tmp.pb(i);
		}
		seg.pop_back();
		seg[0] = tmp;
	}
	/*
	WBWBWBW
	WWBWBWW
	WWWBWWW
	1 2 3 4 5 
	*/
	for (auto v : seg) {
		int cur = 0, now = 1, l = 0, r = v.size() - 1;
		while (l <= r && cur++ < k) {
			if (now) {
				s[v[l]] = 'B' + 'W' - s[v[l]];
				if (l != r) s[v[r]] = 'B' + 'W' - s[v[r]];
			}
			l++;
			r--;
			now ^= 1;
		}
		if (!now) {
			fop (i,l,r+1) s[v[i]] = 'B' + 'W' - s[v[i]];
		}
	}
	cout << s << endl;
}