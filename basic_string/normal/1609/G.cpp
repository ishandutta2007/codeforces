#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=109,M=100009;
int n,m,q;
ll a[N],b[M],c[M];
struct FW{ 
ll a[M],b[M];
void add(int x,ll y){for(ll z=x*y;x<=m;x+=x&-x)a[x]+=y,b[x]+=z;}
ll sum(int x){ll u=0,v=0;for(int i=x;i;i-=i&-i)u+=a[i],v+=b[i];return(x+1)*u-v;}
int erf(ll x){
	int r=0,i=1<<18;
	for(;i;i>>=1)if(r+i<m&&a[r+i]<x)x-=a[r+=i];
	return r;
}
}T;
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int i,j,k,l,o,y,las;
	ll ans,sum=0; 
	cin>>n>>m>>q;
	for(i=1;i<=n;++i)cin>>a[i];
	for(i=1;i<=m;++i)cin>>b[i],sum+=b[i];
	for(i=1;i<m;++i)c[i]=b[i+1]-b[i];
	for(i=1;i<m;++i)T.add(i,c[i]-c[i-1]);
	while(q--){
		cin>>i>>j>>k;
		if(i==1){
			for(l=n-j+1,o=0;l<=n;++l)o+=k,a[l]+=o;
		}else{
			if(m==j)T.add(1,k),b[1]+=k;
			else T.add(m-j,k);
			sum+=(j+1ll)*j/2*k;
		}
		ans=0;las=1;
		for(i=1;i<n;++i){
			y=T.erf(a[i+1]-a[i])+1;
			y=min(y,m);
			ans+=a[i]*(y-las+1);
			ans+=T.sum(y-1)+b[1];
			las=y;
		}
		ans+=a[n]*(m-las+1);
		cout<<ans+sum<<'\n';
	}
	return 0;
}