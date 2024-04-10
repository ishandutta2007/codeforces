#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define N (111)
#define ll long long
#define ld long double

ll n,m,p,g;
vector <ll> e[N],ans[N];
vector <vector <ll> > res[3];
bool mark[N];

void dfs(ll x)
{
	mark[x]=1;
	ans[g].push_back(x);
	p++;
	for(int i=0;i<e[x].size();i++)
		if(!mark[e[x][i]])
			dfs(e[x][i]);		
}

int main()
{ 
    //ios_base::sync_with_stdio(0);
    cin>>n>>m;
   	for(int i=0;i<m;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);  	
	}  
	for(int i=1;i<=n;i++)
		if(!mark[i])
		{
			g++;
			p=0;
			dfs(i);
			if(p>3)
				return cout<<-1,0;	
			res[p].push_back(ans[g]);	
		}
	if((res[1].size()-res[2].size())%3 || res[2].size()>res[1].size())
		return cout<<-1,0;	
	for(int i=0;i<res[3].size();i++,puts(""))
		for(int j=0;j<3;j++)			
			cout<<res[3][i][j]<<" ";
	for(int i=0;i<res[2].size();i++)
		cout<<res[2][i][0]<<" "<<res[2][i][1]<<" "<<res[1][i][0]<<"\n";	
	for(int i=res[2].size();i<res[1].size();i+=3)
		cout<<res[1][i][0]<<" "<<res[1][i+1][0]<<" "<<res[1][i+2][0]<<"\n";
    return 0;
}