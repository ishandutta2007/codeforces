#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)16)
#define M ((ll)50)
#define INF ((ll)2e9+7)

ll k,t,a[N],dp[2][M],c[M][M];
char ans[M];

ll count(bool flg,ll x)
{
	memset(dp,0,sizeof dp);dp[0][0]=1;
	for(int i=N-1;i>=0;i--)
	{
		bool q=(i&1);
		for(int j=0;j<M;j++)dp[q][j]=dp[!q][j];
		for(int j=1;j<=a[i];j++)
			for(int p=j+(i==0 && flg);p<M;p++)
				dp[q][p]+=dp[!q][p-j]*c[p-(i==0 && flg)][j],dp[q][p]=min(dp[q][p],INF);
	}
	if(!flg)return dp[0][x];
	ll res=0;
	for(int i=1;i<=x;i++)res+=dp[0][i],res=min(res,INF);
	return res;
}

void solve(ll num,bool zero=1)
{
	if(num==0)return ;
	if(zero && count(1,num-1)>=k){ans[num-1]='.';solve(num-1,1);return ;}
	if(zero)k-=count(1,num-1);
	for(int i=zero;i<N;i++)
	{
		if(!a[i])continue;
		char p=(i+'0');
		if(i>9)p=((i-10)+'a');
		a[i]--;
		if(count(0,num-1)>=k)
		{
			ans[num-1]=p;
			solve(num-1,0);
			return ;
		}
		k-=count(0,num-1);a[i]++;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>k>>t;
	for(int i=0;i<M;i++)c[i][i]=c[i][0]=1;
	for(int i=1;i<M;i++)for(int j=1;j<i;j++)c[i][j]=min(INF,c[i-1][j]+c[i-1][j-1]);
	for(int i=0;i<N;i++)a[i]=t;
	solve(min(M,t*16));
	for(int i=min(M,t*16)-1;i>=0;i--)if(ans[i]!='.')cout<<ans[i];
	return 0;
}