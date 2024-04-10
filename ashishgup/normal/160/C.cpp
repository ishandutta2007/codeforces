#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k;
int a[N], pref[N];
map<int, int> m;
vector<pair<int, int> > v;

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m[a[i]]++;
	}
	for(auto it:m)
		v.push_back(it);
	int sz=v.size();
	int reqd=k;
	for(int i=0;i<sz;i++)
	{
		pref[i+1]=pref[i]+v[i].second;
	}
	for(int i=0;i<sz;i++)
	{
		if(v[i].second*(pref[sz])<k)
		{
			k-=v[i].second*(pref[sz]);
			continue;
		}
		for(int j=0;j<sz;j++)
		{
			if(v[i].second*v[j].second>=k)
			{
				cout<<v[i].first<<" "<<v[j].first;
				return 0;
			}
			k-=v[i].second*v[j].second;
		}
	}
	return 0;
}