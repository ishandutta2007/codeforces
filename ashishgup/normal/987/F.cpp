#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N=(1LL<<22)+2;

int n, m;
int a[N];
bool vis[2][N]; //0 represents the auxilliary graph and 1 represents the actual graph
 
void dfs(int k, int cur)
{
	if(vis[cur][k])
		return;
	vis[cur][k]=1;
	if(cur==1) //Going from the actual graph to the auxilliary graph
		return dfs(k, cur^1);
	for(int i=0;i<n;i++)
	{
		if((k & (1LL<<i)) == 0)
			dfs(k | (1LL<<i), 0);
	}
	dfs(((1LL<<n)-1)^k, 1);
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=0;i<N;i++)
		vis[1][i]=1;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		vis[1][a[i]]=0; //For marking nodes not present in our current graph as visited
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		if(vis[1][a[i]])
			continue;
		ans++;
		dfs(a[i], 1);
	}
	cout<<ans;
	return 0;
} 

/*In the auxilliary graph, every number U has an edge to a number V if V can be made by changing
changing one 0 bit of U to 1, ie 0000 has edges to 1000, 0100, 0010 and 0001

If we can go from a node A to B in this graph, then we can say for sure that the bits
that are 1 in B are definitely 1 in A

For this problem, from a node U we want to reach a node V such that every bit that was 1 in U
is definitely 0 in V.

To achieve that, we map the nodes in such a way that while exiting, we compliment the number. 

That is, Actual(A) -> Aux(A) (Same as A) -> Aux(B) -> Actual(B) (Take complement of Aux(B))

Since Aux(B) is guaranteed to have is guaranteed to have As 1s as 1s, taking its complement
will ensure that all the 1s in A are 0s in Actual B*/