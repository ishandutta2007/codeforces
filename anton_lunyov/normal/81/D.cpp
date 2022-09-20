#include <stdio.h>
#include <time.h>
#include <assert.h>
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

typedef __int64 LL;
typedef unsigned __int64 ULL;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) {if(a>(b)) a=(b);}
#define MAX(a,b) {if(a<(b)) a=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

//clock_t start=clock();
//fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));

int main()
{
#ifdef MY_DEBUG
	freopen("d.in","r",stdin);
#endif
	int m,n;
	while(scanf("%d%d",&m,&n)>0)
	{
		int i,j;
		int a[44];
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		int maxi=0;
		for(i=0;i<n;i++)
			if(a[maxi]<a[i]) maxi=i;
		VI b(m,-1);
		i=maxi;
		for(j=0;j<a[i] && 2*j<m-1;j++) b[2*j]=i;
		a[i]-=j;
		for(j=0;j<m;j++)
		{
			if(b[j]>=0) continue;
			int cur=-1;
			for(i=0;i<n;i++)
			{
				if(i!=b[j-1] && !(m>1 && j==m-1 && i==b[0]) && (cur<0 || a[cur]<a[i]))
					cur=i;
			}
			if(cur<0 || a[cur]==0) break;
			b[j]=cur;
			a[cur]--;
		}
		if(j<m) puts("-1"); else
		{
			for(i=0;i<m;i++)
				printf("%d%c",b[i]+1,i<m-1?' ':'\n');
		}
	}
	return 0;
}