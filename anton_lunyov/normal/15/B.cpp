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

int main()
{
	//freopen("in.txt","r",stdin);
	int T;
	for(scanf("%d",&T);T--;)
	{
		LL n,m,x1,y1,x2,y2;
		scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&n,&m,&x1,&y1,&x2,&y2);
		if(x1>x2) swap(x1,x2);
		if(y1>y2) swap(y1,y2);
		int x=x2-x1;
		int y=y2-y1;
		LL ans=2*(n-x)*(m-y);
		if(x+1<=n-x && y+1<=m-y) ans-=(n-2*x)*(m-2*y);
		printf("%I64d\n",n*m-ans);
	}
	return 0;
}