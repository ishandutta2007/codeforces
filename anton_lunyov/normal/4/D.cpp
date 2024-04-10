#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

#define bit(n) (1<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef __int64 LL;

#define N 5555
int n;
int W,H;
int w[N],h[N];
int f[N];
int prev[N];

void dfs(int i)
{
	f[i]=1;
	for(int j=0;j<n;j++)
		if(w[i]<w[j] && h[i]<h[j])
		{
			if(!f[j]) dfs(j);
			if(f[i]<f[j]+1)
			{
				f[i]=f[j]+1;
				prev[i]=j;
			}
		}
}

int main()
{
	//freopen("in.txt","r",stdin);
	while(scanf("%d%d%d",&n,&W,&H)>0)
	{
		int i,j;
		for(i=0;i<n;i++)
			scanf("%d%d",&w[i],&h[i]);
		fill(f,0);
		int maxi=-1;
		for(i=0;i<n;i++)
		{
			if(!f[i]) dfs(i);
			if(W<w[i] && H<h[i] && (maxi<0 || f[maxi]<f[i])) maxi=i;
		}
		i=maxi;
		int m=maxi<0?0:f[i];
		printf("%d\n",m);
		for(j=0;j<m;j++)
		{
			printf("%d%c",i+1,j<m-1?' ':'\n');
			i=prev[i];
		}
	}
	return 0;
}