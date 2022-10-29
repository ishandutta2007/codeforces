#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

typedef long long ll;

const int N=1e5+5;

struct data
{
	int a,b,type;
};

int n, m;
int revbfs[N], vis[N], level[N], par[N], dp[N], usededges[N];
data edge[N];
vector< pair <int, int> > g[N];
map< pair<int, int>, int > edgeval;


int main()
{
    IOS;
   	cin>>n>>m;
   	for(int i=1;i<=m;i++)
   	{
   		cin>>edge[i].a>>edge[i].b>>edge[i].type;
   		g[edge[i].a].pb(mp(edge[i].b, i));
   		g[edge[i].b].pb(mp(edge[i].a, i));
   		pair<int, int> p={edge[i].a, edge[i].b};
   		edgeval[p]=i;
   		p={edge[i].b, edge[i].a};
   		edgeval[p]=i;
   	}
   	int s=n;
   	queue<int> q;
   	q.push(s);
   	vis[s]=1;
   	revbfs[n]=0;
   	while(!q.empty())
   	{
   		int k=q.front();
   		q.pop();
   		for(auto it:g[k])
   		{
   			if(!vis[it.ff])
   			{
   				q.push(it.ff);
   				vis[it.ff]=1;
   				revbfs[it.ff]=revbfs[k]+1;
   			}
   		}
   	}
   	memset(vis, 0, sizeof(vis));
   	s=1;
   	q.push(s);
   	vis[s]=1;
   	level[s]=0;
   	while(!q.empty())
   	{
   		int k=q.front();
   		q.pop();
   		for(auto it:g[k])
   		{
   			if(!vis[it.ff])
   			{
   				level[it.ff]=level[k]+1;
   				vis[it.ff]=1;
   				if(level[it.ff]+revbfs[it.ff]==revbfs[1])
   				{
   					q.push(it.ff);
   				}
   			}
   			if(level[it.ff]+revbfs[it.ff]==revbfs[1] && level[it.ff]>level[k])
   			{
   				if(edge[it.ss].type==1)
   				{
   					if(dp[k]+1>dp[it.ff])
   					{
   						par[it.ff]=k;
   						dp[it.ff]=dp[k]+1;
   					}
   					else if(par[it.ff]==0)
   					{
   						par[it.ff]=k;
   					}
   				}
   				else
   				{
   					if(dp[k]>dp[it.ff])
   					{
   						par[it.ff]=k;
   						dp[it.ff]=dp[k];
   					}
   					else if(par[it.ff]==0)
   					{
   						par[it.ff]=k;
   					}
   				}
   			}
   		}
   	}
   	vector<int> path;
   	int cur=n;
   	while(cur!=0)
   	{
   		path.pb(cur);
   		cur=par[cur];
   	}
   	reverse(path.begin(), path.end());
   	int sz=path.size();
   	for(int i=0;i<sz-1;i++)
   	{
   		int u=path[i];
   		int v=path[i+1];
   		pair<int, int> curpair={u,v};
   		int edgevalue=edgeval[curpair];
   		usededges[edgevalue]=1;
   	}
   	int ans1=0;
   	for(int i=1;i<=m;i++)
   	{
   		if(usededges[i])
   		{
   			if(edge[i].type==0)
   			{
   				ans1++;
   			}
   		}
   		else
   		{
   			if(edge[i].type==1)
   			{
   				ans1++;
   			}
   		}
   	}
   	cout<<ans1<<endl;
   	for(int i=1;i<=m;i++)
   	{
   		if(usededges[i])
   		{
   			if(edge[i].type==0)
   			{
   				cout<<edge[i].a<<" "<<edge[i].b<<" "<<!(edge[i].type)<<endl;
   			}
   		}
   		else
   		{
   			if(edge[i].type==1)
   			{
   				cout<<edge[i].a<<" "<<edge[i].b<<" "<<!(edge[i].type)<<endl;
   			}
   		}
   	}
    return 0;
}