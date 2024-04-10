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
	int a,b,n;
	while(scanf("%d%d%d",&a,&b,&n)>0)
	{
		if(a==0) puts(b?"No solution":"1"); else
		{
			if(b%a) puts("No solution"); else
			{
				b/=a;
				int i,x;
				if(b<0)
				{
					if(n%2==0) puts("No solution"); else
					{
						x=pow(-b,1./n)+eps;
						int y=1;
						for(i=0;i<n;i++)
							y*=x;
						if(-b!=y) puts("No solution"); else
							printf("%d\n",-x);
					}
				}
				else
				{
					x=pow(b,1./n)+eps;
					int y=1;
					for(i=0;i<n;i++)
						y*=x;
					if(b!=y) puts("No solution"); else
						printf("%d\n",x);
				}
			}
		}
	}
	return 0;
}