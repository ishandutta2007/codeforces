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

#define N 111

int main()
{
	//freopen("in.txt","r",stdin);
	int k,n;
	while(scanf("%d%d",&k,&n)>0)
	{
		int a[N][N]={0};
		int xc=(n+1)/2,yc=(n+1)/2;
		for(;k--;)
		{
			int m;
			scanf("%d",&m);
			int x,y,z,t;
			int ansx=0,ansy=0,ans=inf;
			for(x=1;x<=n;x++)
				for(y=1;y<=n;y=z)
					if(a[x][y]) z=y+1; else
					{
						for(z=y;z<=n && !a[x][z];z++);
						if(z-y>=m)
						{
							int cur=m*abs(x-xc);
							for(t=y;t<y+m;t++)
								cur+=abs(yc-t);
							for(;t<=z;t++)
							{
								if(ans>cur) ansx=x,ansy=t-m,ans=cur;
								cur+=abs(t-yc)-abs(yc-t+m);
							}
						}
					}
			if(ans==inf) puts("-1"); else
			{
				for(y=ansy;y<ansy+m;y++) a[ansx][y]=1;
				printf("%d %d %d\n",ansx,ansy,ansy+m-1);
			}
		}
	}
	return 0;
}