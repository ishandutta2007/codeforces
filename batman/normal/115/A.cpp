#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (2111)
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)

ll n,dis,ans;
bool killed[N];
vector <ll> e[N];

void dfs(ll x)
{
	killed[x]=1;
	dis++;
	ans=max(ans,dis);
	for(int i=0;i<e[x].size();i++)
		dfs(e[x][i]);
	dis--;	
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		ll x;
		cin>>x;
		if(x!=-1)
			e[x].push_back(i);
	}
	for(int i=1;i<=n;i++)
		if(!killed[i])
			dfs(i);
	cout<<ans;		
    return 0;
}