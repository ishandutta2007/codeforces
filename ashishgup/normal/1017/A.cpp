#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N], b[N], c[N], d[N];
pair<int, int> v[N];

bool comp(pair<int, int> &p1, pair<int, int> &p2)
{
	if(p1.first!=p2.first)
		return p1.first>p2.first;
	return p1.second<p2.second;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i]>>d[i];
		v[i].first=a[i]+b[i]+c[i]+d[i];
		v[i].second=i;	
	}
	sort(v+1, v+n+1, comp);
	for(int i=1;i<=n;i++)
	{
		if(v[i].second==1)
		{
			cout<<i;
			return 0;
		}
	}
	return 0;
}