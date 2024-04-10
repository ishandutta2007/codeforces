#include<bits/stdc++.h>
#define N 100000
#define int long long
using namespace std;
int n,a[N+1],b[4*N+1],nxt[4*N+1],ls[N+1],p,q,pb;
int fa[N+1],fc[N+1],ns[N+1],lc[N+1],sz[N+1],aa,ab,na[N+1],nb[N+1];
long double dsz[N+1],ans,da[N+1],db[N+1];
void lb(int np,int nq){ls[np]=(a[np]?nxt[ls[np]]:a[np])=++pb,b[pb]=nq;}
void putin(){
	cin>>n;
	for(int i=1;i<n;i++)cin>>p>>q,lb(p,q),lb(q,p);
	for(int i=1;i<=n;i++)cin>>na[i]>>nb[i],aa+=na[i],ab+=nb[i];
	for(int i=1;i<=n;i++)da[i]=1.0*na[i]/aa,db[i]=1.0*nb[i]/ab;
}
void tttree(int x){
	sz[x]=1,dsz[x]=da[x];
	for(int i=a[x];i;i=nxt[i]){
		if(b[i]==fa[x])continue;
		fa[b[i]]=x,lc[x]=(fc[x]?ns[lc[x]]:fc[x])=b[i];
		tttree(b[i]);
		sz[x]+=sz[b[i]],dsz[x]+=dsz[b[i]];
	}
}
signed main(){
//	freopen("maze.in","r",stdin);
//	freopen("maze.out","w",stdout);
	putin();
	tttree(1);
	for(int i=1;i<=n;i++){
		for(int j=fc[i];j;j=ns[j])ans+=dsz[j]*db[i]*(sz[j]);
		if(fa[i])ans+=(1-dsz[i])*db[i]*(n-sz[i]);
	}
	printf("%.12f\n",(double)ans);
	return 0;
}