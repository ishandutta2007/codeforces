#include<bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
int n,a[100001],b[400001],nxt[400001],ls[100001],cd[100001],p,q,pb,rt,fl[100001];
int fa[100001],fc[100001],ns[100001],lc[100001];
int dpt[100001],logn[100001],bzb[20][100001];
int lev[100001],pl,ans1=1,ans2;
void lb(int np,int nq){
	if(!a[np]) a[np]=++pb;
	else nxt[ls[np]]=++pb;
	b[pb]=nq;
	ls[np]=pb;
	cd[np]++;
	return;
}
void putin(){
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>p>>q;
		lb(p,q);
		lb(q,p);
	}
	return;
}
void tttree(int x,int ndpt){
	dpt[x]=ndpt;
	for(int i=a[x];i;i=nxt[i]){
		if(fa[x]!=b[i]){
			fa[b[i]]=x;
			if(!fc[x]) fc[x]=b[i];
			else ns[lc[x]]=b[i];
			lc[x]=b[i];
			tttree(b[i],ndpt+1);
		}
	}
	return;
}
void ycl(){
	for(int i=2;i<=n;i++) logn[i]=logn[i/2]+1;
	for(int i=1;i<=n;i++){
		bzb[0][i]=fa[i];
	}
	for(int i=1;i<=logn[n];i++){
		for(int j=1;j<=n;j++){
			bzb[i][j]=bzb[i-1][bzb[i-1][j]];
		}
	}
	return;
}
int lca(int x,int y){
	if(dpt[x]<dpt[y]) swap(x,y);
	while(dpt[x]>dpt[y]) x=bzb[logn[dpt[x]-dpt[y]]][x];
	if(x==y) return x;
	while(fa[x]!=fa[y]){
		for(int i=logn[n];i>=0;i--){
			if(bzb[i][x]!=bzb[i][y]){
				x=bzb[i][x];
				y=bzb[i][y];
			}
		}
	}
	return fa[x];
}
signed main(){
	putin();
	for(int i=1;i<=n;i++){
		if(cd[i]!=1){
			rt=i;
			tttree(i,1);
			break;
		}
	}
	ycl();
	for(int i=1;i<=n;i++){
		if(cd[i]==1){
			lev[++pl]=i;
		}
	}
	ans2=n-1;
	for(int i=1;i<pl;i++){
		int r=lca(lev[i],lev[i+1]);
		if((dpt[lev[i]]+dpt[lev[i+1]]-2*dpt[r])%2!=0){
			ans1=3;
		}
		if(fl[fa[lev[i]]]){
			ans2--;
		}
		fl[fa[lev[i]]]=1;
	}
	if(fl[fa[lev[pl]]]) ans2--;
	printf("%lld %lld\n",ans1,ans2);
	return 0;
}