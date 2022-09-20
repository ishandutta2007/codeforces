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
#ifdef MY_DEBUG
	freopen("a.in","r",stdin);
#endif
	int x,y;
	while(scanf("%d%d",&x,&y)>0)
	{
		int i;
		for(i=0;;i++)
		{
			int s=22;
			if(i%2==0)
			{
				int k=min(s/10,x);
				x-=k;
				s-=10*k;
				if(s>y) break;
				y-=s;
			}
			else
			{
				if(y>=22) y-=22; else
				if(y>=12 && x>=1) y-=12,x--; else
				if(y>=2 && x>=2) y-=2,x-=2; else break;
			}
		}
		puts(i%2?"Ciel":"Hanako");
	}
	return 0;
}