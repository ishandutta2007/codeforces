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
	int a,b;
	while(scanf("%d%d",&a,&b)>0)
	{
		LL ans1=0,ans2=0;
		LL i,j;
		LL prev=0;
		for(i=a,j=b;;)
			if(i<j) ans1+=i-prev,prev=i,i+=a; else
			if(i>j) ans2+=j-prev,prev=j,j+=b; else
			{
				if(a<b) ans2+=j-prev; else ans1+=i-prev;
				break;
			}
		puts(ans1>ans2?"Dasha":
			ans1<ans2?"Masha":"Equal");
	}
	return 0;
}