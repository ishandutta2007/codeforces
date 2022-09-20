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

#define N 101010
int a[N];
LL s[N];

int main()
{
	//freopen("c.in","r",stdin);
	int n,i;
	while(scanf("%d",&n)>0)
	{
		s[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			s[i]=a[i]+s[i-1];
		}
		LL ans=s[n];
		LL mins=0;
		for(i=1;i<=n;i++)
		{
			MIN(mins,s[i]);
			MAX(ans,s[i]-s[n]+s[i]-2*mins);
		}
		printf("%d\n",int(ans));
	}
	return 0;
}