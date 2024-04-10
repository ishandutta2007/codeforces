#include<bits/stdc++.h>
using namespace std;
#define _(a,b) if(j>k)swap(j,k);\
if(o==1){\
if(!mp[{j,k}])w=mp[{j,k}]=++t,ex[t]=j,ey[t]=k;\
else w=mp[{j,k}],u=ti[w],v=i,upd(1,1,m);\
(a)[i]=w,ti[w]=i+1;\
}else (a)[i]=j,(b)[i]=k;
const int N=2e5+3,M=N*2;
map<pair<int,int>,int>mp;
using ar=int[N];
ar st,sz,f,fi,fy,se,sy;
int las,u,v,w,t,ex[M],ey[M],ti[M];
bool vis[M];
vector<int>e[N*4];
int gf(int x){return f[x]==x?x:gf(f[x]);}
void upd(int k,int l,int r){
	if(u<=l&&r<=v)return e[k].push_back(w);
	int m=l+r>>1;
	if(u<=m)upd(k*2,l,m);
	if(m<v)upd(k*2+1,m+1,r);
}
void wk(int x,int l,int r){
	int o=t,j,k;
	for(int i:e[x])if(vis[i]){
		j=gf(ex[i]),k=gf(ey[i]);
		if(j!=k){
			if(sz[j]>sz[k])swap(j,k);
			sz[k]+=sz[j],f[j]=k,st[++t]=j;
		}
	}
	if(l==r){
		if(fy[l])printf("%d",las=las?gf(se[l])==gf(sy[l]):gf(fi[l])==gf(fy[l]));
		else if(las)vis[se[l]]^=1;else vis[fi[l]]^=1;
	}else{
		int m=l+r>>1;
		wk(x*2,l,m),wk(x*2+1,m+1,r);
	}
	for(;t>o;)j=st[t--],sz[f[j]]-=sz[j],f[j]=j;
}
int main(){
	int n,m,i,j,k,o,t=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)f[i]=i,sz[i]=1;
	for(i=1;i<=m;++i){
		scanf("%d%d%d",&o,&j,&k);
		_(fi,fy)
		j=j%n+1,k=k%n+1;
		_(se,sy)
	}
	for(i=1;i<=t;++i)if(ti[i]<=m)u=ti[i],v=m,w=i,upd(1,1,m);
	wk(1,1,m);
	return 0;
}