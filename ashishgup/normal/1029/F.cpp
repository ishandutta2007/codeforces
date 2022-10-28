#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3e5+5;

int a, b, area, ans=1e18;
vector<pair<int, int> > p, q;
vector<int> v1, v2;
vector<int> pref1, pref2;

int32_t main()
{
	IOS;
	cin>>a>>b;
	area=a+b;
	for(int i=1;i*i<=a;i++)
	{
		if(a%i!=0)
			continue;
		p.push_back({i, a/i});
		if(i!=a/i)
			p.push_back({a/i, i});
	}
	for(int i=1;i*i<=b;i++)
	{
		if(b%i!=0)
			continue;
		q.push_back({i, b/i});
		if(i!=b/i)
			q.push_back({b/i, i});
	}
	sort(p.begin(), p.end());
	sort(q.begin(), q.end());
	pref1.push_back(p[0].second);
	pref2.push_back(q[0].second);
	for(auto &it:p)
		v1.push_back(it.first);
	for(auto &it:q)
		v2.push_back(it.first);
	for(int i=1;i<p.size();i++)
	{
		int cur=pref1[i-1];
		cur=min(cur, p[i].second);
		pref1.push_back(cur);
	}
	for(int i=1;i<q.size();i++)
	{
		int cur=pref2[i-1];
		cur=min(cur, q[i].second);
		pref2.push_back(cur);
	}
	for(int i=1;i*i<=area;i++)
	{
		if(area%i!=0)
			continue;
		int n=i, m=area/i;
		bool check=0;
		int idx=upper_bound(v1.begin(), v1.end(), n) - v1.begin() - 1;
		if(pref1[idx]<=m)
			check=1;
		idx=upper_bound(v2.begin(), v2.end(), n) - v2.begin() - 1;
		if(pref2[idx]<=m)
			check=1;
		if(check)
			ans=min(ans, 2*n + 2*m);
	}
	cout<<ans;
	return 0;
}