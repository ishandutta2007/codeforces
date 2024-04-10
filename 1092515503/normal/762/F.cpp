#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int bs=13;
void ADD(int&x,int y){if((x+=y)>=mod)x-=mod;}
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
int n,m,res;
vector<int>u[1010],v[20],vec;
int f[1010][20],g[1010][20],h[1<<12],deg[20],frm[20],id[20],rt;
int fav[1010][20][20];
int p[1010][1<<12],q[1010][1<<12];
void calch(int x,int i){
	int lim=1<<deg[i];
	for(int k=0;k<lim;k++)h[k]=0;h[0]=1;
	for(auto y:u[x])for(int k=lim-1;k>=0;k--)for(int j=0;j<deg[i];j++)
		if(!(k&(1<<j)))ADD(h[k|(1<<j)],1ll*h[k]*f[y][v[i][j]]%mod);
//	printf("H:");for(int k=0;k<lim;k++)printf("%d ",h[k]);puts("");
}
void dfs1(int x){
	vector<int>w;
	for(auto y:u[x])u[y].erase(find(u[y].begin(),u[y].end(),x)),dfs1(y);
	for(int i=1;i<=m;i++)calch(x,i),f[x][i]=h[(1<<deg[i])-1];
//	printf("%d:",x);for(int i=1;i<=m;i++)printf("%d ",f[x][i]);puts("");
}
void dfs2(int x){
//	printf("%2d:",x);for(int i=1;i<=m;i++)printf("%2d ",f[x][i]);puts("");
	for(int i=1;i<=m;i++)ADD(f[x][i],g[x][i]);
	if(u[x].empty())return;
	for(auto i:vec){
		if(i==rt)continue;
		int lim=(1<<deg[i]);
		p[*u[x].begin()][0]=1;for(int j=0;j<deg[i];j++)p[*u[x].begin()][1<<j]=fav[x][i][j];
		for(auto y=u[x].begin();next(y)!=u[x].end();y++){
			for(int j=0;j<deg[i];j++)for(int k=0;k<lim;k++)if(!(k&(1<<j)))
				ADD(p[*next(y)][k|(1<<j)],1ll*p[*y][k]*f[*y][v[i][j]]%mod);
			for(int k=0;k<lim;k++)ADD(p[*next(y)][k],p[*y][k]);
		}
		q[*u[x].rbegin()][0]=1;
		for(auto y=u[x].rbegin();next(y)!=u[x].rend();y++){
			for(int j=0;j<deg[i];j++)for(int k=0;k<lim;k++)if(!(k&(1<<j)))
				ADD(q[*next(y)][k|(1<<j)],1ll*q[*y][k]*f[*y][v[i][j]]%mod);
			for(int k=0;k<lim;k++)ADD(q[*next(y)][k],q[*y][k]);
		}
		for(auto y:u[x]){
			int sum=0;
			for(int k=0;k<lim;k++)ADD(sum,1ll*p[y][k]*q[y][(lim-1)^k]%mod);
			calch(y,frm[i]);
			fav[y][frm[i]][id[i]]=sum;
			ADD(g[y][frm[i]],1ll*h[(1<<deg[frm[i]])-1-(1<<id[i])]*sum%mod);
			for(int k=0;k<lim;k++)p[y][k]=q[y][k]=0;
		}
	}
	for(auto y:u[x])dfs2(y);
}
namespace isomor{
ll hs[20];
int pro=1,fac[20];
int sz[20],msz[20];
void grt(int x,int fa){
	sz[x]=1;
	for(auto y:v[x])if(y!=fa)grt(y,x),sz[x]+=sz[y],msz[x]=max(msz[x],sz[y]);
	msz[x]=max(msz[x],m-sz[x]);
	if(msz[rt]>msz[x])rt=x;
}
void gsz(int x){
	vec.push_back(x);
	sz[x]=1;
	for(auto y:v[x])v[y].erase(find(v[y].begin(),v[y].end(),x)),gsz(y),sz[x]+=sz[y];
	for(int i=0;i<v[x].size();i++)frm[v[x][i]]=x,id[v[x][i]]=i;
}
void aim(int x,int fa){
	vector<ll>w;
	for(auto y:v[x])if(y!=fa)aim(y,x),w.push_back(hs[y]);
	sort(w.begin(),w.end());
	for(int l=0,r=0;l<w.size();l=r){
		while(r<w.size()&&w[r]==w[l])r++;
		pro=1ll*pro*fac[r-l]%mod;
	}
	hs[x]=1;for(auto i:w)hs[x]=hs[x]*bs+i;
}
}using namespace isomor;
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),u[x].push_back(y),u[y].push_back(x);
	scanf("%d",&m);
	for(int i=1,x,y;i<m;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	fac[0]=1;for(int i=1;i<=m;i++)fac[i]=1ll*fac[i-1]*i%mod;
	msz[rt=0]=m,grt(1,0),aim(rt,0),gsz(rt);
	for(int i=1;i<=m;i++)if((sz[i]<<1)==m){
		int qwq=pro;
		aim(rt,i),aim(i,rt);
		pro=qwq;
		if(hs[rt]==hs[i])(pro<<=1)%=mod;
		break;
	}
	for(int i=1;i<=m;i++)deg[i]=v[i].size();
//	for(int i=1;i<=m;i++)printf("%d ",deg[i]);puts("");
	dfs1(1),dfs2(1);
	for(int i=1;i<=n;i++)ADD(res,f[i][rt]);
	printf("%d\n",1ll*res*ksm(pro)%mod);
	return 0;
}
/*
1
12
12 9
4 2
11 9
7 4
11 3
10 6
2 8
2 12
1 2
4 5
9 10
*/