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

#define N 505050
int x[N],v[N];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(scanf("%d",&n)>0)
	{
		for(i=0;i<n;i++)
			scanf("%d%d",&x[i],&v[i]);
		double L=0;
		double R=2e9;
		double T;
		for(int it=0;it<100;it++)
		{
			T=(L+R)/2;
			double maxx=-1e50;
			for(i=0;i<n;i++)
			{
				if(v[i]>0)
				{
					MAX(maxx,x[i]+v[i]*T);
				}
				else
				{
					if(maxx>x[i]+v[i]*T) break;
				}
			}
			if(i<n) R=T; else L=T;
		}
		if(T>1.5e9) puts("-1"); else
			printf("%.10lf\n",T);
	}
	return 0;
}