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

#define N 55

double fac[N]={1.};

int main()
{
	//freopen("in.txt","r",stdin);
	int n,m;
	for(n=1;n<N;n++)
		fac[n]=n*fac[n-1];
	while(scanf("%d%d",&n,&m)>0)
	{
		int i,j,k,s,y;
		int a[N];
		for(i=0;i<m;i++) scanf("%d",a+i);
		double p[N];
		p[0]=0.;
		double M=0;
		for(k=1;k<=n;k++)
		{
			double f[N][N];
			f[m][0]=fac[n]/pow(1.*m,1.*n);
			for(s=1;s<=n;s++) f[m][s]=0;
			for(j=m-1;j>=0;j--)
				for(s=0;s<=n;s++)
				{
					f[j][s]=0;
					for(y=0;y<=s && y<=k*a[j];y++)
						f[j][s]+=f[j+1][s-y]/fac[y];
				}
			p[k]=f[0][n];
			M+=k*(p[k]-p[k-1]);
		}
		printf("%.10lf\n",M);
	}
	return 0;
}