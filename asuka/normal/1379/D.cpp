#include<bits/stdc++.h>
#define ll long long
#define N
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
int n,h,m,k;
int ans,tim;
VI res;
vector<pii> ele;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d%d",&n,&h,&m,&k);
	rep(i,1,n){
		int u,v; scanf("%d%d",&u,&v);
		if(v >= m/2) v -= m/2;
		ele.pb(mp(v,i));
		ele.pb(mp(v+m/2,i));
	}
	sort(all(ele));
	// for(auto x:ele) printf("%d ",x.fi);
		// printf("\n");
	int l = -1; ans = inf;
	rep(r,0,SZ(ele)-1){
		if(ele[r].fi < k) continue;
		while(ele[r].fi - k >= ele[l+1].fi && l+1 < r) l++;
		// printf("%d %d\n",l,r);
		if(r-l-1 < ans) ans = r-l-1,tim = ele[r].fi;
	}
	for(auto v:ele){
		if(tim-k < v.fi && v.fi < tim) res.pb(v.se);
	}
	printf("%d %d\n",ans,tim%(m/2));
	for(auto u:res) printf("%d ",u);
	return 0;
}