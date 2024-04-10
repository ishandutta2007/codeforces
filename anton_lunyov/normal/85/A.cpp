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

int main()
{
#ifdef XDEBUG
	freopen("a.in","r",stdin);
#endif
	int n,i,j;
	while(scanf("%d",&n)>0)
	{
		if(n==1) puts("a\na\nb\nb"); else
		{
			char a[4][111]={0};
			for(j=0;j<4;j++)
				for(i=0;i<n;i++)
					a[j][i]='a'+(i+(j>1))/2%2+2*j;
			a[3][0]=a[2][0];
			if(n%2==0) a[3][n-1]=a[2][n-1]; else
				a[1][n-1]=a[0][n-1];
			for(j=0;j<4;j++)
				puts(a[j]);
		}
	}
	return 0;
}