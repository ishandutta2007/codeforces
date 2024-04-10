#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, m;
int a[N], ans[N];
vector<pair<int, int> > v;

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		int t, r;
		cin>>t>>r;
		while(!v.empty() && v.back().first<=r)
			v.pop_back();
		v.push_back({r, t});
	}
	sort(a+1, a+v[0].first+1);
	for(int i=n;i>v[0].first;i--)
		ans[i]=a[i];
	v.push_back({0, 0});
	int l=1, r=v[0].first;
	for(int i=0;i+1<v.size();i++)
	{
		while(v[i].first > v[i+1].first)
		{
			if(v[i].second == 1)
				ans[v[i].first]=a[r--];
			else
				ans[v[i].first]=a[l++];
			v[i].first--;
		}
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}