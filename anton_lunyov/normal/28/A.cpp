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

#define N 555

int main()
{
	//freopen("in.txt","r",stdin);
	int n,m;
	while(scanf("%d%d",&n,&m)>0)
	{
		int i,j,k;
		int x[N],y[N];
		for(i=0;i<n;i++)
			scanf("%d%d",x+i,y+i);
		int a[N];
		for(j=0;j<m;j++)
			scanf("%d",a+j);
		if(n%2){puts("NO");continue;}
		int ans[N];
		for(k=0;k<2;k++)
		{
			int mark[N]={0};
			for(i=0;i<n;i++) ans[i]=-1;
			for(i=k;i<n;i+=2)
			{
				int u=(i+1)%n;
				int v=(i+n-1)%n;
				int du=x[u]-x[i]?abs(x[u]-x[i]):abs(y[u]-y[i]);
				int dv=x[v]-x[i]?abs(x[v]-x[i]):abs(y[v]-y[i]);
				for(j=0;j<m;j++)
					if(!mark[j] && du+dv==a[j]) break;
				if(j==m) break;
				ans[i]=j+1;
				mark[j]=1;
			}
			if(i>=n) break;
		}
		puts(k<2?"YES":"NO");
		if(k<2) for(i=0;i<n;i++)
			printf("%d%c",ans[i],i<n-1?' ':'\n');
	}
	return 0;
}