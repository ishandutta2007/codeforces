#include<bits/stdc++.h>
using namespace std;
#define ll long long
map <ll,ll> x,y,e;
ll n,ans,p,q,m=1e9+5;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>p>>q,ans+=x[p]+y[q]-e[p*m+q],x[p]++,y[q]++,e[p*m+q]++;
	cout<<ans;
	return 0;
}