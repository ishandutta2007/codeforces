#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll n,m,ans;
ll ksm(ll a,ll b){ll m=a,s=1;while(b){if(b&1)s=s*m%mod;b>>=1,m=m*m%mod;}return s;}
int main()
{
	cin>>n>>m;
	cout<<ksm(ksm(2,m)-1,n);
    return 0;
}