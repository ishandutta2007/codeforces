#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=N<<1;
map<pair<int,int>,int>mp;
int ds[N],a[23][31],x[M],y[M],z[M],l[M],r[M],f[N],sz[N],s1[N],s2[N],t,qx[N],qy[N],u,v,w;
vector<int>e[N<<2];
int gf(int x){return f[x]==x?x:gf(f[x]);}
int gd(int x){return f[x]==x?0:ds[x]^gd(f[x]);}
void ins(int d,int x){for(int i=29;~i;--i)if(x&(1<<i)){if(!a[d][i]){a[d][i]=x;return;}x^=a[d][i];}}
int qry(int d,int x){for(int i=29;~i;--i)x=min(x,x^a[d][i]);return x;}
inline void mg(int x,int y,int z){if(sz[x]>sz[y])swap(x,y);f[x]=y,ds[x]=z,s1[++t]=x,s2[t]=sz[y],sz[y]+=sz[x];}
void upd(int k,int l,int r){
	if(u<=l&&r<=v){e[k].push_back(w);return;}
	int m=l+r>>1;
	if(u<=m)upd(k<<1,l,m);
	if(m<v)upd(k<<1|1,m+1,r);
}
void dfs(int k,int l,int r,int d){
	memcpy(a[d],a[d-1],124);
	int u,v,w,p,q,o=t;
	for(auto i:e[k]){
		p=gf(u=x[i]),q=gf(v=y[i]),w=gd(u)^gd(v)^z[i];
		if(p==q)ins(d,w);
		else mg(p,q,w);
	}
	if(l==r)printf("%d\n",qry(d,gd(qx[l])^gd(qy[l])));
	else{int m=l+r>>1;dfs(k<<1,l,m,++d),dfs(k<<1|1,m+1,r,d);}
	for(;t>o;--t)sz[f[u=s1[t]]]=s2[t],ds[f[u]=u]=0;
}
int main(){
	int n,m,q,i,j,k,t=0,c=0,o=0;
	for(scanf("%d%d",&n,&m),i=1;i<=n;++i)f[i]=i,sz[i]=1;
	while(m--)++c,scanf("%d%d%d",x+c,y+c,z+c),r[mp[{x[c],y[c]}]=c]=-2;
	for(scanf("%d",&q);q--;){
		scanf("%d%d%d",&i,&j,&k);
		if(i==1)x[++c]=j,y[c]=k,scanf("%d",z+c),l[c]=t,r[mp[{j,k}]=c]=-2;
		else if(i==2)r[mp[{j,k}]]=t-1,mp.erase({j,k});
		else qx[t]=j,qy[t++]=k;
	}
	for(--t,i=1;i<=c;++i)if(u=l[i],v=r[i]>-2?r[i]:t,u<=v)w=i,upd(1,0,t);
	dfs(1,0,t,1);
	return 0;
}