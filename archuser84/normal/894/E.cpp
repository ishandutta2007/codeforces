#include <bits/stdc++.h>
#define ll long long
#define Loop(x,a,b) for(int x = a; x < b; x++)
using namespace std;
 
vector<pair<int, ll> > A[1000000];
vector<int> T[1000000];
int n,m;
 
bool visited[1000000]={0};
vector<int> DFSList;
void dfs(int u)
{
	visited[u]=true;
	Loop(i,0,A[u].size())
	{
		if(!visited[A[u][i].first])
		{
			dfs(A[u][i].first);
		}
	}
	DFSList.push_back(u);
}
 
int parent[1000000];
bool sccvis[1000000]={0};
void findSCC(int u,int P)
{
	sccvis[u]=true;
	parent[u] = P;
	Loop(i,0,T[u].size())
	{
		if(!sccvis[T[u][i]])
		{
			findSCC(T[u][i],P);
		}
	}
}
 
ll getMaxOfEdge(ll x)
{
	ll n;
	//n^2 + n - 2x <= 0
	ll delta = 1 + 8*x;
	n = (-1 + sqrt(delta)) / 2;
	return x*(n + 1) - n*(n + 1)*(n + 2) / 6;
}
 
ll Ans[1000000];
ll sumDag[1000000]={0};
vector<pair<int, ll> > dagAlis[1000000];
ll getAns(int u)
{
	if(Ans[u] != -1)
		return Ans[u];
	ll ans = 0;
	Loop(i,0,dagAlis[u].size())
	{
		int v = dagAlis[u][i].first;
		ll x = dagAlis[u][i].second + getAns(v); 
		if(x > ans)
			ans = x;
	}
	ans += sumDag[u];
	Ans[u] = ans;
	return ans;
}
 
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	Loop(i,0,m)
	{
		int u,v,w;
		cin >> u >> v >> w;
		A[u - 1].push_back({v-1,w});
		T[v - 1].push_back(u - 1);
	}
	int startin;
	cin >> startin;
	Loop(u,0,n)
	{
		if(!visited[u])
			dfs(u);
	}
	int dagsize = 0;
	while(DFSList.size() > 0)
	{
		int u = DFSList[DFSList.size()-1];
		DFSList.pop_back();
		if(!sccvis[u])
			findSCC(u,dagsize++);
	}
	Loop(u,0,n)
	{
		Loop(i,0,A[u].size())
		{
			int v = A[u][i].first;
			if(parent[u] == parent[v])
				sumDag[parent[u]] += getMaxOfEdge(A[u][i].second);
			else
			{
				dagAlis[parent[u]].push_back({parent[v], A[u][i].second});
			}
		}
	}
	memset(Ans,-1,8*1000000);
	cout << getAns(parent[startin - 1]) << endl;
}