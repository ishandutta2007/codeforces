#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)
#define N (110)

ll w,h,n,p;
vector <pair<ll,ll> > e[N][N];
vector <ll> ans;
bool mark[N][N];

void dfs(ll x,ll y)
{
	p++;
	mark[x][y]=1;
	for(int i=-1;i<=1;i++)
		for(int j=-1;j<=1;j++)
			if((i==0 ^ j==0) && x+i>=0 && x+i<w && y+j>=0 && y+j<h && !mark[x+i][y+j])
			{
				ll m=1;
				for(int q=0;q<e[x][y].size();q++)
					if(e[x][y][q].first==x+i && e[x][y][q].second==y+j)
						m=0;
				if(m)dfs(x+i,y+j);
			}
				
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>w>>h>>n;
	for(int i=0;i<n;i++)
	{
		ll x,y,x2,y2;
		cin>>x>>y>>x2>>y2;
		if(x==x2 && x!=0 && x!=w)
			for(int j=y;j<y2;j++)
				e[x-1][j].push_back({x,j}),e[x][j].push_back({x-1,j});
		if(y==y2 && y!=0 && y!=h)
			for(int j=x;j<x2;j++)
				e[j][y-1].push_back({j,y}),e[j][y].push_back({j,y-1});		
	}
	
	for(int i=0;i<w;i++)
		for(int j=0;j<h;j++)
			if(!mark[i][j])
			{
				p=0;
				dfs(i,j);
				ans.push_back(p);
			}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";	
	return 0;
}