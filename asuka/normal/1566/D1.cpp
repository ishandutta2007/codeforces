#include<bits/stdc++.h>
#define ll long long
#define N 305
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
int T, n, m, a[N * N], b[N * N], vis[N * N];
map<int, int> rk;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		rk.clear();
		scanf("%d%d", &n, &m);
		rep(i, 1, m) scanf("%d", &a[i]), b[i] = a[i];
		rep(i, 1, m) vis[i] = 0;
		sort(b + 1, b + m + 1);
		rep(i, 1, m) rk[a[i]] = upper_bound(b + 1, b + m + 1, a[i]) - b - 1;
		int ans = 0;
		rep(i, 1, m) {
			int p = rk[a[i]];
			rep(j, 1, p) ans += vis[j];
			vis[p] = 1;
			rk[a[i]]--;
		}
		printf("%d\n", ans);
	}
	return 0;
}