#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=205;

int t, n, m, u, v;
int deg[N], vis[N], in[N], out[N], viscircuit[N];
set< pair<int, int> > g[N];
vector<pair<int, int> > ans; 
vector<int> odd, circuit;

void EulerTour(int k) //Heirholzer's Algorithm
{
	int cur=k;
	stack<int> temake_pair;
	while(true)
	{
		int ct=g[cur].size();
		if(!ct)
		{
			viscircuit[cur]=1;
			circuit.push_back(cur);
			if(temake_pair.size()==0)
				break;
			cur=temake_pair.top();
			temake_pair.pop();
		}
		else
		{
			pair<int,int> next=*(g[cur].begin());
			g[cur].erase(next);
			g[next.first].erase(make_pair(cur,next.second));
			if(next.second==1)
			{
				in[next.first]++;
				out[cur]++;
				ans.push_back(make_pair(cur, next.first));
			}
			temake_pair.push(cur);
			cur=next.first;
		}
	}
}

void dfs(int k)
{
	if(vis[k])
		return;
	vis[k]=1;
	if(deg[k]&1)
		odd.push_back(k);
	for(auto it:g[k])
		dfs(it.first);
}

int32_t main()
{
	IOS;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			deg[i]=vis[i]=in[i]=out[i]=viscircuit[i]=0;
			g[i].clear();
			ans.clear();
			circuit.clear();
		}
		for(int i=1;i<=m;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].insert(make_pair(v, 1));
			g[v].insert(make_pair(u, 1));
			deg[u]++;
			deg[v]++;
		}	
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{	
				odd.clear();
				dfs(i);
				int sz=odd.size();
				for(int j=0;j<sz;j+=2)
				{
					int x=odd[j];
					int y=odd[j+1];
					deg[x]++;
					deg[y]++;
					g[x].insert(make_pair(y, 2));
					g[y].insert(make_pair(x, 2));
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(!viscircuit[i])
				EulerTour(i);
		}
		int counteven=0;
		for(int i=1;i<=n;i++)
		{
			if((in[i] + out[i])%2 == 0)
			{
				counteven++;
			}
		}
		cout<<counteven<<endl;
		/*for(auto it:circuit)
		{
			cout<<it<<" ";
		}*/
		for(auto it:ans)
		{
			cout<<it.first<<" "<<it.second<<endl;
		}
	}
	return 0;
}