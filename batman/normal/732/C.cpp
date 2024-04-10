#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)1100)
#define INF ((ll)2e9)
#define MOD ((ll)1e9+7)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=b%2?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}


ll a[3];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	if(a[1]==a[2])return cout<<max(0ll,a[1]-1-a[0]),0;
	cout<<a[1]-a[0]+2*max(0ll,a[2]-1-a[1]);
	return 0;
}