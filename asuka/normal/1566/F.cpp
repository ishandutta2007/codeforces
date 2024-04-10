#include<bits/stdc++.h>
#define int long long
#define N 400015
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
int T, n, m, a[N], dp[N][2];
struct node{
	int l, r, typ;
};
vector<node> vec, stk;
bool incl(node u, node v) {
	return u.l <= v.l && v.r <= u.r;
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld", &T);
	while(T--) {
		vec.clear();
		stk.clear();
		scanf("%lld%lld", &n, &m);
		rep(i, 1, n) scanf("%lld", &a[i]), vec.pb((node){a[i], a[i], 1});
		rep(i, 1, m) {
			int l, r;
			scanf("%lld%lld", &l, &r);
			vec.pb((node){l, r, 0});
		}
		sort(all(vec), [&](node u, node v) {return u.l != v.l ? u.l < v.l : u.r != v.r ? u.r > v.r : u.typ < v.typ;});
		for(auto x : vec) {
			while(SZ(stk) > 0 && incl(stk.back(), x)) stk.pop_back();
			stk.pb(x);
		}
		// for(auto x : stk) printf("%lld %lld\n", x.l, x.r);
		rep(i, 0, SZ(stk)) dp[i][0] = dp[i][1] = infll;
		dp[0][0] = dp[0][1] = 0;
		rep(i, 1, SZ(stk)) {
			if(stk[i - 1].typ == 0) {
				// printf("qj %lld, %lld\n", stk[i - 1].l, stk[i - 1].r);
				// printf("%lld\n", dp[i][0]);
				continue;
			}
			// <- ->
			per(j, 1, i) {
				if(j != i && stk[j - 1].typ == 1) break;
				dp[i][0] = min(dp[i][0], min(dp[j - 1][0], dp[j - 1][1]) + 2 * (stk[i - 1].l - stk[j - 1].r));
				dp[i][1] = min(dp[i][1], min(dp[j - 1][0], dp[j - 1][1]) + (stk[i - 1].l - stk[j - 1].r));
			}
			// printf("CUR %lld\n", stk[i - 1].l);
			// printf("%lld %lld\n", dp[i][0], dp[i][1]);
			// -> <-
			rep(j, i + 1, SZ(stk)) {
				if(stk[j - 1].typ == 1) break;
				dp[j][0] = min(dp[j][0], dp[i][0] + (stk[j - 1].l - stk[i - 1].r));
				dp[j][0] = min(dp[j][0], dp[i][1] + 2 * (stk[j - 1].l - stk[i - 1].r));
			}
		}
		printf("%lld\n", min(dp[SZ(stk)][0], dp[SZ(stk)][1]));
	}
	return 0;
}