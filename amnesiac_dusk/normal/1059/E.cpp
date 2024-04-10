/*
 * Words like "tomorrow" or "future" or "fate"
 *		No matter how far they extend their hands
 *			We breathe, we dream, we raise our love
 *				In a timeless land that is far out of reach
 */
#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
//#define endl '\n'
#define pii pair<int,int>
#define pb push_back
#define int long long
typedef long long ll;
using namespace std;

const int N=100001;
vector<int> g[N];
int w[N];
int up[N][19];
ll dist[N][19];
ll dp[N];
void dfs(int at, int fr)
{
	up[at][0]=fr;
	for(int i=1; i<=18; i++)
		up[at][i]=up[up[at][i-1]][i-1];
	dist[at][0]=w[at];
	int te=at;
	int j=0;
	while(te!=1)
	{
		te=up[at][j];
		j++;
		dist[at][j]=dist[at][j-1]+dist[te][j-1];
	}
	j++;
	for(;j<=18; j++)
		dist[at][j]=dist[at][j-1];
	for(int i:g[at])
		dfs(i,at);
}
int ans=0;
int dfs(int at)
{
	int te=0;
	for(int i:g[at])
		te=max(te,dfs(i));
	if(te==0)
	{
		ans+=g[at].size();
		return dp[at]-1;
	}
	ans+=g[at].size()-1;
	return te-1;
}
signed main()
{
	IO;
	int n,s,l;
	cin>>n>>l>>s;
	for(int i=1; i<=n; i++)
	{
		cin>>w[i];
		if(w[i]>s)
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	int p;
	for(int i=2; i<=n; i++) {
		cin>>p;
		g[p].pb(i);
	}
	dfs(1,1);
	for(int i=1; i<=n; i++)
	{
		int lol=i;
		int dista=0;
		int uper=0;
		for(int j=18; j>=0; j--)
			if(dist[lol][j]&&dist[lol][j]+dista<=s)
			{
				dista+=dist[lol][j];
				lol=up[lol][j];
				uper+=(1<<j);
			}
		dp[i]=min(uper,l);
	}
	dfs(1);
	cout<<ans+1<<endl;
}