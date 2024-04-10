#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define endl "\n"
#define int long long

const int N=1005;

int n, m;
pair<int, int> p[2*N];
int vis[2*N], match[2*N];
vector<pair<int, int> > a, b;

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=2*n;i++)
	{
		cin>>p[i].first;
		p[i].second=i;
		b.push_back(p[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		match[u]=v;
		match[v]=u;
		a.push_back(p[u]);
		a.push_back(p[v]);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int t;
	cin>>t;
	int flipped=0;
	while(a.size())
	{
		if(t==2)
		{
			int cur;
			cin>>cur;
			vis[cur]=1;
			while(a.size() && vis[a.back().second])
				a.pop_back();
			if(match[cur] && !vis[match[cur]])
			{
				cout<<match[cur]<<endl;
				vis[match[cur]]=1;
				while(a.size() && vis[a.back().second])
					a.pop_back();
				continue;
			}
		}
		if(!a.size())
		{
			flipped=1;
			break;
		}
		int cur=a.back().second;
		a.pop_back();
		cout<<cur<<endl;
		vis[cur]=1;
		if(t==1)
		{
			int x;
			cin>>x;
			vis[x]=1;
		}
		while(a.size() && vis[a.back().second])
			a.pop_back();
	}
	while(b.size() && vis[b.back().second])
		b.pop_back();
	while(b.size())
	{
		if(t==2 && flipped==0)
		{
			int cur;
			cin>>cur;
			vis[cur]=1;
			while(b.size() && vis[b.back().second])
				b.pop_back();
			if(match[cur])
			{
				cout<<match[cur]<<endl;
				vis[match[cur]]=1;
				while(b.size() && vis[b.back().second])
					b.pop_back();
				continue;
			}
		}
		flipped=0;
		int cur=b.back().second;
		b.pop_back();
		cout<<cur<<endl;
		vis[cur]=1;
		if(t==1)
		{
			int x;
			cin>>x;
			vis[x]=1;
		}
		while(b.size() && vis[b.back().second])
			b.pop_back();
	}
	return 0;
}