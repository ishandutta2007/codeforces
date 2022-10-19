#include<bits/stdc++.h>
#define ll long long
#define N 200015
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
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
const int mod = 1e9 + 7;
int n, l[N], r[N], p[N], val[N];
bool is[N];
namespace fenwick {
	int D[N << 1];
	void add(int p, int v) {for(; p <= (n << 1); p += lowbit(p)) (D[p] += v) %= mod;}
	int query(int p) {int res = 0; for(; p; p -= lowbit(p)) (res += D[p]) %= mod; return res;}
}
using namespace fenwick;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d%d", &l[i], &r[i]);
	rep(i, 1, n) p[i] = i;
	sort(p + 1, p + n + 1, [&](int u, int v) {
		return r[u] < r[v];
	});
	int t, tt;
	scanf("%d", &t);
	rep(i, 1, t) scanf("%d", &tt), is[tt] = 1;
	rep(i, 1, n) {
		int u = p[i];
		val[u] = (query(r[u]) + mod - query(l[u]) + 1) % mod;
		add(l[u], val[u]);
	}
	int L = 1, ans = 0;
	per(i, 1, n) {
		int u = p[i];
		if(is[u] && L <= l[u]) {
			(ans += (query(l[u]) - query(L - 1) + mod) % mod) %= mod;
			L = l[u] + 1;
		}
		add(l[u], mod - val[u]);
	}
	printf("%d\n", ans);
	return 0;
}