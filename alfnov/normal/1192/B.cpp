#include<bits/stdc++.h>
using namespace std;
vector<pair<int,long long>>g[100005];
long long dis[100005];
int fa[100005];
int ol[200005],gs=0;
int L[100005],R[100005];
void dfs(int x,int la){
	ol[++gs]=x,L[x]=R[x]=gs;
	for(auto pi:g[x]){
		int cu=pi.first;
		long long c2=pi.second;
		if(cu==la)continue;
		fa[cu]=x,dis[cu]=dis[x]+c2;
		dfs(cu,x);
		ol[++gs]=x,R[x]=gs;
	}
}
struct apple{
	long long M1,M2;
	long long Z1,Z2;
	long long QZ;
}sm[800005];
long long lz[800005];
apple operator+(apple a,apple b){
	apple c;
	c.M1=max(a.M1,b.M1);
	c.M2=min(a.M2,b.M2);
	c.Z1=max(max(a.Z1,b.Z1),a.M1-2*b.M2);
	c.Z2=max(max(a.Z2,b.Z2),b.M1-2*a.M2);
	c.QZ=max(max(a.QZ,b.QZ),max(a.Z1+b.M1,a.M1+b.Z2));
	return c;
}
void build(int l,int r,int o){
	if(l==r){
		long long zz=dis[ol[l]];
		sm[o].M1=sm[o].M2=zz;
		sm[o].Z1=sm[o].Z2=-zz;
		sm[o].QZ=0;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,o<<1);
	build(mid+1,r,o<<1|1);
	sm[o]=sm[o<<1]+sm[o<<1|1];
}
void pushdown(int o){
	if(!lz[o])return;
	sm[o<<1].M1+=lz[o],sm[o<<1].M2+=lz[o];
	sm[o<<1].Z1-=lz[o],sm[o<<1].Z2-=lz[o];
	sm[o<<1|1].M1+=lz[o],sm[o<<1|1].M2+=lz[o];
	sm[o<<1|1].Z1-=lz[o],sm[o<<1|1].Z2-=lz[o];
	lz[o<<1]+=lz[o],lz[o<<1|1]+=lz[o];
	lz[o]=0;
}
void add(int l,int r,int o,int ll,int rr,long long jz){
	if(l>=ll&&r<=rr){
		sm[o].M1+=jz,sm[o].M2+=jz;
		sm[o].Z1-=jz,sm[o].Z2-=jz;
		lz[o]+=jz;
		return;
	}
	pushdown(o);
	int mid=(l+r)>>1;
	if(mid>=ll)add(l,mid,o<<1,ll,rr,jz);
	if(mid<rr)add(mid+1,r,o<<1|1,ll,rr,jz);
	sm[o]=sm[o<<1]+sm[o<<1|1];
}
int U[100005],V[100005];
long long W[100005];
int main(){
	int n,q;
	long long w;
	scanf("%d%d%lld",&n,&q,&w);
	for(int i=1;i<n;++i){
		int u,v;
		long long w;
		scanf("%d%d%lld",&u,&v,&w);
		g[u].emplace_back(v,w);
		g[v].emplace_back(u,w);
		U[i]=u,V[i]=v,W[i]=w;
	}
	dfs(1,0);
	build(1,gs,1);
	long long lastans=0;
	while(q--){
		int d;
		long long e;
		scanf("%d%lld",&d,&e);
		d=(d+lastans)%(n-1)+1;
		e=(e+lastans)%w;
		int u=U[d],v=V[d];
		if(fa[v]==u)swap(u,v);
		long long jz=e-W[d];
		W[d]=e;
		add(1,gs,1,L[u],R[u],jz);
		lastans=sm[1].QZ;
		printf("%lld\n",lastans);
	}
	return 0;
}