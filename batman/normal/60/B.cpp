#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define N (15)
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;a;}return p;}

ll k,n,m,x,y,ans;
string s[N][N];
bool mark[N][N][N];

void dfs(ll a,ll b,ll c)
{
	if(a<0 || b<0 || c<0 || a>=k || b>=n || c>=m || s[a][b][c]!='.' || mark[a][b][c])
		return ;
	ans++;
	mark[a][b][c]=1;
	dfs(a-1,b,c);
	dfs(a+1,b,c);
	dfs(a,b+1,c);
	dfs(a,b-1,c);
	dfs(a,b,c+1);
	dfs(a,b,c-1);
		
}

int main()
{ 
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>k>>n>>m;
    for(int i=0;i<k;i++)
    	for(int j=0;j<n;j++)
    		cin>>s[i][j];
    cin>>x>>y;
	dfs(0,x-1,y-1);	
	cout<<ans;	
    return 0;
}