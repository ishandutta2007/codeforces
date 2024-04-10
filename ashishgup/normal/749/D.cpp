#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, q;
int a[N], b[N];
vector<int> idx[N];
vector<pair<int, int> > v;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		idx[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(idx[i].size())
			v.push_back({idx[i].back(), i});
	}
	sort(v.begin(), v.end());
	cin>>q;
	while(q--)
	{
		int k;
		cin>>k;
		set<int> s;
		for(int i=1;i<=k;i++)
		{
			int x;
			cin>>x;
			s.insert(x);
		}
		int cur=v.size()-1;
		while(cur>=0 && s.find(v[cur].second)!=s.end())
			cur--;
		if(cur<0)
		{
			cout<<"0 0"<<endl;
			continue;
		}
		int person=v[cur].second;
		cur--;
		while(cur>=0 && s.find(v[cur].second)!=s.end())
			cur--;
		int to_search=(cur>=0)?v[cur].first:0;
		auto it=upper_bound(idx[person].begin(), idx[person].end(), to_search) - idx[person].begin();
		cout<<person<<" "<<b[idx[person][it]]<<endl;
	}
	return 0;
}