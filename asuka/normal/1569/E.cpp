#include<bits/stdc++.h>
#define ll long long
#define N
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
#define per(i,a,n) for(int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int mod = 998244353;
int k, A, h, pd[114];
map<int, VI> ok[2];
void dfs(VI ans, VI cur, int rnk, bool flag) {
	if (SZ(cur) == 1) {
		if(rnk == 2) dfs(ans, cur, 1, flag);
		ans[cur[0]] = rnk;
		int val = 0;
		rep(i, 1, (1 << k)) if(ans[i]) (val += (ll) i * pd[ans[i]] % mod) %= mod;
		if (!flag) ok[rnk - 1][val] = ans;
		else {
			int need = (h - val + mod) % mod;
			if (ok[(rnk - 1) ^ 1].count(need) > 0) {
				VI tmp = ok[(rnk - 1) ^ 1][need];
				rep(i, 1, (1 << k)) cout << max(tmp[i], ans[i]) << ' ';
				exit(0);
			}
		}
		return;
	} else {
		int len = SZ(cur) / 2;
		rep(mask, 0, (1 << len) - 1) {
			VI nxt = ans, tmp;
			rep(i, 0, len - 1) {
				int a = cur[i << 1], b = cur[i << 1 | 1];
				if(mask >> i & 1) swap(a, b);
				nxt[a] = rnk;
				tmp.pb(b);
			}
			dfs(nxt, tmp, (rnk + 1) / 2, flag);
		}
	}
}
int main() {
	//freopen(".in","r",stdin);
	// freopen("data.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> k >> A >> h;
	pd[0] = 1;
	rep(i, 1, 32) pd[i] = (ll) pd[i - 1] * A % mod;
	VI emp, ori;
	emp.resize(33);
	rep(i, 1, (1 << (k - 1))) ori.pb(i);
	dfs(emp, ori, (1 << (k - 1)) + 1, 0);
	ori.clear();
	rep(i, 1, (1 << (k - 1))) ori.pb(i + (1 << (k - 1)));
	dfs(emp, ori, (1 << (k - 1)) + 1, 1);
	puts("-1");
	return 0;
}