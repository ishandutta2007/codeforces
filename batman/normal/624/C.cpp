#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)
#define N (505)

ll n,m,ans[N],c[N],num[N];
bool a[N][N];
vector <ll> e[N];

void dfs(ll x)
{
	for(int i=0;i<e[x].size();i++)
	{
		if(!c[e[x][i]])
		{
			c[e[x][i]]=((c[x]==1)?2:1);
			dfs(e[x][i]);
		}
		else if(c[e[x][i]]==c[x])
		{
			cout<<"No";
			exit(0);
		}
	}
		
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		cin>>v>>u;
		a[v][u]=a[u][v]=1;
		num[v]++;num[u]++;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(!a[i][j] && i!=j)
				e[i].push_back(j);
				
	for(int i=1;i<=n;i++)
		if(!c[i] && num[i]!=n-1)
		{
			c[i]=1;
			dfs(i);
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			if(((c[i]==1 && c[j]==2) || (c[i]==2 && c[j]==1)) && a[i][j])
				return cout<<"No",0;	
	cout<<"Yes\n";
	for(int i=1;i<=n;i++)
		cout<<(((c[i]==0)?'b':((c[i]==1)?'a':'c')));
		
	return 0;
}