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

//clock_t start=clock();
//fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));

char res[4][111]={"Carrots","Kiwis","Grapes","Waste"};

int main()
{
#ifdef MY_DEBUG
	freopen("b.in","r",stdin);
#endif
	int n,m,k,t;
	while(scanf("%d%d%d%d",&n,&m,&k,&t)>0)
	{
		int x[1111],y[1111];
		int i;
		for(i=0;i<k;i++)
		{
			scanf("%d%d",x+i,y+i);
			x[i]--;
			y[i]--;
		}
		while(t--)
		{
			int X,Y;
			scanf("%d%d",&X,&Y);
			X--;Y--;
			int num=m*X+Y;
			int cur=-1;
			for(i=0;i<k;i++)
			{
				if(mp(x[i],y[i])<mp(X,Y)) num--;
				if(x[i]==X && y[i]==Y)
					cur=3;
			}
			if(cur<0) cur=num%3;
			puts(res[cur]);
		}
	}
	return 0;
}