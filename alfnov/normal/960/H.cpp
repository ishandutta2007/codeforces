#include<bits/stdc++.h>
#define A 5000000
#define double long double
#define int long long
using namespace std;
struct apple{
	int gs;
	long long S1,S2;
}sm[A+5];
int ls[A+5],rs[A+5],lz[A+5],zl[A+5];
apple operator*(apple a,int x){
	apple b=a;
	b.S2+=2*b.S1*x+b.gs*x*x;
	b.S1+=b.gs*x;
	return b;
}
void operator*=(apple &a,int x){
	a=a*x;
}
apple operator+(apple a,apple b){
	apple c;
	c.gs=a.gs+b.gs;
	c.S1=a.S1+b.S1;
	c.S2=a.S2+b.S2;
	return c;
}
int cs[50005],b[50005];
vector<int>g[50005];
int id[50005],tot=0;
int build(int l,int r,int zz){
	++tot;
	sm[tot].gs=r-l+1;
	sm[tot].S1=sm[tot].S2=0;
	sm[tot]*=zz;
	zl[tot]=zz;
	return tot;
}
void pushdown(int l,int r,int o){
	if(!lz[o])return;
	if(ls[o])sm[ls[o]]*=lz[o],lz[ls[o]]+=lz[o],zl[ls[o]]+=lz[o];
	if(rs[o])sm[rs[o]]*=lz[o],lz[rs[o]]+=lz[o],zl[rs[o]]+=lz[o];
	lz[o]=0;
}
void add(int l,int r,int o,int ll,int rr,int v){
	if(l>=ll&&r<=rr){
		sm[o]=sm[o]*v,lz[o]+=v,zl[o]+=v;
		return;
	}
	pushdown(l,r,o);
	int mid=(l+r)>>1;
	if(mid>=ll&&!ls[o])ls[o]=build(l,mid,zl[o]);
	if(mid<rr&&!rs[o])rs[o]=build(mid+1,r,zl[o]);
	if(mid>=ll)add(l,mid,ls[o],ll,rr,v);
	if(mid<rr)add(mid+1,r,rs[o],ll,rr,v);
	if(ls[o]&&rs[o])sm[o]=sm[ls[o]]+sm[rs[o]];
	else if(ls[o]){
		apple zz;
		zz.gs=r-mid,zz.S1=zz.S2=0;
		zz*=zl[o];
		sm[o]=sm[ls[o]]+zz;
	}
	else if(rs[o]){
		apple zz;
		zz.gs=mid-l+1,zz.S1=zz.S2=0;
		zz*=zl[o];
		sm[o]=zz+sm[rs[o]];
	}
}
int fa[50005],ffa[50005],dep[50005],sz[50005],bg[50005],gb[50005],tt=0;
void dfs1(int x){
	sz[x]=1;
	for(auto cu:g[x]){
		dep[cu]=dep[x]+1;
		dfs1(cu);
		fa[cu]=x,sz[x]+=sz[cu];
	}
}
void dfs2(int x){
	bg[x]=++tt,gb[bg[x]]=x;
	if(sz[x]==1)return;
	int ans=-1,w;
	for(auto cu:g[x]){
		if(ans<sz[cu]){
			ans=sz[cu];
			w=cu;
		}
	}
	ffa[w]=ffa[x],dfs2(w);
	for(auto cu:g[x]){
		if(cu==w)continue;
		ffa[cu]=cu,dfs2(cu);
	}
}
signed main(){
	int n,m,q,c;
	cin>>n>>m>>q>>c;
	for(int i=1;i<=n;++i)scanf("%lld",&cs[i]);
	for(int i=2;i<=n;++i){
		int p;
		scanf("%lld",&p);
		g[p].emplace_back(i);
	}
	for(int i=1;i<=m;++i)scanf("%lld",&b[i]);
	for(int i=1;i<=m;++i)id[i]=build(1,n,0);
	dep[1]=1;
	dfs1(1);
	ffa[1]=1;
	dfs2(1);
	for(int i=1;i<=n;++i){
		int x=i;
		while(x!=0){
			int xx=ffa[x];
			add(1,n,id[cs[i]],bg[xx],bg[x],1);
			x=fa[xx];
		}
	}
	while(q--){
		int op,x;
		scanf("%lld%lld",&op,&x);
		if(op==1){
			int xx=x,cc=cs[xx];
			int y;
			scanf("%lld",&y);
			while(x!=0){
				int xx=ffa[x];
				add(1,n,id[cc],bg[xx],bg[x],-1);
				add(1,n,id[y],bg[xx],bg[x],1);
				x=fa[xx];
			}
			cs[xx]=y;
		}else{
			auto cu=sm[id[x]];
			double ans=1.0*c*c*n;
			ans-=2.0*c*b[x]*cu.S1;
			ans+=1.0*b[x]*b[x]*cu.S2;
			ans/=n;
			printf("%.10Lf\n",ans);
		}
	}
	return 0;
}