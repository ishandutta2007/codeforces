#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;
 
int n, m;
int b[N], ans[N];
pair<int, int> a[N];
pair<pair<int, int>, int> diff[N];
set<pair<int, int> > s;

bool comp(pair<pair<int, int>, int> &p1, pair<pair<int, int>, int> &p2)
{
	if(p1.first.second==p2.first.second)
		return p1.first.first<p2.first.first;
	return p1.first.second<p2.first.second;
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first>>a[i].second;
		if(i>=2)
		{
			diff[i-1].first.first=a[i].first - a[i-1].second;
			diff[i-1].first.second=a[i].second - a[i-1].first;
			diff[i-1].second=i-1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		s.insert({b[i], i});
	}
	sort(diff+1, diff+n, comp);
	int idx=1;
	for(int i=1;i<=n-1;i++)
	{
		auto it=s.lower_bound({diff[i].first.first, 0});
		if(it==s.end() || it->first>diff[i].first.second)
		{
			cout<<"No";
			return 0;
		}
		ans[diff[i].second]=it->second;
		s.erase(it);
	}
	cout<<"Yes"<<endl;
	for(int i=1;i<=n-1;i++)
		cout<<ans[i]<<" ";
	return 0;    
}