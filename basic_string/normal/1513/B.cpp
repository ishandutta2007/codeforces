#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3,P=1e9+7;
int a[N];
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n,i,j,k;
		cin>>n;
		for(i=1;i<=n;++i)cin>>a[i];
		j=a[1];
		for(i=2;i<=n;++i)j&=a[i];
		for(i=1;i<=n;++i)a[i]^=j;
		for(i=1,j=0;i<=n;++i)if(a[i]==0)++j;
		if(j<2)cout<<0<<'\n';
		else{
			for(i=n-2,k=1;i;--i)k=k*1ll*i%P;
			k=k*1ll*j%P*(j-1)%P;
			cout<<k<<'\n';
		}
	}
	return 0;
}