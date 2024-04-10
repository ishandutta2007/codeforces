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
const int mod=1e9+7;
using namespace std;
ll ny[60];
ll dp[60];
ll sum[60];

ll ksm(ll basic,ll x)
{
//	if(basic<0) cout<<"FUCK";
	ll res=1;
	while(x)
	{
		if(x&1)
		{
			res*=basic;
			res%=mod;
		}
		x>>=1;
		basic*=basic;
		basic%=mod;
	}
	return res;
}

ll calc(ll prime,ll e,ll k)
{
	for(int i=0;i<=e;i++)
	{
		dp[i]=ksm(prime,i);
//		cout<<"FUCK"<<ksm(prime,i)<<endl;
//		dp[i]%=mod;
	}
	sum[0]=dp[0];
	for(int i=1;i<=e;i++)
	{
		sum[i]=sum[i-1]+dp[i];
		sum[i]%=mod;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=e;j++)
		{
			dp[j]=sum[j]*ny[j+1];
			dp[j]%=mod;
		}
		sum[0]=dp[0];
		for(int j=1;j<=e;j++)
		{
			sum[j]=sum[j-1]+dp[j];
			sum[j]%=mod;
		}
	}
	return dp[e]%mod;
}

int main()
{
//	freopen("input.txt","r",stdin);
	for(int i=1;i<60;i++)
	{
		ny[i]=ksm(i,mod-2);
	}
	ll x,k;
	cin>>x>>k;
	ll tx=x;
	int s;
	ll res=1;
	for(ll i=2;i*i<=x;i++)
	{
		if(tx%i) continue;
		s=0;
		while(tx%i==0)
		{
			s++;
			tx/=i;
		}
//		cout<<i<<' '<<s<<' '<<k<<endl;
		res*=calc(i,s,k);
//		cout<<calc(i,s,k)<<endl;
		res%=mod;
	}
//	cout<<calc(2,1,4)<<endl;
	if(tx!=1)
	{
		res*=calc(tx,1,k);
		res%=mod;
	}
	cout<<res<<endl;
	return 0;
}