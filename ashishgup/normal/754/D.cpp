#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define x first
#define y second

const int N=3e5+5;

int n, k, ans=-1, idx=0;
pair<pair<int, int>, int> a[N], b[N];
multiset<int> s, finans;

bool comp(pair<pair<int, int>, int> &p1, pair<pair<int, int>, int> &p2)
{
	if(p1.x.x==p2.x.x)
		return p1.x.y>p2.x.y;
	return p1.x.x<p2.x.x;
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x.x>>a[i].x.y;
		a[i].y=i;
	}
	sort(a+1, a+n+1, comp);
	set<pair<int, int> > s;
	for(int i=1;i<=n;i++)
	{
		while(s.size() && s.begin()->first<a[i].x.x)
			s.erase(s.begin());
		s.insert({a[i].x.y, a[i].y});
		while(s.size()>k)
			s.erase(s.begin());
		if(s.size()>=k)
		{
			if(s.begin()->first - a[i].x.x + 1 > ans)
			{
				ans=s.begin()->first - a[i].x.x + 1;
				idx=i;
			}
		}
	}
	s.clear();
	for(int i=1;i<=n;i++)
	{
		while(s.size() && s.begin()->first<a[i].x.x)
			s.erase(s.begin());
		s.insert({a[i].x.y, a[i].y});
		while(s.size()>k)
			s.erase(s.begin());
		if(idx==i)
		{
			int ctr=0;
			for(auto &it:s)
			{
				finans.insert(it.second);
				ctr++;
				if(ctr==k)
					break;
			}
			break;
		}
	}
	if(ans<=0)
	{
		ans=0;
		for(int i=1;i<=k;i++)
			finans.insert(i);
	}
	cout<<ans<<endl;
	for(auto &it:finans)
		cout<<it<<" ";
	return 0;
}