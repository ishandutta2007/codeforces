#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[19];
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,n,i,j,k;
	for(cin>>T;T--;){
		cin>>n,j=1;k=0;
		for(i=1;i<=n;++i){
			cin>>a[i];
			while(a[i]%2==0)a[i]/=2,++k;
			}
		for(i=1;i<=n;++i)if(a[i]>a[j])j=i; 
		ll ans=a[j];
		while(k--)ans*=2;
		for(i=1;i<=n;++i)if(i!=j)ans+=a[i];
		cout<<ans<<'\n';
	}
	return 0;
}