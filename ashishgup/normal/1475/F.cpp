//Trying to screencast

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 1005;
 
struct TwoSAT
{
	static const int MAXV = 4005;

	int n, cnt;
	vector<int> g[MAXV], rg[MAXV]; //g=forward, rg=backward
	bool vis[MAXV];
	int order[MAXV], comp[MAXV];

	void init(int curn)
	{
		n=curn;
		for(int i=0;i<n;i++)
		{	
			g[i].clear();
			rg[i].clear();
		}
	}

	void add(int u, int v)
	{
		g[u].push_back(v);
		rg[v].push_back(u);
	}

	void dfs1(int u)
	{
		vis[u] = true;
		for(auto it:g[u])
			if(!vis[it])
				dfs1(it);
		order[cnt++] = u;
	}

	void dfs2(int u, int c)
	{
		comp[u] = c;
		for(auto it:rg[u])
			if(comp[it]==-1)
				dfs2(it, c);
	}

	int solve(vector<int> &ans)
	{
		cnt=0;
		memset(vis, 0, sizeof(vis));
		for(int i=0;i<n;i++)
			if(!vis[i])
				dfs1(i);
		memset(comp, -1, sizeof(comp));
		int grp=0;
		for(int i=n-1;i>=0;i--)
		{
			int u=order[i];
			if(comp[u] == -1)
				dfs2(u, grp++);
		}

		for(int i=0;i<n;i+=2)
			if(comp[i]==comp[i^1])
				return 0;

		ans.clear();

		for(int i=0;i<n;i+=2)
		{
			int choose = (comp[i] > comp[i^1]) ? i : (i^1);
			ans.push_back(choose);
		}
		return 1;
	}
};

int n;
char a[N][N], b[N][N];

void addEdge(TwoSAT &twosat, int u, int v, int c)
{
	int u0=2*(u-1), u1=2*(u-1) + 1; //0 = Unchanged, 1 = Changed
	int v0=2*(v-1), v1=2*(v-1) + 1; //0 = Unchanged, 1 = Changed
 
	if(c==1)
	{
		twosat.add(u0, v1);
		twosat.add(u1, v0);
		twosat.add(v0, u1);
		twosat.add(v1, u0);
	}
 
	else
	{
		twosat.add(u0, v0);
		twosat.add(u1, v1);
		twosat.add(v0, u0);
		twosat.add(v1, u1);
	}
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				cin >> a[i][j];
		TwoSAT twosat;
		twosat.init(2 * n);
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				cin >> b[i][j];
				if(a[i][j] == b[i][j])
					addEdge(twosat, i, j + n, 0);
				else
					addEdge(twosat, i, j + n, 1);
			}
		}
		vector<int> ans;
		if(twosat.solve(ans))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}