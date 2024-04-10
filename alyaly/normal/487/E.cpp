#include<bits/stdc++.h>
#define N 400000
#define mid (l+r)/2
#define int long long
#define inf 999999999999
using namespace std;
int n,m,Q;
int a[N+1],b[4*N+1],nxt[4*N+1],ls[N+1],dq[N+1],p,q,pb;
int dfn[N+1],lw[N+1],pdfn,col[N+1],sta[N+1],psta,pc;
int fa[N+1],fc[N+1],ns[N+1],lc[N+1],dpt[N+1],sz[N+1],hs[N+1],tp[N+1];
int logn[N+1],bzb[21][N+1],seg[4*N+1],fl[N+1];
int cq[N+1],q1,q2,s[N+1];
vector<int>ve[N+1],bi[N+1];
multiset<int>se[N+1];
string q0;
void lb(int np,int nq){ls[np]=(a[np]?nxt[ls[np]]:a[np])=++pb,b[pb]=nq;}
void putin(){
	cin>>n>>m>>Q;
	for(int i=1;i<=n;i++)cin>>dq[i];
	for(int i=1;i<=m;i++)cin>>p>>q,lb(p,q),lb(q,p);
}
void dfs(int x,int nfa){
	dfn[x]=lw[x]=++pdfn,sta[++psta]=x;
	for(int i=a[x];i;i=nxt[i]){
		if(!dfn[b[i]]){
			dfs(b[i],x),lw[x]=min(lw[x],lw[b[i]]);
			if(lw[b[i]]>=dfn[x]){
				pc++;
				while(sta[psta+1]!=b[i])ve[pc].push_back(sta[psta]),psta--;
				ve[pc].push_back(x);
			}
		}else lw[x]=min(lw[x],dfn[b[i]]);
	}
}
void tttree(int x,int ndpt){
	dpt[x]=ndpt,sz[x]=1;
	for(int i=0;i<bi[x].size();i++){
		int ni=bi[x][i];
		if(ni==fa[x])continue;
		lc[x]=(fc[x]?ns[lc[x]]:fc[x])=ni,fa[ni]=x;
		tttree(ni,ndpt+1),sz[x]+=sz[ni];
		if(sz[ni]>sz[hs[x]])hs[x]=ni;
	}
}
void dfs0(int x){
	dfn[x]=++pdfn;
	if(x==hs[fa[x]])tp[x]=tp[fa[x]];else tp[x]=x;
	if(hs[x])dfs0(hs[x]);
	for(int i=fc[x];i;i=ns[i])if(i!=hs[x])dfs0(i);
}
void bzbycl(){
	for(int i=2;i<=n+pc;i++)logn[i]=logn[i/2]+1,bzb[0][i]=fa[i];bzb[0][1]=1;
	for(int i=1;i<=logn[n+pc];i++)for(int j=1;j<=n+pc;j++)bzb[i][j]=bzb[i-1][bzb[i-1][j]];
}
int lca(int x,int y){
	if(dpt[x]<dpt[y])swap(x,y);
	for(;dpt[x]>dpt[y];x=bzb[logn[dpt[x]-dpt[y]]][x]);
	if(x==y)return x;
	for(int i=logn[n+pc];i>=0;i--)if(bzb[i][x]!=bzb[i][y])x=bzb[i][x],y=bzb[i][y];
	return fa[x];
}
void segadd(int u,int l,int r,int np,int nx){
	if(l==r){
		seg[u]=nx;return;
	}else{
		if(np<=mid)segadd(u*2,l,mid,np,nx);
		else segadd(u*2+1,mid+1,r,np,nx);
		seg[u]=min(seg[u*2],seg[u*2+1]);
	}
}
int segreq(int u,int l,int r,int nl,int nr){
	if(l>nr||r<nl)return inf;
	else if(l>=nl&&r<=nr)return seg[u];
	else return min(segreq(u*2,l,mid,nl,nr),segreq(u*2+1,mid+1,r,nl,nr));
}
void ycl(){
	dfs(1,0);
	for(int i=1;i<=pc;i++){
		for(int j=0;j<ve[i].size();j++){
			int ni=ve[i][j];
			bi[ni].push_back(n+i),bi[n+i].push_back(ni);
		}
	}
	memset(dfn,0,sizeof(dfn)),pdfn=0;
	tttree(1,1);
	dfs0(1);
	bzbycl();
	for(int i=2;i<=n;i++){
		se[fa[i]].insert(dq[i]);
	}
	for(int i=1;i<=pc;i++){
		segadd(1,1,n+pc,dfn[i+n],*se[i+n].begin());
		//printf("%d ",*se[i+n].begin());
	}//printf("\n");
	for(int i=1;i<=n;i++)segadd(1,1,n+pc,dfn[i],dq[i]);
}
int treq(int np,int nq){
	int nans=inf;
	while(tp[np]!=tp[nq]){
		nans=min(nans,segreq(1,1,n+pc,dfn[tp[np]],dfn[np]));
		np=fa[tp[np]];
	}
	nans=min(nans,segreq(1,1,n+pc,dfn[nq],dfn[np]));
	return nans;
}
void cal0(){
	for(int i=1;i<=Q;i++){
		cin>>q0>>q1>>q2;
		if(q0=="C"){
			int nj=fa[q1];
			if(nj){
				se[nj].erase(se[nj].find(dq[q1]));
				se[nj].insert(q2);
				segadd(1,1,n+pc,dfn[nj],*se[nj].begin());
			}
			dq[q1]=q2;
			segadd(1,1,n+pc,dfn[q1],dq[q1]);
		}else{
			int nr=lca(q1,q2);
			int nans=treq(q1,nr);
			nans=min(nans,treq(q2,nr));
			if(nr>n)nans=min(nans,dq[fa[nr]]);
			cout<<nans<<'\n';
		}
	}
}
signed main(){
//	freopen("tourist20.in","r",stdin);
//	freopen("tourist.out","w",stdout);
	putin();
	ycl();
	cal0();
//	cout<<"bbbbb"<<endl;
//	ycl();
//	cout<<"aa"<<endl;
//	cal0();
//	for(int i=1;i<=pc;i++,cout<<'\n')for(int j=0;j<ve[i].size();j++)printf("%d ",ve[i][j]);
	return 0;
}