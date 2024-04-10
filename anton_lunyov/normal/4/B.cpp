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
	int n,s;
	while(scanf("%d%d",&n,&s)>0)
	{
		int d=0;
		int i;
		int a[33],b[33];
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			s-=a[i];
			d+=b[i]-a[i];
		}
		if(0<=s && s<=d)
		{
			puts("YES");
			for(i=0;i<n;i++)
			{
				int cur=min(b[i]-a[i],s);
				s-=cur;
				printf("%d%c",a[i]+cur,i<n-1?' ':'\n');
			}
		}
		else puts("NO");

	}
	return 0;
}