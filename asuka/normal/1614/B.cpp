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
int T, n, a[N], ord[N], x[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		int l = 0, r = 0;
		rep(i, 1, n) ord[i] = i;
		sort(ord + 1, ord + n + 1, [&](int u, int v) {
			return a[u] > a[v];
		});
		x[0] = 0;
		rep(i, 1, n) {
			if(i & 1) x[ord[i]] = ++r;
			else x[ord[i]] = --l;
		}
		ll ans = 0;
		rep(i, 1, n) ans += (ll) 2 * abs(x[i]) * a[i];
		printf("%lld\n", ans);
		rep(i, 0, n) printf("%d ", x[i]);
		printf("\n");
	}
	return 0;
}