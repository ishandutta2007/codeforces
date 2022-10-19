#include<bits/stdc++.h>
#define int long long
#define N 200015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
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
int n,m,k,s;
int val[3][N],t[N],c[N],Min[3][N],id[3][N];
VI cost;
vector<pair<int,pair<int,int> > > a;
bool check(int d){
	cost.clear();
	int res = 0;
	rep(i,1,m) cost.pb(Min[t[i]][d]*c[i]);
	sort(all(cost));
	rep(i,1,k) res += cost[i-1];
	return res <= s;
}
void getans(int d){
	printf("%lld\n",d);
	rep(i,1,m) a.pb(mp(Min[t[i]][d]*c[i],mp(i,id[t[i]][d])));
	sort(all(a));
	rep(i,1,k) printf("%lld %lld\n",a[i-1].se.fi,a[i-1].se.se);
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld%lld%lld%lld",&n,&m,&k,&s);
 	memset(Min,0x3f,sizeof Min);
 	rep(i,1,n) scanf("%lld",&val[1][i]),id[1][i] = Min[1][i-1] < val[1][i] ? id[1][i-1] : i,Min[1][i] = min(Min[1][i-1],val[1][i]);
 	rep(i,1,n) scanf("%lld",&val[2][i]),id[2][i] = Min[2][i-1] < val[2][i] ? id[2][i-1] : i,Min[2][i] = min(Min[2][i-1],val[2][i]);
 	rep(i,1,m) scanf("%lld%lld",&t[i],&c[i]);
 	if(!check(n)) return puts("-1"),0;
 	int l = 1,r = n,ans = 0;
 	while(l <= r){
 		int mid = (l+r)>>1;
 		if(check(mid)) ans = mid,r = mid-1;
 		else l = mid+1;
 	}
 	getans(ans);
	return 0;
}