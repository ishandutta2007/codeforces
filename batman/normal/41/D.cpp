#include <bits/stdc++.h>
using namespace std;
#define N (111)
#define K (11)
#define ll long long
#define INF ((ll)1e9)

ll n,m,k,dp[N][N][K],dir[N][N][K];
string s[N];
bool mark[N][N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	k++;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)for(int q=0;q<K;q++)dp[i][j][q]=-INF;
	for(int i=0;i<n;i++)
		cin>>s[i];	
	for(int i=0;i<m;i++)
		dp[n-1][i][(s[n-1][i]-'0')%k]=s[n-1][i]-'0';
	for(int i=n-2;i>=0;i--)
		for(int j=0;j<m;j++)
		{
			for(int q=0;q<k && j;q++)
				if(dp[i+1][j-1][(((q-(s[i][j]-'0'))%k)+k)%k]+(s[i][j]-'0')>dp[i][j][q])
					dp[i][j][q]=dp[i+1][j-1][(((q-(s[i][j]-'0'))%k)+k)%k]+(s[i][j]-'0'),dir[i][j][q]=1;	
			for(int q=0;q<k && j!=m-1;q++)
				if(dp[i+1][j+1][(((q-(s[i][j]-'0'))%k)+k)%k]+(s[i][j]-'0')>dp[i][j][q])
					dp[i][j][q]=dp[i+1][j+1][(((q-(s[i][j]-'0'))%k)+k)%k]+(s[i][j]-'0'),dir[i][j][q]=2;
		}	
	ll ans=-1,id;
	vector <char> res;	
	for(int i=0;i<m;i++)
		if(dp[0][i][0]>ans)
			ans=dp[0][i][0],id=i;	
	if(ans<0)return cout<<-1,0;
	cout<<ans<<"\n";
	for(int i=0,remain=0;i<n-1;i++)
	{
		ll r2=(((remain-(s[i][id]-'0'))%k)+k)%k;
		if(dir[i][id][remain]==1)
			res.push_back('R'),id--;
		else
			res.push_back('L'),id++;
		remain=r2;
	}
	cout<<id+1<<"\n";
	for(int i=n-2;i>=0;i--)
		cout<<res[i];
    return 0;
}