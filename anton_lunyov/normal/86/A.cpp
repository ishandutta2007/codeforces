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

#define N 12

int main()
{
#ifdef XDEBUG
	freopen("a.in","r",stdin);
#endif
	LL p[N]={1};
	int n;
	for(n=1;n<N;n++)
		p[n]=10*p[n-1];
	LL l,r;
	while(scanf("%I64d%I64d",&l,&r)>0)
	{
		LL ans=0;
		for(n=1;n<N;n++)
		{
			LL L=max(l,p[n-1]);
			LL R=min(r,p[n]-1);
			if(L>R) continue;
			LL M=(p[n]-1)/2;
			if(L<=M && M<=R)
				MAX(ans,M*(p[n]-1-M));
			M++;
			if(L<=M && M<=R)
				MAX(ans,M*(p[n]-1-M));
			MAX(ans,L*(p[n]-1-L));
			MAX(ans,R*(p[n]-1-R));
		}
		printf("%I64d\n",ans);
	}
	return 0;
}