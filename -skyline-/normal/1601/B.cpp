#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#pragma GCC optimize("O2")
using namespace std;
int n,a[300005],b[300005],d[1200005],q[1200005],qr,ans[1200005],res[1200005],Q[1200005];
int L,R,X;
vector<int> v[300005],e[1200005];
void dfs(int k,int l,int r){
	if(l>=L&&R>=r){
		e[k].pb(X);
		return;
	}
	int m=(l+r)>>1;
	if(L<=m)dfs(k<<1,l,m);
	if(R>m)dfs((k<<1)|1,m+1,r);
}
void upd(int x,int k,int _){
	if(ans[x]!=-1) return;
	ans[x]=k,res[x]=_;
	for(int i=0;i<v[x].size();++i)d[v[x][i]+524287]=k+1,q[++qr]=v[x][i]+524287,Q[qr]=x;
}
int main(){
	scanf("%d",&n);
	memset(d,-1,sizeof(d));
	memset(ans,-1,sizeof(ans));
	d[0]=0;
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
	}
	for(int i=1;i<=n;++i)scanf("%d",b+i),v[i+b[i]].pb(i);
	
	for(int i=1;i<=n;++i){
		if(a[i]>=i)upd(i,1,0);
		else{
			L=i-a[i],R=i,X=i;
			dfs(1,1,524288);
		}
	}
	for(int ql=1;ql<=qr;++ql){
		int x=q[ql];
		int o=x;
		for(int i=0;i<e[o].size();++i)upd(e[o][i],d[o],x-524287);
		o/=2;
		while(d[o]==-1){
			d[o]=d[x];
			for(int i=0;i<e[o].size();++i)upd(e[o][i],d[o],x-524287);
			o>>=1;
		}
	}
	printf("%d\n",ans[n]);
	if(ans[n]!=-1){
		int x=n;
		for(int i=1;i<ans[n];++i)printf("%d ",res[x]),x=res[x],x+=b[x];
		printf("0\n");
	}
    return 0;
}