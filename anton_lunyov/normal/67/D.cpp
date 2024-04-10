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

#define N 1010101

int x[N];
int a[N];
int m[N];

int main()
{
#ifdef mydebug
	freopen("d.in","r",stdin);
#endif
	int n,i,j;
	while(scanf("%d",&n)>0)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&j);j--;
			x[j]=i;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&j);j--;
			a[x[j]]=i;
		}
		int len=0;
		m[0]=inf;
		for(i=0;i<n;i++)
		{
			int x=a[i];
			if(m[len]>x) m[++len]=x; else
			{
				int l=0;
				int r=len;
				while(l+1<r)
				{
					int mid=(l+r)/2;
					if(m[mid]>x) l=mid; else r=mid;
				}
				m[r]=x;
			}
		}
		printf("%d\n",len);
	}
	return 0;
}