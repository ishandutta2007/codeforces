#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)510)

ll n,m,k,dp[N][N];
ll tmp[N];
vector <ll> v;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		v.clear();
		string ex;
		cin>>ex;
		for(int j=0;j<m;j++)
			if(ex[j]=='1')
				v.push_back(j);
		for(int j=0;j<N;j++)tmp[j]=N,dp[i][j]=N*N;
		for(int p=0;p<v.size();p++)
			for(int q=p;q<v.size();q++)
				tmp[p+(ll)v.size()-1-q]=min(tmp[p+(ll)v.size()-1-q],v[q]-v[p]+1);
		tmp[v.size()]=0;
		for(int j=0;j<=k;j++)
			for(int p=0;p<=j;p++)
				dp[i][j]=min(dp[i][j],dp[i-1][j-p]+tmp[p]);
	}
	cout<<dp[n][k]<<"\n";
	return 0;
}