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
ll a[1000005];
ll b[1000005];
const int mod=998244353;

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	a[2]=-1;
	a[3]=0;
	a[4]=2;
	a[5]=9;
	for(int i=6;i<=1000000;i++)
	{
		a[i]=a[i-1]*(i-2)+i-2;
		a[i]%=mod;
	}
	b[1]=1;
	for(int i=2;i<=1000000;i++)
	{
		b[i]=b[i-1]*i+a[i];
		b[i]%=mod;
	}
//	cout<<b[3];
	cin>>n;
	cout<<b[n]*n%mod<<endl;
//	int n;
//	cin>>n;
//	int a[10];
//	for(int i=0;i<n;i++)
//	{
//		a[i]=i+1;
//	}
//	do
//	{
//		for(int i=0;i<n;i++)
//		{
//			vec.push_back(a[i]);
//		}
//	}while(next_permutation(a,a+n));
////	for(int i=0;i<vec.size();i++)
////	{
////		cout<<vec[i]<<' ';
////	}
//	int res=0;
//	for(int i=0;i<vec.size()-n+1;i++)
//	{
//		int s=0;
////		set <int> squ;
//		for(int j=0;j<n;j++)
//		{
//			s+=vec[i+j];
//		}
//		if(s==n*(n+1)/2) res++;
//	}
//	cout<<res<<endl;
	return 0;
}