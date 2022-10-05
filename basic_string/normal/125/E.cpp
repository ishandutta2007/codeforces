#include<bits/stdc++.h>
using namespace std;
const int N=5009,M=1e5+9,inf=5e8+3;
struct E{
	int u,v,w,i;
	bool operator<(E a)const{return w<a.w;}
}a[M],b[M];
int n,m,c,ta,tb,f[N],in[M];
long long ans;
bool ans2[M];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
bool add(const E&e){if(gf(e.u)!=gf(e.v))return f[f[e.u]]=e.v,1;return 0;}
bool add2(const E&e){if(gf(e.u)!=gf(e.v))return f[f[e.u]]=e.v,ans2[e.i]=1,1;return 0;}
int get(int x){
	int i,pa=1,pb=1,ca=0,cb=0;
	for(i=1,ans=0;i<=n;++i)f[i]=i;
	while(pa<=ta&&pb<=tb){
		if(a[pa].w-x<b[pb].w){if(add(a[pa]))ans+=a[pa].w-x,in[pa]=x,++ca;++pa;}
		else{if(add(b[pb]))ans+=b[pb].w,++cb;++pb;}
	}
	for(;pa<=ta;++pa)if(add(a[pa]))ans+=a[pa].w-x,in[pa]=x,++ca;
	for(;pb<=tb;++pb)if(add(b[pb]))ans+=b[pb].w,++cb;
	if(ca+cb<n-1)cout<<"-1",exit(0);
	return ca;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int m2,o,i,j,k,l=-inf,r=inf;
	cin>>n>>m>>c,m2=m;
	for(o=1;o<=m;++o)if(cin>>i>>j>>k,i==1||j==1)a[++ta]={i,j,k,o};else b[++tb]={i,j,k,o};
	sort(a+1,a+ta+1),sort(b+1,b+tb+1);
	while(l<=r){
		m=(l+r)/2;
		if(get(m)>c)r=m-1;else l=m+1;
	}
	k=get(r);
	if((r>=inf&&k<c)||r<=-inf)cout<<"-1",exit(0);
	cout<<n-1<<'\n';
	for(i=1;i<=n;++i)f[i]=i;
	for(i=1;i<=ta;++i)if(in[i]==r)add2(a[i]);
	int pa=1,pb=1;
	while(pa<=ta&&pb<=tb){
		if(a[pa].w-r<=b[pb].w&&k<c){if(add2(a[pa]))++k;++pa;}
		else add2(b[pb]),++pb;
	}
	for(;pa<=ta;++pa)add2(a[pa]);
	for(;pb<=tb;++pb)add2(b[pb]);
	for(i=1;i<=m2;++i)if(ans2[i])cout<<i<<' ';
}