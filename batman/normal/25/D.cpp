#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;}return p;}
#define N (1010)
#define INF ((ll)1e16)
#define MOD ((ll)1e9+7)

ll n,e[N][N];
vector <ll> m;
vector <pair<ll,ll> > ans;
bool mark[N];

void dfs(ll x,ll par=0)
{
	mark[x]=1;
	for(int i=1;i<=n;i++)
		if(e[x][i] && i!=par)
		{
			if(mark[i]==1)
				while(e[x][i])
					ans.push_back({x,i}),e[x][i]--,e[i][x]--;
			if(!mark[i])dfs(i,x);		
		}
	
	mark[x]=2;
}

int main()
{
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v][u]++;e[u][v]++;
	}
	for(int i=1;i<=n;i++)
		if(!mark[i])
		{
			m.push_back(i);
			dfs(i);
		}
	cout<<(ll)ans.size()<<"\n";	
	for(int i=1;i<m.size();i++)
		cout<<ans[i-1].first<<" "<<ans[i-1].second<<" "<<m[0]<<" "<<m[i]<<"\n";	
    return 0;
}