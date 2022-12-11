#include<bits/stdc++.h>
#define mid (l+r)/2
#define N 100000
#define M 5000000
#define int long long
#define inf 999999999999999999
using namespace std;
int n,a[N+1],b[4*N+1],nxt[4*N+1],ls[N+1],q0,q1,pb;
int aa[N+1],bb[N+1],dp[N+1],son[M+1][2],rt[N+1];
int fa[N+1],fc[N+1],ns[N+1],lc[N+1],dpt[N+1],sz[N+1],hs[N+1];
int dic[N+1],pdic;
struct line{
	int k,b;
	int dr(int x){return k*dic[x]+b;}
}seg[M+1],In;
vector<line>ve[N+1];
queue<int>qu;
int qread(){int nans=0,nf=1;char c=getchar();while(c!='-'&&(c<'0'||c>'9'))c=getchar();if(c=='-')nf=-1,c=getchar();while(c>='0'&&c<='9')nans=nans*10+c-'0',c=getchar();return nans*nf;}
int lb(int np,int nq){ls[np]=(a[np]?nxt[ls[np]]:a[np])=++pb,b[pb]=nq;}
int qnew(){int nt=qu.front();seg[nt]=In,qu.pop();return nt;}
void putin(){
	n=qread();
	for(int i=1;i<=n;i++)aa[i]=qread();
	for(int i=1;i<=n;i++)bb[i]=qread();
	for(int i=1;i<n;i++)q0=qread(),q1=qread(),lb(q0,q1),lb(q1,q0);
}
void tttree(int x,int ndpt){
	dpt[x]=ndpt,sz[x]=1;
	for(int i=a[x];i;i=nxt[i]){
		if(fa[x]==b[i])continue;
		fa[b[i]]=x,lc[x]=(fc[x]?ns[lc[x]]:fc[x])=b[i];
		tttree(b[i],ndpt+1),sz[x]+=sz[b[i]];
		if(sz[b[i]]>sz[hs[x]])hs[x]=b[i];
	}
}
int blcal(int x,int na){
	int nans=bb[x]*na+dp[x];
	for(int i=fc[x];i;i=ns[i])nans=min(nans,blcal(i,na));
	return nans;
}
void bldp(int x){
	dp[x]=inf;if(!fc[x])dp[x]=0;
	for(int i=fc[x];i;i=ns[i]){
		bldp(i),dp[x]=min(dp[x],blcal(i,aa[x]));
	}
}
void caldic(){
	for(int i=1;i<=n;i++)dic[++pdic]=aa[i];
	sort(dic+1,dic+pdic+1),pdic=unique(dic+1,dic+pdic+1)-dic-1;
	for(int i=1;i<=n;i++)aa[i]=lower_bound(dic+1,dic+pdic+1,aa[i])-dic;
}
void segadd(int u,int l,int r,line nx){
	if(l==r){
		if(nx.dr(l)<seg[u].dr(l))seg[u]=nx;
	}else{
		bool na=(nx.dr(l)<seg[u].dr(l)),nb=(nx.dr(r)<seg[u].dr(r));
		if(nx.dr(mid)<seg[u].dr(mid)){
			if(na&&nb){
				seg[u]=nx;
				return;
			}
			if(!na){
				if(!son[u][0])son[u][0]=qnew();segadd(son[u][0],l,mid,seg[u]);segadd(son[u][0],l,mid,nx);
			}if(!nb){
				if(!son[u][1])son[u][1]=qnew();segadd(son[u][1],mid+1,r,seg[u]);segadd(son[u][1],mid+1,r,nx);
			}seg[u]=nx;
		}else{
			if(!na&&!nb)return;
			if(na){
				if(!son[u][0])son[u][0]=qnew();segadd(son[u][0],l,mid,nx);
			}if(nb){
				if(!son[u][1])son[u][1]=qnew();segadd(son[u][1],mid+1,r,nx);
			}
		}
	}
}
int segreq(int u,int l,int r,int nx){
	if(l==r)return seg[u].dr(nx);
	else if(nx<=mid)return min(seg[u].dr(nx),segreq(son[u][0],l,mid,nx));
	else return min(seg[u].dr(nx),segreq(son[u][1],mid+1,r,nx));
}
line segfnd(int u,int l,int r,int nx){
	if(l==r)return seg[u];
	else{
		line nl=((nx<=mid)?segfnd(son[u][0],l,mid,nx):segfnd(son[u][1],mid+1,r,nx));
		if(nl.dr(nx)<seg[u].dr(nx))return nl;
		else return seg[u];
	}
}
void segclr(int u,int l,int r){
	if(!u)return;
	if(l!=r)segclr(son[u][0],l,mid),segclr(son[u][1],mid+1,r);
	son[u][0]=son[u][1]=0,seg[u]=(line){0,0},qu.push(u);
}
void dfs1(int x){
//	if(x==9){
//		cout<<'a';
//	}
	if(!fc[x]){segadd(rt[x],1,pdic,(line){bb[x],0}),ve[rt[x]].push_back((line){bb[x],0});return;}
	dfs1(hs[x]),rt[x]=rt[hs[x]];
	for(int i=fc[x];i;i=ns[i]){
		if(i==hs[x])continue;
		dfs1(i);
		for(int j=0;j<ve[rt[i]].size();j++){
			segadd(rt[x],1,pdic,ve[rt[i]][j]),ve[rt[x]].push_back(ve[rt[i]][j]);
		}
		ve[rt[i]].clear();
		segclr(rt[i],1,pdic);
	}
	dp[x]=segreq(rt[x],1,pdic,aa[x]);
	segadd(rt[x],1,pdic,(line){bb[x],dp[x]}),ve[rt[x]].push_back((line){bb[x],dp[x]});
}
void cal1(){
	In.k=0,In.b=inf;
	for(int i=1;i<=n;i++)rt[i]=i,seg[i]=In;for(int i=n+1;i<=M;i++)qu.push(i);seg[0]=In;
	dfs1(1);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	putin();
	tttree(1,1);
//	bldp(1);
	caldic();
	cal1();
	for(int i=1;i<=n;i++)printf("%lld ",dp[i]);printf("\n");
	return 0;
}
/*
20
31 -56 1 72 -60 90 -30 -51 -45 6 -23 43 -45 -14 67 -84 33 11 -90 4
-25 -74 78 -83 35 -46 4 54 77 -65 -37 58 -94 8 12 44 -55 -29 98 65
2 1 3 1 4 1 5 2 6 2 7 4 8 6 9 6 10 7
11 9 12 11 13 12 14 12 15 12 16 13 17 8 18 17 19 17 20 16

248 448 0 2238 0 720 1950 1479 360 0 184 344 2925 0 0 5460 957 0 0 0
-20698 -18404 0 -4680 0 -16146 1950 -4998 -14092 0 -12816 -11482 -7440 0 0 -5460 -957 0 0 0

7
3 -7 -5 4 -2 -8 5
1 6 7 -4 -3 -4 -2
2 1 3 1 4 1 5 2 6 2 7 4
-20 21 0 -8 0 0 0
*/