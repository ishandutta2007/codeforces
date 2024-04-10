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
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) {if(a>(b)) a=(b);}
#define MAX(a,b) {if(a<(b)) a=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

//clock_t start=clock();
//fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));

#define N 1010

int main()
{
#ifdef mydebug
	freopen("b.in","r",stdin);
#endif
	int n,k;
	while(scanf("%d%d",&n,&k)>0)
	{
		int b[N],p[N];
		int i,j,h;
		for(i=1;i<=n;i++)
			scanf("%d",b+i);
		int mark[N]={0};
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				if(!mark[j] && !b[j]) break;
			p[i]=j;
			for(h=j-k;h>0;h--)
				if(!mark[h]) b[h]--;
			mark[j]=1;
		}
		for(i=1;i<=n;i++)
			printf("%d%c",p[i],i<n?' ':'\n');
	}
	return 0;
}