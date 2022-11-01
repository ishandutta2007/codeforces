#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;}return p;}
#define N (301*1000)
#define INF ((ll)1e9)

ll n,a[N],mini=INF,first=-1,last,ans;
set <ll> s;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    	if(mini>a[i])mini=a[i];
	}
	for(ll i=0,p=0;i<n;i++)
	{
		if(a[i]==mini)
			p=0,last=i;
		else 
			p++;	
		if(a[i]==mini && first==-1)
			first=i;		
		ans=max(ans,p);	
	}
	cout<<mini*n+max(ans,first+n-last-1);
				
    return 0;
}