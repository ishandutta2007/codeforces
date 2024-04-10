#include<bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define N (2111)
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}

ll n,m,k,d[N][N],d_last[N][N],ans,res1,res2;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fin>>n>>m>>k;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)d_last[i][j]=(ll)1e9;
	for(int i=0;i<k;i++)
	{
		ll x,y;
		fin>>x>>y;
		queue <pair <ll,ll> > q;
		for(int j=0;j<N;j++)for(int k=0;k<N;k++)d[j][k]=0;
		d[x][y]=1;
		d_last[x][y]=min(d_last[x][y],d[x][y]);
		q.push({x,y});
		while(q.size())
		{
			ll a=q.front().first,b=q.front().second;
			d_last[a][b]=min(d_last[a][b],d[a][b]);
			q.pop();
			if(a>1 && !d[a-1][b])d[a-1][b]=d[a][b]+1,q.push({a-1,b});
			if(a<n && !d[a+1][b])d[a+1][b]=d[a][b]+1,q.push({a+1,b});
			if(b>1 && !d[a][b-1])d[a][b-1]=d[a][b]+1,q.push({a,b-1});
			if(b<m && !d[a][b+1])d[a][b+1]=d[a][b]+1,q.push({a,b+1});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(ans<d_last[i][j])
				ans=d_last[i][j],res1=i,res2=j;
	fout<<res1<<" "<<res2;			
					
	return 0;
}