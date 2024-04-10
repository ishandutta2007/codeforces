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

#define N 101010

PII a[N];
int mark[N];

int main()
{
#ifdef MY_DEBUG
	freopen("b.in","r",stdin);
#endif
	int n;
	LL k;
	while(scanf("%d%I64d",&n,&k)>0)
	{
		LL tot=0;
		int i,j;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i].X);
			tot+=a[i].X;
			a[i].Y=i;
		}
		if(tot<k){puts("-1");continue;}
		sort(a,a+n);
		fill(mark,1);
		int prev=0;
		int num=n;
		int cnt=0;
		for(i=0;i<n;i=j)
		{
			int cur=a[i].X;
			cnt++;
			for(j=i;j<n && a[j].X==cur;j++)
				mark[a[j].Y]=cnt;
			LL d=cur-prev;
			if(k>d*num)
			{
				k-=d*num;
				num-=j-i;
			}
			else
			{
				LL q=(k-1)/num;
				LL r=(k-1)%num;
				VI c;
				for(i=0;i<n;i++)
					if(mark[i]>=cnt) c.pb(i);
				for(i=1;i<=num;i++)
				{
					j=c[(r+i)%num];
					if(mark[j]>cnt || q*num+r+i<d*num && mark[j]==cnt)
						printf("%d ",j+1);
				}
				printf("\n");
				break;
			}
			prev=cur;
		}
	}
	return 0;
}