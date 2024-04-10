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
		int ans=0,d;
		for(d=1;d<=n;d++)
		{
			int m=d;
			int k=0,i;
			for(i=2;i*i<=m;i++)
				if(m%i==0)
				{
					k++;
					for(;m%i==0;m/=i);
				}
			if(m>1) k++;
			if(k==2) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}