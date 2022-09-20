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

#define N 101010
int a[N];
map<int,VI> inds;
PII b[10101010];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j,k;
	while(scanf("%d",&n)>0)
	{
		inds.cl;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			inds[a[i]].pb(i);
		}
		int len=0;
		for(i=1;i<=n;i++)
		{
			VI cur=inds[a[i]];
			int L=cur.sz;
			for(j=0;j<L;j++)
				if(cur[j]>i)
				{
					int K=cur[j]+i-1;
					int p=cur[j]-i;
					for(k=i;k<K-k && a[k]==a[k+p] && a[K-k]==a[K-k+p];k++);
					if(k>=K-k)
					{
						b[len++]=mp(p,i);
						break;
					}

				}
		}
		sort(b,b+len);
		int q=1;
		for(i=0;i<len;i++)
			if(b[i].second>=q)
				q=b[i].second+b[i].first;
		printf("%d\n",n-q+1);
		for(i=q;i<=n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}