//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#define int long long
#define N 403
using namespace std;
int T,n,K,a[N+1],b[4*N+1],nxt[4*N+1],ls[N+1],d[N+1],p,q,pb,dd,pre[N+1],aa,ans[N+1],pans;
int fl[N+1],fa[N+1],fc[N+1],ns[N+1],lc[N+1],hs[N+1],mdpt[N+1],dpt[N+1];
void lb(int np,int nq){ls[np]=(a[np]?nxt[ls[np]]:a[np])=++pb,b[pb]=nq;}
void putin(){
	pb=0;
	memset(a,0,sizeof(a));memset(b,0,sizeof(b));memset(nxt,0,sizeof(nxt));memset(ls,0,sizeof(ls));
	memset(ans,0,sizeof(ans));memset(fa,0,sizeof(fa));memset(fc,0,sizeof(fc));memset(ns,0,sizeof(ns));
	memset(lc,0,sizeof(lc));memset(hs,0,sizeof(hs));memset(dpt,0,sizeof(dpt));memset(mdpt,0,sizeof(mdpt));
	cin>>n>>K;
	for(int i=2;i<=n;i++)cin>>p,lb(i,p),lb(p,i);
}
void tttree(int x,int ndpt){
	dpt[x]=mdpt[x]=ndpt;
	for(int i=a[x];i;i=nxt[i]){
		if(fa[x]==b[i])continue;
		fa[b[i]]=x,lc[x]=(fc[x]?ns[lc[x]]:fc[x])=b[i];
		tttree(b[i],ndpt+1);
		if(mdpt[b[i]]>mdpt[hs[x]])hs[x]=b[i],mdpt[x]=mdpt[b[i]];
	}
}
void ddfs(int x){
	if(aa>=K-1)return;
	ans[++pans]=x;aa++;
	if(aa>=K-1)return;
	for(int i=fc[x];i;i=ns[i]){
		ddfs(i);
		ans[++pans]=x;
		if(aa>=K-1)return;
	}
}
void cdfs(int x){
	ans[++pans]=x;
	for(int i=fc[x];i;i=ns[i]){
		if(i==hs[x]||aa>=K-1)continue;
		ddfs(i);
		ans[++pans]=x;
		if(aa>=K-1)continue;
	}
	if(hs[x])cdfs(hs[x]);
}
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	cin>>T;
	while(T--){
		putin();
		pans=0;
		tttree(1,0);
		if(mdpt[1]>=K-1){
			printf("%d\n",K-1);
			int ng=1,np=1;
			while(ng<=K){
				printf("%d ",np);
				np=hs[np];
				ng++;
			}
			printf("\n");continue;
		}
		aa=mdpt[1];
		cdfs(1);
		printf("%d\n",2*(K-1)-mdpt[1]);
		for(int i=1;i<=pans;i++)printf("%d ",ans[i]);printf("\n");
	}
	return 0;
}
/*
8
9 1
1 1 1 2 2 4 6 6
9 2
1 1 1 2 2 4 6 6
9 3
1 1 1 2 2 4 6 6
9 4
1 1 1 2 2 4 6 6
9 5
1 1 1 2 2 4 6 6
9 6
1 1 1 2 2 4 6 6
9 7
1 1 1 2 2 4 6 6
9 8
1 1 1 2 2 4 6 6
9 9
1 1 1 2 2 4 6 6
*/