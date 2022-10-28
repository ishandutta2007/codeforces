#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5005;

int n;
pair<int, int> a[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first>>a[i].second;
	}
	sort(a+1, a+n+1);
	int ans=0, day=0;
	for(int i=1;i<=n;i++)
	{
		if(min(a[i].first, a[i].second)>=day)
			day=min(a[i].first, a[i].second);
		else
			day=max(a[i].first, a[i].second);
	}
	cout<<day;
}