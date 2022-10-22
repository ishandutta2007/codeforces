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

void query(int x)
{
	cout<<'?'<<' '<<2*x<<' '<<x<<endl;
	fflush(stdout);
}

void solve()
{
	int now=1;
	char c;
	int l=1;
	int r=1e9;
	for(int i=0;i<29;i++)
	{
		query(1<<i);
		cin>>c;
		if(c=='y')
		{
			r=(1<<i)*2;
			break;
		}
	}
	int ans=0;
	int mid;
	while(l<=r)
	{
//		cout<<l<<'-'<<r<<endl;
		mid=l+r>>1;
		query(mid);
		cin>>c;
		if(c=='e') exit(0);
		if(c=='x')
		{
			l=mid+1;
			ans=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	if(2*(r+1)>2e9)
	{
		cout<<'!'<<' '<<1<<endl;
		fflush(stdout);
		return;
	}
	cout<<'?'<<' '<<2*(r+1)<<' '<<1<<endl;
	fflush(stdout);
	cin>>c;
	if(c=='e') exit(0);
	if(c=='x')
	{
		if(2*ans+1>1e9)
		{
			cout<<'!'<<' '<<1<<endl;
			fflush(stdout);
			return;
		}
		cout<<'!'<<' '<<2*ans+1<<endl;
		fflush(stdout);
	}
	else
	{
		if(2*ans+2>1e9)
		{
			cout<<'!'<<' '<<1<<endl;
			fflush(stdout);
			return;
		}
		cout<<'!'<<' '<<2*ans+2<<endl;
		fflush(stdout);
	}
	
}

int main()
{
//	freopen("input.txt","r",stdin);
	char t[105];
	while(true)
	{
		scanf("%s",t);
		if(t[0]=='e') break;
		if(t[0]=='m') exit(0);
		solve();
	}
	return 0;
}