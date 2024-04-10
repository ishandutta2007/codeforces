#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (1111)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll n,p=0;
bool mark[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	mark[p]=1;
	for(int i=1;i<=100*1000;i++)
	{
		p+=i;
		p%=n;
		mark[p]=1;
	}
	bool ans=1;
	for(int i=0;i<n;i++)
		if(!mark[i])
			ans=0;
	cout<<((ans)?"YES":"NO");		
	
	
    return 0;
}