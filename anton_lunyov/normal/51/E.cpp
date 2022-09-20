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
#define X first
#define Y second


#define N 707
int a[N][N];
int a2[N][N];
int a3[N][N];

int main()
{
	clock_t start=clock();
	//freopen("E.in","r",stdin);
	int n,m;
	//n=700;
	while(scanf("%d%d",&n,&m)>0)
	{
		fill(a,0);
		int i,j,k;
		while(m--)
		{
			scanf("%d%d",&i,&j);
			i--;j--;
			a[i][j]=a[j][i]=1;
		}
		//for(i=0;i<n;i++) for(j=0;j<i;j++) a[i][j]=a[j][i]=1;
		fill(a2,0);
		for(i=0;i<n;i++)
		{
			int *ai=a[i];
			for(k=0;k<n;k++) if(ai[k])
				for(j=i;j<n;j++)
					a2[i][j]+=a[k][j];
			for(j=i;j<n;j++) a2[j][i]=a2[i][j];
		}
		fill(a3,0);
		for(i=0;i<n;i++)
		{
			int *ai=a[i];
			for(k=0;k<n;k++) if(ai[k])
				for(j=i;j<n;j++)
					a3[i][j]+=a2[k][j];
			for(j=i;j<n;j++) a3[j][i]=a3[i][j];
		}
		LL ans=0;
		for(i=0;i<n;i++)
			for(k=0;k<n;k++)
				ans+=LL(a3[i][k])*a2[k][i];
		for(i=0;i<n;i++)
			ans-=5*a3[i][i];
		for(i=0;i<n;i++)
			ans-=5*LL(a3[i][i])*(a2[i][i]-2);
		printf("%I64d\n",ans/10);
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}