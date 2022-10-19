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
int t, n, k, a[N], ans[N];
VI cnt[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &k);
		VI vec;
		rep(i, 1, n) cnt[i].clear(), ans[i] = 0;
		rep(i, 1, n) scanf("%d", &a[i]), cnt[a[i]].pb(i);
		rep(i, 1, n) if(SZ(cnt[i]) >= k) {
			rep(j, 1, k) {
				ans[cnt[i][j - 1]] = j;
			}
		} else {
			rep(j, 1, SZ(cnt[i])) vec.pb(cnt[i][j - 1]);
		}
		int tot = (SZ(vec) / k) * k;
		rep(i, 0, tot - 1) ans[vec[i]] = (i + 1) % k + 1;
		rep(i, 1, n) printf("%d ", ans[i]); printf("\n");
	}
	return 0;
}