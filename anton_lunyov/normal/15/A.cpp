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

#define N 1111

int n,t;
int x[N],a[N];
int b[N];
int len;

void check(int y)
{
	for(int i=0;i<n;i++)
		if(abs(2*x[i]-y)<t+a[i]) return;
	b[len++]=y;
}

int main()
{
	//freopen("in.txt","r",stdin);
	while(scanf("%d%d",&n,&t)>0)
	{
		int i;
		for(i=0;i<n;i++) scanf("%d%d",&x[i],&a[i]);
		len=0;
		for(i=0;i<n;i++)
		{
			check(2*x[i]-a[i]-t);
			check(2*x[i]+a[i]+t);
		}
		sort(b,b+len);
		int ans=0;
		for(i=0;i<len;i++)
			if(i==0 || b[i-1]!=b[i]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}