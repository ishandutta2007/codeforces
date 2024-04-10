#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)
#define N (5500)

ll n,a[N],b[N],ans;
char c[N];


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>c[i]>>a[i]>>b[i];
	for(int i=1;i<=366;i++)
	{
		ll p=0,q=0;
		for(int j=0;j<n;j++)
			if(i>=a[j] && i<=b[j])
			{
				if(c[j]=='M')p++;
				else q++;
			}
		ans=max(ans,min(p,q));	
	}
	cout<<2*ans;
	return 0;
}