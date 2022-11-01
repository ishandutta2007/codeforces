#include <bits/stdc++.h>
using namespace std;
#define INF ((ll)1e9)
#define N (1555)
#define ll int
#define ld long double
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;a;}return p;}

ll n,m,p,mlfe[N][N],dis[2],mmm[N*N][2];
string s[N];
bool mark[N][N],mm[N*N];
vector <pair <ll,ll> > e[N*N];


void dfs(ll x,ll y)
{
	if(x<0 || y<0 || x>=n || y>=m || mark[x][y] || s[x][y]=='#')
		return ;
	mark[x][y]=1;
	mlfe[x][y]=p;
	dfs(x,y+1),dfs(x,y-1),dfs(x+1,y),dfs(x-1,y);
	
}

void dfs2(ll x,ll y)
{
	if(x<0 || y<0 || x>=n || y>=m || mark[x][y] || s[x][y]=='#')
		return ;
	if(x==0 && s[n-1][y]!='#')
		e[mlfe[x][y]].push_back({mlfe[n-1][y],1});
	if(y==0 && s[x][m-1]!='#')
		e[mlfe[x][y]].push_back({mlfe[x][m-1],4});
	if(y==m-1 && s[x][0]!='#')
		e[mlfe[x][y]].push_back({mlfe[x][0],2});
	if(x==n-1 && s[0][y]!='#')
		e[mlfe[x][y]].push_back({mlfe[0][y],3});			
	mark[x][y]=1;
	dfs2(x,y+1),dfs2(x,y-1),dfs2(x+1,y),dfs2(x-1,y);
}

void dfs3(ll x)
{
	//cout<<x<<" "<<dir<<"\n";
	//cout<<x<<" "<<dis[0]<<" "<<dis[1]<<endl;
	if(mm[x] && (dis[0]!=mmm[x][0] || dis[1]!=mmm[x][1]))
	{
		
		//cout<<x<<" "<<dis[0]<<" "<<dis[1]<<" "<<mmm[x][0]<<" "<<mmm[x][1]<<endl;
		cout<<"Yes";
		exit(0);
	}
	if(mm[x])
		return ;
	mm[x]=1;
	ll p[2]={mmm[x][0],mmm[x][1]};
	mmm[x][0]=dis[0],mmm[x][1]=dis[1];
	for(int i=0;i<e[x].size();i++)
	{
		if(e[x][i].second==1)
			dis[0]++;
		if(e[x][i].second==3)
			dis[0]--;
		if(e[x][i].second==4)
			dis[1]++;
		if(e[x][i].second==2)
			dis[1]--;		
		dfs3(e[x][i].first);
		if(e[x][i].second==3)
			dis[0]++;
		if(e[x][i].second==1)
			dis[0]--;
		if(e[x][i].second==2)
			dis[1]++;
		if(e[x][i].second==4)
			dis[1]--;	
	}
	mmm[x][0]=p[0],mmm[x][1]=p[1];	
	mm[x]=0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    	cin>>s[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(s[i][j]!='#' && !mark[i][j])
			{
				dfs(i,j);
				p++;	
			}
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)mark[i][j]=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(s[i][j]!='#' && !mark[i][j])
				dfs2(i,j);
								
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(s[i][j]=='S')
			{
				dfs3(mlfe[i][j]);
				cout<<"NO";
				return 0;		
			}			
    return 0;
}