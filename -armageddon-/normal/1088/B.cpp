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
ll a[100005];

int main()
{
//	freopen("input.txt","r",stdin);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		scanf("%I64d",a+i);
	}
	sort(a,a+n);
	n=unique(a,a+n)-a;
	for(int i=n-1;i>=1;i--)
	{
		a[i]=a[i]-a[i-1];
	}
	for(int i=n;i<=k;i++)
	{
		a[i]=0;
	}
	for(int i=0;i<k;i++)
	{
		printf("%I64d\n",a[i]);
	}
	return 0;
}