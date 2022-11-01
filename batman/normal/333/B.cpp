#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)1010)


ll n,m,res;
bool mark[N][N],ans;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll x,y;
		cin>>x>>y;x--;y--;
		mark[x][y]=1;
	}
	for(int i=1;i<n-1;i++)
	{
		bool flg=0;
		for(int j=0;j<n;j++)
			flg|=mark[i][j];
		if(!flg)res++;
		if(n%2 && i==n/2 && !flg)ans=1;
	}
	for(int j=1;j<n-1;j++)
	{
		bool flg=0;
		for(int i=0;i<n;i++)
			flg|=mark[i][j];
		if(!flg)res++;
		if(n%2 && j==n/2 && !flg && ans)res--;
	}
	cout<<res<<"\n";
	return 0;
}