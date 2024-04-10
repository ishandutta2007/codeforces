#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3e5+5;

int n;
int l[N], r[N];
pair<pair<int, int>, int> v[N];

bool comp(pair<pair<int, int>, int> &p1, pair<pair<int, int>, int> &p2)
{
	if(p1.first.first<p2.first.first)
		return true;
	if(p1.first.first>p2.first.first)
		return false;
	return p1.first.second>p2.first.second;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
		v[i].first.first=l[i];
		v[i].first.second=r[i];
		v[i].second=i;
	}
	sort(v+1, v+n+1, comp);
	set<pair<int, int> > s;
	for(int i=1;i<=n;i++)
	{
		int cur=v[i].first.second;
		pair<int, int> p= {cur, 0};
		auto it=s.lower_bound(p);
		if(it!=s.end())
		{
			cout<<v[i].second<<" "<<it->second;
			return 0;
		}
		s.insert({cur, v[i].second});
	}
	cout<<"-1 -1";
	return 0;
}