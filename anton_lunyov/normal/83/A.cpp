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

int a[111111];

int main()
{
#ifdef MY_DEBUG
	freopen("a.in","r",stdin);
#endif
	int n,i,j;
	while(scanf("%d",&n)>0)
	{
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		LL ans=0;
		for(i=0;i<n;i=j)
		{
			for(j=i;j<n && a[i]==a[j];j++);
			ans+=LL(j-i)*(j-i+1)/2;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}