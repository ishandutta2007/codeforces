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
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
ll n,k;
ll a[300005];
ll dp[300005][3];
ll res=-inf;

void upd(ll &a,ll b)
{
	if(b>a) a=b;
	if(a>res)
	{
		res=b;
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",a+i);
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<3;j++)
		{
			dp[i][j]=-1LL*inf*inf;
		}
	}
	dp[0][0]=0;
	for(int i=0;i<n;i++)
	{
		upd(dp[i+1][0],0);
		upd(dp[i+1][0],dp[i][0]+a[i+1]);
		upd(dp[i+1][1],dp[i][0]+a[i+1]*k);
		upd(dp[i+1][2],dp[i][0]+a[i+1]);
		upd(dp[i+1][1],dp[i][1]+a[i+1]*k);
		upd(dp[i+1][2],dp[i][1]+a[i+1]);
		upd(dp[i+1][2],dp[i][2]+a[i+1]);
	}
	cout<<res<<endl;
	return 0;
}