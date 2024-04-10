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


typedef vector<int> VI;
typedef pair<int,int> PII;
typedef __int64 LL;

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
inline void MIN(LL &a,LL b){if(a>(b)) a=(b);}
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

#define N 2020

LL f[N];

int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	while(scanf("%d",&n)>0)
	{
		int t,c;
		int i,j,k;
		for(j=0;j<=n;j++) f[j]=LL(inf)*inf;
		f[0]=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&t,&c);
			for(k=n;k>=0;k--)
				MIN(f[min(k+t+1,n)],f[k]+c);
		}
		printf("%I64d\n",f[n]);
	}
	return 0;
}