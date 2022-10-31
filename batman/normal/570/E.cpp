#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll N =501;
const ll K=10100;
ifstream fin("input.txt");
ofstream fout("output.txt");

ll n,m,dp[2][N][N];
string s[N];



int main() 
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>s[i];
	ll l=(n+m-2)/2,r=(n+m-1)/2;
	if((n+m-2)%2==0)
	{
		r=(n+m-2)/2;
		for(int i=0;i<n;i++)
			dp[(l&1)][i][i]=1;	
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			ll i2=l-i,j=i,j2=r-j;
			if(s[i][i2]==s[j][j2])dp[(l&1)][i][j]=1;
			if(i<n-1)
			{
				j=i+1,j2=r-j;
				if(s[i][i2]==s[j][j2])dp[(l&1)][i][j]=1;
			}
		}
	}
	while(l>0)
	{
		l--,r++;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				dp[(l&1)][i][j]=0;
		for(int x=0;x<n;x++)
		{
			ll y=l-x;
			if(y<0 || y>=m)continue;
			for(int x2=0;x2<n;x2++)
			{
				ll y2=r-x2;
				if(y2<0 || y2>=m)continue;
				if(x2>=x && y2>=y && s[x][y]==s[x2][y2])
				{
					dp[(l&1)][x][x2]=dp[!(l&1)][x+1][x2]+dp[!(l&1)][x][x2]+dp[!(l&1)][x+1][x2-1]+dp[!(l&1)][x][x2-1];
					dp[(l&1)][x][x2]%=MOD;
				}
			}
		}
	}
	//cout<<dp[1][0][0]<<" "<<dp[1][1][1]<<"\n";
	cout<<dp[0][0][n-1];
	return 0;
}