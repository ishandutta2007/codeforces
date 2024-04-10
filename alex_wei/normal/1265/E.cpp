#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll ksm(ll a,ll b){
	ll ans=1,m=a;
	while(b){
		if(b&1)ans=ans*m%mod;
		m=m*m%mod;
		b>>=1;
	}
	return ans;
}
int n;
ll ans[200005],p[200005],inv;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	ans[0]=1;
	for(int i=1;i<=n;i++){
		ll pos=ksm(p[i],mod-2)*100%mod;
		ans[i]=(ans[i-1]*pos+1)%mod;
	}
	cout<<(ans[n]-1+mod)%mod<<endl;
    return 0;
}