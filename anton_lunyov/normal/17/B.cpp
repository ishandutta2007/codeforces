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
	int n;
	while(scanf("%d",&n)>0)
	{
		int i,u,v,c;
		for(i=0;i<n;i++) scanf("%*d");
		int m;
		scanf("%d",&m);
		int mine[1111];
		for(i=1;i<=n;i++) mine[i]=inf;
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&c);
			MIN(mine[v],c);
		};
		int num=0;
		int ans=0;
		for(i=1;i<=n;i++)
			if(mine[i]==inf) num++;
			else ans+=mine[i];
		if(num>1) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}