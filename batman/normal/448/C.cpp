#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[5500];
ifstream fin("input.txt");
ll solve(ll l,ll r,ll h)
{
	
	if(l>=r)
		return 0;
	if(l==r-1)
		return 1;	
	ll ans=0,mini=(ll)1e15,last=l;
	for(ll i=l;i<r;i++)
		mini=min(mini,a[i]);
	for(ll i=l;i<r;i++)
		if(a[i]==mini)
		{
			//if(l==n-3)
				//cout<<last<<" "<<solve(last,i,h+mini)<<" ";
			ans+=solve(last,i,mini),last=i+1;		
		}
	ans+=solve(last,r,mini);
	return min(ans+mini-h,r-l);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	cout<<solve(0,n,0);
    return 0;
}