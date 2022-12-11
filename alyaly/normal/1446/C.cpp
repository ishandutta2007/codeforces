//#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int n,a[200001],pb,b[4000001],nxt[4000001],ls[200001],fl[200001],ans;
int son[2][4000001],tr[4000001],g[4000001],pp,t[200001],pt;
pair<int,int> pa[4000001];
void lb(int np,int nq){ls[np]=(a[np]?nxt[ls[np]]:a[np])=++pb;b[pb]=nq;}
int dfs(int x){
	fl[x]=1;int nans=1;
	for(int i=a[x];i;i=nxt[i])if(!fl[b[i]])nans+=dfs(b[i]);return nans;
}
void trieadd(int nx,int x,int np,int p){
	if(!g[nx]){
		g[nx]=x;
	}else{
		g[nx]=-1;
	}
	if(np<0){
		tr[nx]=p;
		return;
	}
	if(x&(1<<np)){
		if(!son[1][nx])son[1][nx]=++pb;
		trieadd(son[1][nx],x,np-1,p);
	}else{
		if(!son[0][nx])son[0][nx]=++pb;
		trieadd(son[0][nx],x,np-1,p);
	}
}
int triefnd(int nx,int x,int np){
	if(np<0){
		return tr[nx];
	}
	if(x&(1<<np)){
		if(!son[1][nx]||g[son[1][nx]]==x)return triefnd(son[0][nx],x,np-1);
		return triefnd(son[1][nx],x,np-1);
	}else{
		if(!son[0][nx]||g[son[0][nx]]==x)return triefnd(son[1][nx],x,np-1);
		return triefnd(son[0][nx],x,np-1);
	}
}
int fz(int l,int r,int np){
	if(l==r||r-1==l)return 0;
	int ng=0;
	for(int i=l;i<r;i++)if(!(a[i]&(1<<np))&&(a[i+1]&(1<<np)))ng=i;
	if(!ng){
		return fz(l,r,np-1);
	}
	return min(fz(ng+1,r,np-1)+ng-l,fz(l,ng,np-1)+r-ng-1);
}
signed main(){
	cin>>n;pb=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<fz(1,n,30)<<endl;
//	for(int i=1;i<=pb;i++)printf("%d:%d %d %d %d\n",i,tr[i],son[0][i],son[1][i],g[i]);
//	for(int i=1;i<=n;i++){
//		pa[++pp]=make_pair(i,triefnd(1,a[i],30));
//	}
//	memset(a,0,sizeof(a));
//	for(int i=1;i<=pp;i++)lb(pa[i].first,pa[i].second),lb(pa[i].second,pa[i].first);
//	for(int i=1;i<=n;i++){
//		if(!fl[i]){
//			t[++pt]=dfs(i)-1;
//		}
//	}
//	sort(t+1,t+pt+1);
//	for(int i=1;i<pt;i++)ans+=t[i];cout<<ans<<endl;
	return 0;
}
/*
6
3 5 6 152 168 176
*/