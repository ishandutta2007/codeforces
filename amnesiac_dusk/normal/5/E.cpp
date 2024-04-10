/*
 * Words like "tomorrow" or "future" or "fate"
 *		No matter how far they extend their hands
 *			We breathe, we dream, we raise our love
 *				In a timeless land that is far out of reach
 */
#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define pii pair<int,int>
typedef long long ll;
using namespace std;
int a[1000001],prem[1000001],pmax[1000001],same[1000001];
int main()
{
	IO;
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	rotate(a,max_element(a,a+n),a+n);
	a[n]=a[0];
	stack<pii> te;
	te.push({a[0]+1,-1});
	for(int i=0; i<n; i++)
	{
		while(!te.empty())
		{
			if(te.top().first>a[i])
				break;
			te.pop();
		}
		prem[i]=te.top().second;
		te.push({a[i],i});
	}
	while(!te.empty())
		te.pop();
	te.push({a[0]+1,-1});
	te.push({a[0],0});
	for(int i=n-1; i>=0; i--)
	{
		while(!te.empty())
		{
			if(te.top().first>a[i])
				break;
			te.pop();
		}
		pmax[i]=te.top().second;
		te.push({a[i],i});
	}
	while(!te.empty())
			te.pop();
	te.push({a[0]+1,-1});
	for(int i=0; i<=n; i++)
	{
		while(!te.empty())
		{
			if(te.top().first>=a[i])
				break;
			te.pop();
		}
		if(te.top().first==a[i])
			same[i]=same[te.top().second]+1;
		else
			same[i]=1;
		te.push({a[i],i});
	}
	ll ans=0;
	for(int i=0; i<n; i++)
	{
//		cout<<prem[i]<<" "<<pmax[i]<<" "<<same[i]<<endl;
		if(prem[i]!=-1)
			ans++;
		if(pmax[i]!=-1&&pmax[i]!=prem[i])
			ans++;
		ans+=same[i]-1;
	}
	cout<<ans<<endl;
}