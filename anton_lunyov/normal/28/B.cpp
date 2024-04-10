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

#define N 111
int n;
int a[N][N];
int len[N];
int p[N];
int mark[N];
int cmp;

void add(int i,int j)
{
	a[i][len[i]++]=j;
	a[j][len[j]++]=i;
}

void dfs(int u)
{
	mark[u]=cmp;
	for(int i=0;i<len[u];i++)
	{
		int v=a[u][i];
		if(!mark[v]) dfs(v);
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	while(scanf("%d",&n)>0)
	{
		int i;
		for(i=1;i<=n;i++) scanf("%d",p+i);
		fill(len,0);
		for(i=1;i<=n;i++)
		{
			int di;
			scanf("%d",&di);
			if(i+di<=n) add(i,i+di);
			if(i-di>=1) add(i,i-di);
		}
		fill(mark,0);
		for(i=1;i<=n;i++)
			if(!mark[i])
			{
				cmp++;
				dfs(i);
			};
		for(i=1;i<=n && mark[i]==mark[p[i]];i++);
		puts(i<=n?"NO":"YES");
	}
	return 0;
}