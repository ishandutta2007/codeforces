
 #include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m;
int a[N], b[N];
queue<int> q;
vector<int> ans;
vector<int> g[N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!a[i])
			q.push(i);
	}
	while(!q.empty())
	{
		int k=q.front();
		q.pop();
		if(b[k]!=a[k])
			continue;
		ans.push_back(k);
		b[k]++;
		for(auto &it:g[k])
		{
			b[it]++;
			if(b[it]==a[it])
				q.push(it);
		}
	}
	cout<<ans.size()<<endl;
	for(auto &it:ans)
		cout<<it<<" ";
	return 0;
}