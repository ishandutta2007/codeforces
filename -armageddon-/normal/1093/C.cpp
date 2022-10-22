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
ll a[200005];
ll ans[200005];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n/2;i++)
	{
		scanf("%I64d",a+i);
	}
	ll x=0,y=1LL*inf*inf;
	for(int i=0;i<n/2;i++)
	{
		ll t=a[i]-x;
//		cout<<t<<'\n'<<y<<endl;
		if(t>y)
		{
			t=y;
		}
		ans[i]=a[i]-t;
		ans[n-i-1]=t;
		x=ans[i];
		y=ans[n-i-1];
//		if(t<=now)
	}
	for(int i=0;i<n;i++)
	{
		printf("%I64d ",ans[i]);
	}
	return 0;
}