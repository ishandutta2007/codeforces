#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define INF ((ll)1e14)
#define MOD ((ll)1e9+7)

ll n,l,ans=1;
bool mark=0;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		ll a;
		cin>>a;
		if(a==1)
		{
			mark=1;
			if(l!=0)ans*=i-l;
			l=i;
		}
	}
	if(!mark)return cout<<0,0;
	cout<<ans;
    return 0;
}