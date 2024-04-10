#include<bits/stdc++.h>
using namespace std;
enum{N=200009,M=N*50};
int u,v,lc[M],rc[M],id,ans[N],rt[109];
void upd(int&k,int l,int r){
	if(!k)k=++id;
	if(l==r)return;
	int m=l+r>>1;
	u>m?upd(rc[k],m+1,r):upd(lc[k],l,m);
}
void sp(int&k,int&t,int l,int r){
	if(!k||r<u||l>v)return;
	if(u<=l&&r<=v){t=k,k=0;return;}
	int m=l+r>>1;
	t=++id,sp(lc[k],lc[t],l,m),sp(rc[k],rc[t],m+1,r);
}
void mg(int&k,int&t){
	if(k&&t)mg(lc[k],lc[t]),mg(rc[k],rc[t]);else k|=t;
	t=0;
}
void qry(int k,int l,int r){
	if(!k)return;
	if(l==r){ans[l]=u;return;}
	int m=l+r>>1;
	qry(lc[k],l,m),qry(rc[k],m+1,r);
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,q,i,j;
	for(cin>>n,u=1;u<=n;++u)cin>>i,upd(rt[i],1,n);
	for(cin>>q;q--;)cin>>u>>v>>i>>j,sp(rt[i],*rt,1,n),mg(rt[j],*rt);
	for(i=1;i<=100;++i)u=i,qry(rt[i],1,n);
	for(i=1;i<=n;++i)cout<<ans[i]<<' ';
	return 0;
}