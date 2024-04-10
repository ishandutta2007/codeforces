#include<bits/stdc++.h>
using namespace std;
enum{N=1000009,M=N*4};
int a[N],b[N];
namespace seg{
int m,t[M];
void upd(int x,int y,int k){
	int i;
	for(x+=m-1,y+=m+1;x^y^1;x>>=1,y>>=1){
		if(~x&1)t[x^1]+=k;
		if(y&1)t[y^1]+=k;
		i=min(t[x],t[x^1]),t[x]-=i,t[x^1]-=i,t[x>>1]+=i;
		i=min(t[y],t[y^1]),t[y]-=i,t[y^1]-=i,t[y>>1]+=i;
	}
	for(;x^1;x>>=1)i=min(t[x],t[x^1]),t[x]-=i,t[x^1]-=i,t[x>>1]+=i;
}
int qry(int x,int y){
	int u=1e8,v=u;
	for(x+=m-1,y+=m+1;u+=t[x],v+=t[y],x^y^1;x>>=1,y>>=1){
		if(~x&1)u=min(u,t[x^1]);
		if(y&1)v=min(v,t[y^1]);
	}
	for(u=min(u,v);x>>=1;)u+=t[x];
	return u;
}
void in(int n){
	m=(2<<__lg(n+1));
	memset(t,0,(n+1)*4*4);
}
}
struct P{
	int a,i;
	bool operator<(P x)const{return a<x.a;}
}p[N];
long long ans;
namespace cdq{
	int a[N],b[N];
void cdq(int l,int r){
	if(l==r)return;
	int m=l+r>>1,i=l,j=m+1,k=l;
	for(cdq(l,m),cdq(j,r);j<=r;ans+=i-l,b[k++]=a[j++])for(;i<=m&&a[i]<a[j];b[k++]=a[i++]);
	memcpy(b+k,a+i,(r-k+1)*4),memcpy(a+l,b+l,(r-l+1)*4);
}
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,n,m,i,j,k;
	for(cin>>T;T--;){
		cin>>n>>m,ans=0;
		for(i=1;i<=n;++i)cin>>a[i],cdq::a[i]=-a[i];
		cdq::cdq(1,n);
		for(i=1;i<=m;++i)cin>>b[i];
		seg::in(n+1);
		sort(b+1,b+m+1);
		for(i=1;i<=n;++i)seg::upd(i+1,n+1,1),p[i]={a[i],i};
		sort(p+1,p+n+1),j=k=1;
		for(i=1;i<=m;++i){
			while(j<=n&&p[j].a<=b[i])seg::upd(p[j].i+1,n+1,-1),++j;
			while(k<=n&&p[k].a<b[i])seg::upd(1,p[k].i,1),++k;
			ans+=seg::qry(1,n+1);
		}
		cout<<ans<<'\n';
	}
	return 0;
}