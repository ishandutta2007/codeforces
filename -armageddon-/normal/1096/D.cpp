#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cinng(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfng(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int id[256];
ll dp[100005][5];
int cost[100005];
int n;
char c[100005];

int main()
{
//	freopen("input.txt","r",stdin);
	memset(id,-1,sizeof(id));
	id['h']=1;
	id['a']=2;
	id['r']=3;
	id['d']=4;
	cin>>n;
	scanf("%s",c+1);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",cost+i);
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=4;j++)
		{
			if(id[c[i+1]]==-1)
			{
				dp[i+1][j]=dp[i][j];
			}
			else
			{
				if(id[c[i+1]]==j+1)
				{
//					cout<<i<<' '<<j<<' '<<"FCK";
					dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
					dp[i+1][j]=min(dp[i+1][j],dp[i][j]+cost[i+1]);
				}
				else
				{
					dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
				}
			}
		}
//		for(int mask=0;mask<(1<<4);mask++)
//		{
//			if(id[c[i+1]]==-1) dp[i+1][mask]=dp[i][mask];
//			else
//			{
//				dp[i+1][mask|(1<<id[c[i+1]])]=min(dp[i+1][mask|(1<<id[c[i+1]])],dp[i][mask]);
//				dp[i+1][mask]=min(dp[i+1][mask],dp[i][mask]+cost[i+1]);
//			}
//		}
	}
	ll res=1LL*inf*inf;
	for(int mask=0;mask<4;mask++)
	{
//		cout<<dp[n][mask]<<' ';
		res=min(dp[n][mask],res);
	}
	cout<<res<<endl;
//	for(int i=1;i<=n;i++)
//	{
//		for(int mask=0;mask<=4;mask++)
//		{
//			cout<<dp[i][mask]<<' ';
//		}
//		cout<<endl;
//	}
//	cout<<dp[n][0]<<endl;
	return 0;
}