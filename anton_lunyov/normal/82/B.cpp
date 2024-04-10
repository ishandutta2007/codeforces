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

#define N 222

pair<string,int> mark[N];

int main()
{
#ifdef MY_DEBUG
	freopen("b.in","r",stdin);
#endif
	int n;
	while(scanf("%d",&n)>0)
	{
		int i,j,k;
		if(n==2)
		{
			scanf("%d%d",&k,&i);
			printf("1 %d\n",i);
			printf("%d",k-1);
			while(--k)
			{
				scanf("%d",&i);
				printf(" %d",i);
			}
			printf("\n");
			continue;
		}
		int m=n*(n-1)/2;
		for(i=0;i<N;i++)
		{
			mark[i].X=string(m,'0');
			mark[i].Y=i;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d",&k);
			while(k--)
			{
				scanf("%d",&j);
				mark[j].X[i]='1';
			}
		}
		sort(mark,mark+N);
		vector<VI> res;
		for(i=0;i<N;i=j)
		{
			VI tmp;
			for(j=i;j<N && mark[i].X==mark[j].X;j++)
				tmp.pb(mark[j].Y);
			for(k=0;k<m && mark[i].X[k]=='0';k++);
			if(k<m)
				res.pb(tmp);
		}
		for(i=res.sz;i--;)
		{
			printf("%d",res[i].sz);
			for(j=res[i].sz;j--;)
				printf(" %d",res[i][j]);
			printf("\n");
		}
	}
	return 0;
}