#include<bits/stdc++.h>
using namespace std;
const int N=50009,M=N*33,P=1e9+7;
using ll=long long;
int a[N],c[M][2],sz[M],w[M][33],id=1,p[N];
void upd(int p,int x){
	++sz[p];
	for(int i=30;~i;--i)if(x>>i&1)++w[p][i];
}
void add(int x){for(int i=30,b,p=1;upd(p,x),~i;--i,p=c[p][b])if(b=x>>i&1,!c[p][b])c[p][b]=++id;}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,i,j,k,o,b,ans=0,kth=0;
	ll m,sum;
	cin>>n>>m,m*=2;
	for(i=1;i<=n;++i)cin>>a[i],add(a[i]),p[i]=1;
	for(i=30;~i;--i){
		sum=0;
		for(j=1;j<=n;++j)b=!(a[j]>>i&1),sum+=sz[c[p[j]][b]];
		if(sum<m){
			m-=sum;
			for(j=1;j<=n;++j){
				b=a[j]>>i&1,o=c[p[j]][!b];
				for(k=30;~k;--k)if(a[j]>>k&1)ans=(ans+(sz[o]-w[o][k])*1ll*(1<<k))%P;
				else ans=(ans+w[o][k]*1ll*(1<<k))%P;
				p[j]=c[p[j]][b];
			}
		}else{
			kth|=1<<i;
			for(j=1;j<=n;++j)b=!(a[j]>>i&1),p[j]=c[p[j]][b];
		}
	}
	ans=(ans+m%P*kth)%P;
	cout<<ans*1ll*(P+1>>1)%P;
	return 0;
}