#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

ll n,d,m;
ll a[N],r;
ll ans,s[N];

int main(){
	cin>>n>>d>>m;
	for(ll i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;++i)s[i]=s[i-1]+a[i];
	for(ll i=1;i<=n;++i)if(a[i]<=m)r=i;
	a[n+1]=2e9;
	for(ll i=0;i<=n-r;++i){
		ll c=max(i-1,0ll)*d;
		if(c>n-i)continue;
		ans=max(ans,s[n]-s[n-i]+max(0ll,s[r]-s[max(0ll,c-(n-i-r))]));
	}
	cout<<ans<<endl;
}