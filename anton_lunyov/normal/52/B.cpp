#include <stdio.h>
#include <time.h>
#include <assert.h>
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

typedef __int64 LL;
typedef unsigned __int64 ULL;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
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
#define X first
#define Y second

//clock_t start=clock();
//fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));

#define N 1111
char a[N][N];
int r[N],c[N];

int main()
{
	//freopen("B.in","r",stdin);
	int n,m;
	while(scanf("%d%d",&n,&m)>0)
	{
		fill(r,0);
		fill(c,0);
		int i,j;
		for(i=0;i<n;i++)
		{
			scanf("%s",a[i]);
			for(j=0;j<m;j++)
				if(a[i][j]=='*')
					r[i]++,c[j]++;
		}
		LL ans=0;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(a[i][j]=='*') ans+=(r[i]-1)*(c[j]-1);
		printf("%I64d\n",ans);
	}
	return 0;
}