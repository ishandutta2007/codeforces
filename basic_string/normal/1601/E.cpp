#include<bits/stdc++.h>
using namespace std;
enum{N=300009,M=N*4};
using ll=long long;
int n,o,pos[N],a[N];
namespace ST{
	int lg[N],f[23][N];
	void mk(){
		int i,j,k,l;
		lg[0]=-1;
		for(i=1;i<=n;++i)cin>>f[0][i],lg[i]=lg[i>>1]+1;
		for(i=0;i<22;++i)
		for(j=1,k=(1<<i)+1,l=n-(1<<i+1)+1;j<=l;++j,++k)
			f[i+1][j]=min(f[i][j],f[i][k]);
	}
	int rmq(int l,int r){
		int i=lg[r-l+1];
		return min(f[i][l],f[i][r-(1<<i)+1]);
	}
}
int u,v,mn[M];
ll sr[M];
ll get(int k,int l,int r,int w){
	if(l==r)return min(w,mn[k]);
	int m=l+r>>1;
	if(mn[k*2]<w)return get(k*2,l,m,w)+sr[k];
	return w*1ll*(m-l+1)+get(k*2+1,m+1,r,w);
}
void bd(int k,int l,int r){
	if(l==r){mn[k]=a[l];return;}
	int m=l+r>>1;
	bd(k*2,l,m),bd(k*2+1,m+1,r),mn[k]=min(mn[k*2],mn[k*2+1]);
	sr[k]=get(k*2+1,m+1,r,mn[k*2]);
}
ll qry(int k,int l,int r,int&w){
	if(u<=l&&r<=v){
		ll s=get(k,l,r,w);
		return w=min(w,mn[k]),s;
	}
	int m=l+r>>1;
	if(u<=m&&m<v){
		ll s=qry(k*2,l,m,w);
		return s+qry(k*2+1,m+1,r,w);
	}
	return m<v?qry(k*2+1,m+1,r,w):qry(k*2,l,m,w);
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int q,i,j,lim,t=0;
	cin>>n>>q>>o,ST::mk();
	for(i=1;i<=o;++i){
		for(j=i+o-1;j<=n;j+=o)pos[j-o+1]=++t,a[t]=ST::rmq(j-o+1,j);
	}
	bd(1,1,t);
	while(q--){
		cin>>i>>j;
		u=pos[i+1],v=pos[i+1]+(j-i)/o-1;
		//cout<<u<<' '<<v<<'\n';
		if(u>v)cout<<ST::f[0][i]<<'\n';
		else lim=ST::f[0][i],cout<<ST::f[0][i]+qry(1,1,t,lim)<<'\n';
	}
	return 0;
}