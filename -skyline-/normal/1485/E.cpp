#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n,a[200005],d[200005],mxd,l[200005],r[200005];
ll f[200005];
vector<int> v[200005],D[200005];
void dfs(int x,int y){
	D[d[x]=d[y]+1].pb(x);
	if(d[x]>mxd)mxd=d[x];
	l[d[x]]=min(l[d[x]],a[x]);
	r[d[x]]=max(r[d[x]],a[x]);
	for(int i=0;i<v[x].size();++i)if(v[x][i]!=y)dfs(v[x][i],x);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)v[i].clear(),D[i].clear(),l[i]=orz,r[i]=-orz;
		mxd=0;
		for(int i=2;i<=n;++i){
			int x;
			scanf("%d",&x);
			v[x].pb(i),v[i].pb(x);
		}
		for(int i=2;i<=n;++i)scanf("%d",a+i);
		dfs(1,0);
		for(int i=0;i<D[mxd].size();++i){
			int x=D[mxd][i];
			f[x]=max(r[mxd]-a[x],a[x]-l[mxd]);
		}
		for(int k=mxd-1;k;--k){
			ll L=-orz*1ll*orz,R=-orz*1ll*orz;
			for(int i=0;i<D[k].size();++i){
				int x=D[k][i];
				f[x]=-orz*1ll*orz;
				for(int j=0;j<v[x].size();++j){
					int y=v[x][j];
					if(d[y]<d[x]) continue;
					f[x]=max(f[x],f[y]);
				}
				L=max(L,f[x]-a[x]);
				R=max(R,f[x]+a[x]);
				f[x]+=max(r[k]-a[x],a[x]-l[k]);
			}
			for(int i=0;i<D[k].size();++i){
				int x=D[k][i];
				f[x]=max(f[x],max(L+a[x],R-a[x]));
			}
		}
		printf("%I64d\n",f[1]);
	}
    return 0;
}