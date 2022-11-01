#include <bits/stdc++.h>
using namespace std;
#define N (1001*1000)
#define ll long long
ll n,p,ans[N];
pair <ll,pair <ll,ll> > a[N];
bool mark[N];
int main()
{
    cin>>n;
    for(ll i=0;i<2*n;i++)
		for(ll j=0;j<i;j++)
		{
			cin>>a[p].first;
			a[p].second.first=i,a[p].second.second=j;
			p++;	
		}	
	sort(a,a+p);
	for(ll i=p-1;i>=0;i--)
	{
		if(!mark[a[i].second.second] && !mark[a[i].second.first])
			ans[a[i].second.first]=a[i].second.second,ans[a[i].second.second]=a[i].second.first,mark[a[i].second.second]=mark[a[i].second.first]=1;
	}
		
	for(ll i=0;i<2*n;i++)
		cout<<ans[i]+1<<" ";			
    return 0;
}