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
const int mod = 1e9 + 7, x = 864197532, N = 1000087, logN = 17;

struct trie {
	trie* ch[2] = {NULL, NULL};
	int sz = 0;
	void insert(lli v, int d = 40) {
		sz++;
		if (d < 0) return;
		bool f = v & (1ll << d);
		if (!ch[f]) ch[f] = new trie();
		ch[f]->insert(v, d - 1);
	}
	void erase(lli v, int d = 40) {
		sz--;
		if (d < 0) return;
		bool f = v & (1ll << d);
		ch[f]->erase(v, d - 1);
	}
	lli queryMax(lli v, int d = 40) {
		if (d < 0) return 0;
		bool f = v & (1ll << d);
		if (ch[!f] && ch[!f]->sz > 0) return ch[!f]->queryMax(v, d - 1) ^ (1ll << d);
		return ch[f]->queryMax(v, d - 1);
	}
};

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	lli a[n];
	fop (i,0,n) cin >> a[i];
	trie T;
	T.insert(0);
	lli pre = 0, ans = 0, cur = 0;
	fop (i,0,n) {
		pre ^= a[i];
		T.insert(pre);
		ans = max(ans, pre);
	}
	FOP (i,n,0) {
		T.erase(pre);
		cur ^= a[i];
		ans = max(ans, T.queryMax(cur));
		pre ^= a[i];
	}
	cout << ans << endl;
}