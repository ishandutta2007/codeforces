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

#define N 101010
int g[N];
int sg[N];

int main()
{
#ifdef XDEBUG
	freopen("c.in","r",stdin);
#endif
	int n,k,x;
	for(n=1;n<N;n++)
	{
		int mark[555]={0};
		for(k=2;k*(k+1)<=2*n;k++)
			if((2*n-k*(k+1))%(2*k)==0)
			{
				x=(2*n-k*(k+1))/(2*k);
				mark[sg[x+k]^sg[x]]=1;
			}
		for(k=0;mark[k];k++);
		g[n]=k;
		sg[n]=sg[n-1]^g[n];
	}
	while(scanf("%d",&n)>0)
	{
		if(!g[n]) puts("-1"); else
		{
			for(k=2;k*(k+1)<=2*n;k++)
				if(2*n%k==0 && (2*n-k*(k+1))%(2*k)==0)
				{
					x=(2*n-k*(k+1))/(2*k);
					if(sg[x+k]==sg[x]) break;
				}
			printf("%d\n",k);
		}
	}
	return 0;
}