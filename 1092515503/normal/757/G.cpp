/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200100;
int n,q,cnt,X[N<<1],Y[N<<1],Z[N<<1],p[N];
vector<int>v[N<<1];
void dfs_cons(int x,int fa){
	int las=x;
	for(auto i:v[x]){
		int y=X[i]^Y[i]^x;
		if(y==fa)continue;
		dfs_cons(y,x);
		if(X[i]!=x)swap(X[i],Y[i]);
		++cnt;
		X[cnt-1]=las,Y[cnt-1]=cnt;
		X[i]=cnt;
		las=cnt;
	}
}
int eid,sz[N<<1],msz[N<<1],SZ;
bool ban[N<<1];
void getedge(int x,int fi){
	sz[x]=1;
	for(auto i:v[x])if(i!=fi&&!ban[i]){
		int y=X[i]^Y[i]^x;
		getedge(y,i),sz[x]+=sz[y],msz[i]=max(sz[y],SZ-sz[y]);
		if(msz[i]<msz[eid])eid=i;
	}
}
void getsz(int x,int fi){sz[x]=1;for(auto i:v[x])if(i!=fi&&!ban[i])getsz(X[i]^Y[i]^x,i),sz[x]+=sz[X[i]^Y[i]^x];}
struct SegTree{int ch[2];ll sum,num;}seg[N*60];
int rt[N],pos[N],tot,tr[N];
void ins(int x,ll dis,bool tp){
	seg[pos[x]].ch[tp]=++tot;
	seg[tot].sum=dis,seg[tot].num=1;
	pos[x]=tot;
	// printf("%d,%lld,%d\n",x,dis,tp);
}
void iterate(int x){
	if(x)printf("[%d:%d]",x,seg[x].sum),iterate(seg[x].ch[0]),iterate(seg[x].ch[1]);
}
int merge(int x,int y){
	if(!x||!y)return x+y;
	int z=++tot;seg[z].sum=seg[x].sum+seg[y].sum,seg[z].num=seg[x].num+seg[y].num;
	seg[z].ch[0]=merge(seg[x].ch[0],seg[y].ch[0]);
	seg[z].ch[1]=merge(seg[x].ch[1],seg[y].ch[1]);
	return z;
}
ll query(int x,int y){
	if(!x||!y)return 0;
	ll ret=
		seg[seg[x].ch[0]].sum*seg[seg[y].ch[1]].num+seg[seg[x].ch[1]].sum*seg[seg[y].ch[0]].num+
		seg[seg[x].ch[0]].num*seg[seg[y].ch[1]].sum+seg[seg[x].ch[1]].num*seg[seg[y].ch[0]].sum;
	ret+=query(seg[x].ch[0],seg[y].ch[0])+query(seg[x].ch[1],seg[y].ch[1]);
	return ret;
}
void getdis(int x,int fi,ll dis,bool tp){
	if(x<=n)ins(x,dis,tp);
	for(auto i:v[x])if(i!=fi&&!ban[i])getdis(X[i]^Y[i]^x,i,dis+Z[i],tp);
}
void solve(int e){
	if(!e)return;
	// printf("solve:%d(%d,%d)\n",e,X[e],Y[e]);
	getdis(X[e],e,Z[e],false),getdis(Y[e],e,0,true);
	ban[e]=true;
	getsz(X[e],e),SZ=sz[X[e]],eid=0,getedge(X[e],e),solve(eid);
	getsz(Y[e],e),SZ=sz[Y[e]],eid=0,getedge(Y[e],e),solve(eid);
}
int main(){
	scanf("%d%d",&n,&q),cnt=n;
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<n;i++)scanf("%d%d%d",&X[i],&Y[i],&Z[i]),v[X[i]].push_back(i),v[Y[i]].push_back(i);
	dfs_cons(1,0);
	// puts("BUILT.");
	// for(int i=1;i<cnt;i++)printf("%d %d %d\n",X[i],Y[i],Z[i]);
	for(int i=1;i<=n;i++)v[i].clear();
	for(int i=1;i<cnt;i++)v[X[i]].push_back(i),v[Y[i]].push_back(i);
	for(int i=1;i<=n;i++)rt[i]=pos[i]=++tot;
	msz[0]=SZ=cnt,getedge(1,0),solve(eid);
	// for(int i=1;i<=n;i++)iterate(rt[i]),puts("");
	for(int i=1;i<=n;i++)tr[i]=merge(tr[i-1],rt[p[i]]);
	ll lans=0;
	for(int i=1,tp,l,r,x;i<=q;i++){
		scanf("%d",&tp);
		if(tp==1)
			scanf("%d%d%d",&l,&r,&x),l^=lans,r^=lans,x^=lans,
			printf("%lld\n",lans=query(tr[r],rt[x])-query(tr[l-1],rt[x])),lans&=((1<<30)-1);
		else scanf("%d",&x),x^=lans,swap(p[x],p[x+1]),tr[x]=merge(tr[x-1],rt[p[x]]);
	}
	return 0;
}