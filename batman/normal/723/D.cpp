#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)55)
#define INF ((ll)1e9+10)
#define MOD ((ll)1e9+7)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=b%2?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}

ll n,m,k,num,cnt;
bool mark[N][N];
bool flg;
string s[N];
vector <pair<ll,ll> > v[N*N];

bool cmp(vector <pair<ll,ll> > &x,vector <pair<ll,ll> > &y){return (ll)x.size()<(ll)y.size();}

void dfs(ll x,ll y)
{
	if(x==0 || y==0 || x==n-1 || y==m-1)flg=1;
	mark[x][y]=1;
	v[cnt].push_back({x,y});
	if(x-1>=0 && s[x-1][y]=='.' && !mark[x-1][y])dfs(x-1,y);
	
	if(y-1>=0 && s[x][y-1]=='.' && !mark[x][y-1])dfs(x,y-1);
	
	if(x+1<n && s[x+1][y]=='.' && !mark[x+1][y])dfs(x+1,y);
	
	if(y+1<m && s[x][y+1]=='.' && !mark[x][y+1])dfs(x,y+1);
}


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(!mark[i][j] && s[i][j]=='.')
			{
				flg=0;
				dfs(i,j);
				if(flg)
				{
					v[cnt].clear();
					cnt--;
				}
				cnt++;
			}
	sort(v,v+cnt,cmp);
	ll ans=0;
	for(int i=0;i<cnt-k;i++)
	{
		ans+=(ll)v[i].size();
		for(auto x:v[i])
			s[x.first][x.second]='*';
	}
	cout<<ans<<"\n";
	for(int i=0;i<n;i++)cout<<s[i]<<"\n";
	return 0;
}