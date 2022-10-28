#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, m, reqd, ans=0;
int a[N];
vector<int> g[N];

void work()
{
	vector<pair<int, int> > v;
	for(int i=0;i<=3*m-1;i++)
	{
		int cur=i%m;
		while(g[cur].size()>reqd)
		{  
			v.push_back({g[cur].back(), cur});
			g[cur].pop_back();
		}
		while(g[cur].size()<reqd && v.size()>0)
		{
			pair<int, int> p=v.back();
			v.pop_back();
			int inc=((cur-p.second+m)%m);
			ans+=inc;
			a[p.first]+=inc;
			g[cur].push_back(p.first);
		}
	}
}

int32_t main()
{
	IOS; 
	cin>>n>>m;
	reqd=n/m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		g[a[i]%m].push_back(i);
	}
	work();
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;   
}