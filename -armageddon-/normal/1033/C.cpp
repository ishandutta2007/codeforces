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
int n;
int a[100005];
int dp[100005];
bool visit[100005];

bool dfs(int x)
{
	if(visit[x]) return dp[x];
	visit[x]=true;
	dp[x]=false;
	for(int i=x;i<n;i+=a[x])
	{
		if(a[i]<=a[x]) continue;
//		cout<<x<<' '<<i<<endl;
		dp[x]|=(dfs(i)==false);
	}
	for(int i=x;i>=0;i-=a[x])
	{
		if(a[i]<=a[x]) continue;
//		cout<<x<<' '<<i<<endl;
		dp[x]|=(dfs(i)==false);
	}
	return dp[x];
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=0;i<n;i++)
	{
		if(!visit[i]) dfs(i);
	}
	for(int i=0;i<n;i++)
	{
		if(dp[i]==false)
		{
			printf("B");
		}
		else
		{
			printf("A");
		}
	}
	return 0;
}