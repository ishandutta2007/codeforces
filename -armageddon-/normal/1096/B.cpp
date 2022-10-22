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
const int mod=998244353;
int suffix[200005];
int prefix[200005];
char c[200005];

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	scanf("%s",c);
	prefix[0]=c[0];
	int l=0,r=n-1;
	for(int i=1;i<n;i++)
	{
		prefix[i]=(prefix[i-1]!=c[i]?-1:c[i]);
//		cout<<prefix[i]<<endl;
		if(prefix[i]!=-1) l=i;
	}
	suffix[n-1]=c[n-1];
	for(int i=n-2;i>=0;i--)
	{
		suffix[i]=(suffix[i+1]!=c[i]?-1:c[i]);
		if(suffix[i]!=-1) r=i;
	}
	if(prefix[n-1]!=-1)
	{
		cout<<(1LL*n*(n+1)/2+1)%mod<<endl;
		return 0;
	}
//	cout<<l+2<<' '<<n-r<<endl;
	if(c[0]!=c[n-1])
	{
		cout<<l+1+n-r+2-1<<endl;
	}
	else
	{
		cout<<1LL*(l+2)*(n-r+1)%mod<<endl;
	}
	return 0;
}