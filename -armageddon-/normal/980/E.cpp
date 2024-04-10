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
typedef unsigned long long ull;
const int inf=103974182;
using namespace std;
int n,k;
vector <int> vec[1000005];
int depth[1000005];
int use[1000005];
int par[21][1000005];

void dfs(int x,int d,int p)
{
//	cout<<x<<' '<<d<<' '<<p<<endl;
	par[0][x]=p;
	depth[x]=d;
	for(int i=0;i<(int)vec[x].size();i++)
	{
		if(vec[x][i]==p) continue;
//		cout<<x<<' '<<d<<' '<<p<<endl;
		dfs(vec[x][i],d+1,x);
	}
}

int get(int x)
{
	if(use[x]) return -1;
	for(int i=20;i>=0;i--)
	{
		if(par[i][x]==-1 || use[par[i][x]]) continue;
		x=par[i][x];
	}
	return x;
}

void init()
{
	for(int k=1;k<=20;k++)
	{
		for(int i=0;i<n;i++)
		{
			par[k][i]=(par[k-1][i]==-1?-1:par[k-1][par[k-1][i]]);
		}
	}
}

void color(int l,int r)
{
	r=par[0][r];
	for(int i=l;i!=r;i=par[0][i])
	{
		use[i]=true;
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	int x,y;
	for(int i=0;i<n-1;i++)
	{
		cin>>x>>y;
		x--;
		y--;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	dfs(n-1,0,-1);
	init();
	k=n-k-1;
	use[n-1]=true;
	for(int i=n-2;i>=0;i--)
	{
//		cout<<i+1<<'-'<<x+1<<endl;
		int x=get(i);
		if(x==-1) continue;
		if(depth[i]-depth[x]+1<=k)
		{
			k-=depth[i]-depth[x]+1;
			color(i,x);
		}
	}
	for(int i=0;i<n;i++)
	{
	    if(!use[i])
	    {
	        cout<<i+1<<' ';
	    }
	}
	cout<<endl;
	return 0;
}