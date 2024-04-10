#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define MOD ((ll)1e9+7)
#define INF ((ll)1e15)

ll n,a,b;

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>a>>b;
	if(n>a*b)return cout<<-1,0;
	for(int i=0;i<a;i++)
	{
		ll p=i*b+1,q=1;
		if(i%2==1)p+=b-1,q=-1;
		for(int j=0;j<b;j++,p+=q)
			cout<<((p<=n)?p:0)<<" ";
		cout<<"\n";
	}
	return 0;
}