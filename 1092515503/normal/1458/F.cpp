#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int>v[200100];
struct Nei{
	int p,r;Nei(){}
	Nei(int P,int R){p=P,r=R;}
	void print()const{printf("(%d,%d)",p,r);}
};
namespace Tree{
int fir[200100],lim,st[400100][19],dep[200100],LG[400100],fa[200100],anc[200100][19];
int son[200100],len[200100],dfn[200100],rev[200100],top[200100],tot,ult[200100];
void dfs1(int x){
	st[++lim][0]=x,dep[x]=dep[fa[x]]+1,fir[x]=lim;
	anc[x][0]=fa[x];for(int i=1;i<=18;i++)anc[x][i]=anc[anc[x][i-1]][i-1];
	for(auto y:v[x])if(y!=fa[x]){
//		printf("%d %d\n",x,y);
		fa[y]=x,dfs1(y);
		if(len[x]<len[y]+1)len[x]=len[y]+1,son[x]=y;
		st[++lim][0]=x;
	}
}
void dfs2(int x){
	dfn[x]=++tot,rev[tot]=x;
	if(!top[x]){
		top[x]=x;
		for(int i=0,y=fa[x];i<=len[x]&&y;i++,y=fa[y])ult[tot+i]=y;
	}
	if(son[x])top[son[x]]=top[x],dfs2(son[x]);
	for(auto y:v[x])if(y!=fa[x]&&y!=son[x])dfs2(y);
}
inline int MIN(const int&x,const int&y){return dep[x]<dep[y]?x:y;}
inline int LCA(int x,int y){
	x=fir[x],y=fir[y];
	if(x>y)swap(x,y);
	int k=LG[y-x+1]; 
	return MIN(st[x][k],st[y-(1<<k)+1][k]);
}
inline int KAC(int x,int k){
	if(!k)return x;
	x=anc[x][LG[k]],k-=1<<LG[k];
	if(dep[x]-dep[top[x]]>=k)return rev[dfn[x]-k];
	k-=dep[x]-dep[top[x]],x=top[x];
	return ult[dfn[x]+k-1];
}
inline int DIS(int x,int y){return dep[x]+dep[y]-(dep[LCA(x,y)]<<1);}
inline Nei MPT(int x,int y,int d){return Nei(KAC(dep[x]>=dep[y]?x:y,d),d);}
void init(){
	dfs1(1),dfs2(1);
	for(int i=2;i<=lim;i++)LG[i]=LG[i>>1]+1;
	for(int j=1;j<=LG[lim];j++)for(int i=1;i+(1<<j)-1<=lim;i++)
		st[i][j]=MIN(st[i][j-1],st[i+(1<<j-1)][j-1]);
}
}
using Tree::LCA;
using Tree::MPT;
using Tree::DIS;
namespace CDT{
int sz[200100],msz[200100],RT,SZ,jum[200100],dep[200100];
vector<int>dis[200100];
bool vis[200100];
ll sel[200100],par[200100];
int cnt[200100];
#define iter for(auto y:v[x])if(y!=fa&&!vis[y])
void getroot(int x,int fa){
	sz[x]=1,msz[x]=0;
	iter getroot(y,x),sz[x]+=sz[y],msz[x]=max(msz[x],sz[y]);
	msz[x]=max(msz[x],SZ-sz[x]);
	if(msz[x]<msz[RT])RT=x;
}
void getdep(int x,int fa){dis[x].push_back(dep[x]);iter dep[y]=dep[x]+1,getdep(y,x);}
void getsz(int x,int fa){sz[x]=1;iter getsz(y,x),sz[x]+=sz[y];}
void solve(int x){
	getsz(x,0),dep[x]=0,getdep(x,0),vis[x]=true,reverse(dis[x].begin(),dis[x].end());
	for(auto y:v[x])if(!vis[y])SZ=sz[y],RT=0,getroot(y,0),jum[RT]=x,solve(RT);
}
void init(){
	msz[RT=0]=SZ=(n<<1)-1,getroot(1,0),solve(RT);
/*	for(int i=1;i<=n;i++){
		printf("%d:",i);
		for(int x=i,j=0;x;x=jum[x],j++)printf("[%d,%d]",x,dis[i][j]);
		puts("");
	}*/
}
void insert(int x,int tp){
//	printf("INSERT:%d,%d\n",x,tp);
	for(int i=0,y=x;i<dis[x].size();i++,y=jum[y]){
		cnt[y]+=tp,sel[y]+=dis[x][i]*tp;
		if(i+1<dis[x].size())par[y]+=dis[x][i+1]*tp;
	}
}
ll calc(int x){
	ll ret=0;
	for(int i=0,y=x;i<dis[x].size();i++,y=jum[y]){
		ret+=1ll*cnt[y]*dis[x][i]+sel[y];
		if(i+1<dis[x].size())ret-=1ll*cnt[y]*dis[x][i+1]+par[y];
	}
//	printf("CALC:%d,%lld\n",x,ret);
	return ret;
}
}
using CDT::insert;
using CDT::calc;
ll res;
struct Dia{
	int x,y,z;
	Dia(){}
	Dia(int X){x=y=X,z=0;}
	Dia(int X,int Y){x=X,y=Y,z=DIS(x,y);}
	friend bool operator<(const Dia&u,const Dia&v){return u.z<v.z;}
	friend Dia operator+(const Dia&u,const int&v){
		Dia w=u;
		w=max(w,Dia(u.x,v));
		w=max(w,Dia(u.y,v));
		return w;
	}
	Nei operator()()const{return MPT(x,y,z>>1);}
}D[100100];
inline int rela(const Nei&u,const Nei&v){
	int dis=DIS(u.p,v.p);
	if(v.r+dis<=u.r)return 1;
	if(u.r+dis<=v.r)return -1;
	return 0;
}
Nei N[100100];
ll sum[100100];
vector<int>vec[100100];
void solve(int l,int r){
	if(l==r)return;
	int mid=(l+r)>>1;
	solve(l,mid),solve(mid+1,r);
//	printf("[%d,%d]\n",l,r);
	D[mid]=Dia(mid);for(int i=mid-1;i>=l;i--)D[i]=D[i+1]+i;
	D[mid+1]=Dia(mid+1);for(int i=mid+2;i<=r;i++)D[i]=D[i-1]+i;
//	printf("%d,%d,%d,%d\n",D[l].x,D[l].y,LCA(D[l].x,D[l].y),D[l].z);
	for(int i=l;i<=r;i++)N[i]=D[i]();
	sum[l-1]=0;for(int i=l;i<=mid;i++)sum[i]=sum[i-1]+N[i].r;
//	for(int i=l;i<=r;i++)N[i].print();puts("");
//	for(int i=l-1;i<=mid;i++)printf("%lld ",sum[i]);puts("");
	for(int i=mid+1,u,v;i<=r;i++){
		int p1,p2;
		u=l,v=mid+1;
		while(u<v){
			int w=(u+v)>>1;
			if(rela(N[i],N[w])==1)v=w;else u=w+1;
		}
		p1=v;
		u=l,v=p1;
		while(u<v){
			int w=(u+v)>>1;
			if(rela(N[i],N[w])==0)v=w;else u=w+1;
		}
		p2=v;
//		printf("<%d,%d>",p1,p2);
		res+=1ll*(mid+1-p1)*N[i].r<<1;
//		printf("[%lld,%lld,%lld]",sum[p2-1]<<1,sum[p1-1]-sum[p2-1],1ll*(p1-p2)*N[i].r);
		res+=sum[p2-1]<<1;
		res+=sum[p1-1]-sum[p2-1];
		res+=1ll*(p1-p2)*N[i].r;
		if(p1!=mid+1)vec[p1].push_back(-i);
		if(p2!=mid+1)vec[p2].push_back(i);
	}//puts("");
	for(int i=mid;i>=l;i--){
		insert(N[i].p,1);
		for(auto x:vec[i])if(x>0)res+=calc(N[x].p);else res-=calc(N[-x].p);
		vec[i].clear();
	}
	for(int i=mid;i>=l;i--)insert(N[i].p,-1);
//	printf("%lld\n",res);
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)
		scanf("%d%d",&x,&y),
		v[x].push_back(i+n),v[i+n].push_back(x),
		v[y].push_back(i+n),v[i+n].push_back(y);
	Tree::init();
	CDT::init();
	solve(1,n);
	printf("%lld\n",res>>1);
	return 0;
}
/*
20
1 2
2 3
3 4
2 5
4 6
4 7
6 8
2 9
4 10
7 11
1 12
9 13
3 14
6 15
15 16
4 17
5 18
9 19
11 20
*/