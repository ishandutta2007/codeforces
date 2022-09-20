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

#define m 3

int main()
{
#ifdef XDEBUG
	freopen("b.in","r",stdin);
#endif
	int k[m],t[m];
	while(scanf("%d",k)>0)
	{
		int i;
		for(i=1;i<m;i++)
			scanf("%d",k+i);
		for(i=0;i<m;i++)
			scanf("%d",t+i);
		multiset<LL> free[m];
		int n;
		LL ans=0;
		for(scanf("%d",&n);n--;)
		{
			LL c;
			scanf("%I64d",&c);
			LL c0=c;
			for(i=0;i<m;i++)
			{
				if(k[i]>0)
				{
					c+=t[i];
					free[i].insert(c);
					k[i]--;
				}
				else
				{
					multiset<LL>::iterator it=free[i].begin();
					MAX(c,*it);
					c+=t[i];
					free[i].erase(it);
					free[i].insert(c);
				}
			}
			MAX(ans,c-c0);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}