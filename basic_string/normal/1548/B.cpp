#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
using ll=long long;
ll a[N],p[N];
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,n,i,l,r,m,s;
	ll w;
	for(cin>>T;T--;cout<<s+2<<'\n'){
		for(cin>>n,i=1,s=-1;i<=n;++i)cin>>a[i];
		for(i=r=1;i<n;++i)a[i]=a[i+1]-a[i];
		gg:;
		for(m=l=r,p[l+1]=w=0;l;--l)if((p[l]=gcd(p[l+1],a[l]))==1)break;
		if(r<n)for(++l;s=max(s,r-l),(++r)<n;){
			for(w=gcd(w,a[r]);l<=m&&gcd(p[l],w)==1;++l);
			if(l>m)goto gg;
		}
	}
	return 0;
}