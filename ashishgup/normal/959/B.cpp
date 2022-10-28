#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, k, m;
int a[N];
string s[N];
map<string, int> store;

int32_t main()
{
	IOS;
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=k;i++)
	{
		int x;
		cin>>x;
		vector<int> v;
		int cost=1e9+5;
		for(int j=1;j<=x;j++)
		{
			int cur;
			cin>>cur;
			v.push_back(cur);
			cost=min(cost, a[cur]);
		}
		for(auto it:v)
		{
			a[it]=cost;
		}
	}
	for(int i=1;i<=n;i++)
	{
		store[s[i]]=a[i];
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		string str;
		cin>>str;
		ans+=store[str];
	}
	cout<<ans;
	return 0;
}