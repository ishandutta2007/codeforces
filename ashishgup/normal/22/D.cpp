#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
vector<int> v;
pair<int, int> a[N];
multiset<pair<int, int> > s;

bool comp(pair<int, int> &p1, pair<int, int> &p2)
{
	if(p1.first==p2.first)
		return p1.second>p2.second;
	return p1.first<p2.first;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first>>a[i].second;
		if(a[i].second<a[i].first)
			swap(a[i].first, a[i].second);
	}
	sort(a+1, a+n+1, comp);
	stack<pair<int, int> > st;
	for(int i=1;i<=n;i++)
	{	
		while(st.size() && st.top().first<=a[i].first&&st.top().second>=a[i].second)
			st.pop();
		st.push(a[i]);
	}
	while(!st.empty())
	{
		s.insert(st.top());
		st.pop();
	}
	while(!s.empty())
	{
		pair<int, int> p = *(s.begin());
		s.erase(s.begin());
		v.push_back(p.second);
		vector<pair<int, int> > del;
		for(auto it:s)
			if(p.second>=it.first && p.second<=it.second)
				del.push_back(it);
		for(auto it:del)
			s.erase(s.find(it));
	}
	cout<<v.size()<<endl;
	for(auto it:v)
		cout<<it<<" ";
	return 0;
}