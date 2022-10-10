#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define int long long
#define MIN LLONG_MIN
#define MAX LLONG_MAX
#define PB push_back
#define N 200001
#define MX 262144
#define LG 17
#define M 1000000007
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define LD long double
#define F first
#define S second
#define endl "\n"

/*https://github.com/Ashishgup1/Competitive-Coding/blob/master/Matching%20(Hopcroft-Karp)%20in%20Bipartite%20Graph.cpp*/
struct Hopcroft_Karp
{
	static const int inf = 1e9;

	int n;
	vector<int> matchL, matchR, dist;
	vector<vector<int> > g;

	Hopcroft_Karp(int n) :
		n(n), matchL(n+1), matchR(n+1), dist(n+1), g(n+1) {}

	void addEdge(int u, int v)
	{
		g[u].push_back(v);
	}

	bool bfs()
	{
		queue<int> q;
		for(int u=1;u<=n;u++)
		{
			if(!matchL[u])
			{
				dist[u]=0;
				q.push(u);
			}
			else
				dist[u]=inf;
		}
		dist[0]=inf;

		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(auto v:g[u])
			{
				if(dist[matchR[v]] == inf)
				{
					dist[matchR[v]] = dist[u] + 1;
					q.push(matchR[v]);
				}
			}
		}

		return (dist[0]!=inf);
	}

	bool dfs(int u)
	{
		if(!u)
			return true;
		for(auto v:g[u])
		{
			if(dist[matchR[v]] == dist[u]+1 &&dfs(matchR[v]))
			{
				matchL[u]=v;
				matchR[v]=u;
				return true;
			}
		}
		dist[u]=inf;
		return false;
	}

	int max_matching()
	{
		int matching=0;
		while(bfs())
		{
			for(int u=1;u<=n;u++)
			{
				if(!matchL[u])
					if(dfs(u))
						matching++;
			}
		}
		return matching;
	}
};


int32_t main()
{
    LL i,j,lt,z,v,c,r,l,t1,k,h,u,q,ts,te,x,y,n,m,s,b;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    LL dist[n+1][n+1];
    for(i=1;i<=n;i++)
    	for(j=1;j<=n;j++)
    		if(i==j)
    			dist[i][j]=0;
    		else
    			dist[i][j]=1e9;
    for(i=1;i<=m;i++)
    {
    	cin>>x>>y;
    	if(x==y)
    	{
    		// cout<<"wtf\n";
    		continue;
    	}
    	dist[x][y]=1;
    	dist[y][x]=1;
    }
    for(k=1;k<=n;k++)
    	for(i=1;i<=n;i++)
    		for(j=1;j<=n;j++)
    			dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    // for(i=1;i<=n;i++)
    // {
    // 	for(j=1;j<=n;j++)
    // 		cout<<dist[i][j]<<" ";
    // 	cout<<endl;
    // }
    cin>>s>>b>>k>>h;
    LL lcs[s+1],lcb[b+1],a[s+1],d[b+1],fl[s+1];
    for(i=1;i<=s;i++)
    	cin>>lcs[i]>>a[i]>>fl[i];
    for(i=1;i<=b;i++)
    	cin>>lcb[i]>>d[i];
    Hopcroft_Karp match(max(s,b));
    for(i=1;i<=s;i++)
    	for(j=1;j<=b;j++)
    	{
    		x=lcs[i];
    		y=lcb[j];
    		if(a[i]>=d[j]&&fl[i]>=dist[x][y])
    		{
    			// cout<<i<<" "<<j<<endl;
    			match.addEdge(i,j);
    		}
    	}
    z=match.max_matching();
    // cout<<z<<endl;
    cout<<min(s*h,k*z);
}