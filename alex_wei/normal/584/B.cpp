#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll ksm(ll a,ll b){
	ll s=1,m=a;
	while(b){
		if(b&1)s=s*m%mod;
		m=m*m%mod;
		b>>=1; 
	}
	return s;
}
int n;
int main()
{
	cin>>n;cout<<(ksm(27,n)-ksm(7,n)+mod)%mod<<endl;
    return 0;
}