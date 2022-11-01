#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (101*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll n,a[N],cnt[N],maxi,mini;
set <ll> s;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>a[0];
	maxi=a[0],mini=a[0];
	cnt[a[0]]++;
	s.insert(a[0]);
	ll ans=1;	
	for(int i=1,j=0;i<n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
		s.insert(a[i]);
		if(a[i]>maxi)
			maxi=a[i];
		if(a[i]<mini)
			mini=a[i];
		while(mini<maxi-1)
		{
			cnt[a[j]]--;
			if(cnt[a[j]]==0)
				s.erase(a[j]);
			if(cnt[a[j]]==0 && a[j]==maxi)
			{
				set <ll>::iterator it=s.end();
				it--;
				maxi=*it;
			}
			if(cnt[a[j]]==0 && a[j]==mini)
			{
				set <ll>::iterator it=s.begin();
				mini=*it;
			}
			j++;
		}	
		ans=max(ans,(ll)i-j+1);		
	}	
	cout<<ans;
    return 0;
}