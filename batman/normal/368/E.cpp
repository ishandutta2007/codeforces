#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll n,m,a[N];


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=0;i<m;i++)
	{
		ll b;
		cin>>b>>a[i];
	}
	sort(a,a+m);
	ll sum=a[m-1];
	for(ll i=m-2,j=2;i>=0;i--,j++)
	{
		ll p=((j%2)?(j*(j-1))/2+1:(j*j)/2);
		if(p>n)return cout<<sum,0;
		sum+=a[i];
	}
	cout<<sum;
    return 0;
}