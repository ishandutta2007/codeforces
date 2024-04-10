#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>g[200005];
int fa[21][200005];
int dep[200005];
int bg[200005],gb[200005],en[200005],tot=0;
int ol[21][400005],L[200005],R[200005],cd=0;
int lg[400005];
void dfs(int x,int la){
	bg[x]=en[x]=++tot,gb[bg[x]]=x;
	ol[0][++cd]=bg[x],L[x]=R[x]=cd;
	for(auto cu:g[x]){
		if(cu==la)continue;
		fa[0][cu]=x;
		dep[cu]=dep[x]+1;
		dfs(cu,x);
		en[x]=en[cu];
		ol[0][++cd]=bg[x],R[x]=cd;
	}
}
int lca(int x,int y){
	int ll=L[x],rr=R[y];
	if(ll>rr)swap(ll,rr);
	int zz=lg[rr-ll+1];
	return gb[min(ol[zz][ll],ol[zz][rr-(1<<zz)+1])];
}
int dist(int x,int y){
	if(x<0||y<0)return -1;
	int l=lca(x,y);
	return (dep[x]-dep[l])+(dep[y]-dep[l]);
}
int tiaofa(int x,int gd){
	for(int i=20;i>=0;--i)
		if(gd>=(1<<i))gd-=1<<i,x=fa[i][x];
	return x;
}
namespace fen1{
	int c[200005];
	void add(int x,int s){
		while(x<=n){
			c[x]+=s;
			x+=x&-x;
		}
	}
	int query(int x){
		int ans=0;
		while(x){
			ans+=c[x];
			x-=x&-x;
		}
		return ans;
	}
	int sum(int l,int r){
		return query(r)-query(l-1);
	}
};
struct apple{
	int gs;
	int L,R,cd;
}sm[800005];
apple operator+(apple a,apple b){
	apple c;
	int b1=a.cd,b2=dist(a.L,b.L),b3=dist(a.L,b.R);
	int b4=dist(a.R,b.L),b5=dist(a.R,b.R),b6=b.cd;
	int mx=max(max(b1,b2),max(max(b3,b4),max(b5,b6)));
	if(mx==b1)c.L=a.L,c.R=a.R;
	else if(mx==b2)c.L=a.L,c.R=b.L;
	else if(mx==b3)c.L=a.L,c.R=b.R;
	else if(mx==b4)c.L=a.R,c.R=b.L;
	else if(mx==b5)c.L=a.R,c.R=b.R;
	else c.L=b.L,c.R=b.R;
	c.cd=mx;
	return c;
}
void add(int l,int r,int o,int x,int jz){
	if(l==r){
		sm[o].gs+=jz;
		if(sm[o].gs>=1)sm[o].L=sm[o].R=gb[l],sm[o].cd=0;
		else sm[o].L=sm[o].R=-1,sm[o].cd=-1;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)add(l,mid,o<<1,x,jz);
	else add(mid+1,r,o<<1|1,x,jz);
	sm[o]=sm[o<<1]+sm[o<<1|1];
}
apple query(int l,int r,int o,int ll,int rr){
	if(l>=ll&&r<=rr)return sm[o];
	int mid=(l+r)>>1;
	if(mid>=ll&&mid<rr){
		return query(l,mid,o<<1,ll,rr)+query(mid+1,r,o<<1|1,ll,rr);
	}
	if(mid>=ll)return query(l,mid,o<<1,ll,rr);
	return query(mid+1,r,o<<1|1,ll,rr);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=20;++i)for(int j=1;j<=n;++j)
		fa[i][j]=fa[i-1][fa[i-1][j]];
	for(int i=1;i<=20;++i)for(int j=1;j<=cd-(1<<i)+1;++j)
		ol[i][j]=min(ol[i-1][j],ol[i-1][j+(1<<(i-1))]);
	lg[1]=0;
	for(int i=2;i<=cd;++i)lg[i]=lg[i>>1]+1;
	multiset<pair<int,int>>ms;
	for(int i=1;i<=4*n;++i){
		sm[i].L=sm[i].R=-1;
		sm[i].cd=-1;
	}
	while(m--){
		int op;
		scanf("%d",&op);
		if(op==1){
			int u,v;
			scanf("%d%d",&u,&v);
			int l=lca(u,v);
			ms.emplace(-dep[l],l);
			fen1::add(bg[u],1);
			fen1::add(bg[v],1);
			fen1::add(bg[l],-1);
			add(1,n,1,bg[l],1);
		}else if(op==2){
			int u,v;
			scanf("%d%d",&u,&v);
			int l=lca(u,v);
			ms.erase(ms.find(make_pair(-dep[l],l)));
			fen1::add(bg[u],-1);
			fen1::add(bg[v],-1);
			fen1::add(bg[l],1);
			add(1,n,1,bg[l],-1);
		}else{
			int d;
			scanf("%d",&d);
			int x=(*ms.begin()).second;
			int ff=tiaofa(x,min(dep[x],2*d));
			int gs=ms.size();
			if(fen1::sum(bg[ff],en[ff])!=gs){
				puts("No");
				continue;
			}
			int le=query(1,n,1,bg[ff],en[ff]).cd;
			if(le<=2*d)puts("Yes");
			else puts("No");
		}
	}
	return 0;
}