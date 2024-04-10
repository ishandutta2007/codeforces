#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
const ll mod = 998244353;

int T;
int n,a[N];
ll fac[N];
int main(){
	fac[0]=1;
	for(int i=1;i<N;++i)fac[i]=fac[i-1]*i%mod;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		if(a[n]-a[n-1]>1){
			puts("0");
			continue;
		}
		int cnt=0,cnt1=0;
		for(int i=1;i<=n;++i)
		if(a[i]==a[n])++cnt;
		else if(a[i]==a[n-1])++cnt1;
		ll ans=1;
		for(int i=1;i<=n;++i)ans=ans*i%mod;
		if(cnt>1){
			cout<<ans<<endl;
			continue;
		}
		else{
			ll res=1;
			for(int i=cnt1+2;i<=n;++i)res=res*i%mod;
			for(int i=1;i<=cnt1;++i)res=res*i%mod;
			cout<<(ans-res+mod)%mod<<endl;
		}
	}
}