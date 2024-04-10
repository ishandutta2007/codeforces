#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int inv2=5e8+4;
typedef long long ll;
ll n,m;
int res;
int main(){
	cin>>n>>m;
	res=(n%mod)*(m%mod)%mod;
	for(ll l=1,r;l<=min(n,m);l=r+1)r=min(m,n/(n/l)),(res+=mod-((r+l)%mod)*((r-l+1)%mod)%mod*((n/l)%mod)%mod*inv2%mod)%=mod;
	cout<<res<<endl;
	return 0;
}