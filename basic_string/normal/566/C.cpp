#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
vector<pair<int,int>>e[N];
int o,r,w[N],sz[N],t,n;
double ft=1e99,nf,d[N];
bool b[N];
void gr(int x,int y){
	sz[x]=1;
	int i,j=0;
	for(auto o:e[x])if(!b[i=o.first]&&i!=y)gr(i,x),sz[x]+=sz[i],j=max(j,sz[i]);
	if((j=max(j,n-sz[x]))<o)o=j,r=x;
}
void dfs(int x,int y,int z){
	nf+=(d[x]=sqrt(z)*w[x])*z;
	for(auto o:e[x])if(o.first^y)dfs(o.first,x,z+o.second),d[x]+=d[o.first];
}
void wk(int x){
	o=N,gr(x,0),b[r]=1,nf=0,dfs(r,0,0);
	if(nf<ft)ft=nf,t=r;
	int i;
	for(auto o:e[r])if(!b[i=o.first]&&d[r]-2*d[i]<0){
		n=sz[i]<sz[r]?sz[i]:n-sz[r],wk(i);
		break;
	}
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int i,j,k,l;
	for(cin>>n,i=1;i<=n;++i)cin>>w[i];
	for(i=1;i<n;++i)cin>>j>>k>>l,e[j].push_back({k,l}),e[k].push_back({j,l});
	wk(1),cout<<t<<' '<<setprecision(9)<<ft;
	return 0;
}