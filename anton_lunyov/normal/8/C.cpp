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

#define N 30

int n;
int x[N],y[N];
int d0[N];
int d[N][N];
int f[1<<24];

int main()
{
	//freopen("in.txt","r",stdin);
	int x0,y0;
	while(scanf("%d%d",&x0,&y0)>0)
	{
		scanf("%d",&n);
		int i,j,k,I,J;
		for(i=0;i<n;i++) scanf("%d%d",&x[i],&y[i]);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++) d[i][j]=sqr(x[i]-x[j])+sqr(y[i]-y[j]);
		for(i=0;i<n;i++) d0[i]=sqr(x0-x[i])+sqr(y0-y[i]);
		int bitn=1<<n;
		int mask;
		f[0]=0;
		for(mask=1;mask<bitn;mask++)
		{
			int p[N];
			for(i=k=0;i<n;i++)
				if(mask & bit(i)) p[k++]=i;
			int &res=f[mask];
			res=inf;
			I=p[k-1];
			int cur=f[mask-bit(I)]+2*d0[I];
			MIN(res,cur);
			for(j=0;j<k-1;j++)
			{
				J=p[j];
				int cur=f[mask-bit(I)-bit(J)]+d0[I]+d[I][J]+d0[J];
				MIN(res,cur);
			}
		}
		mask--;
		printf("%d\n",f[mask]);
		int ans[1111]={0};
		int len=1;
		for(;mask;)
		{
			int p[N];
			for(i=k=0;i<n;i++)
				if(mask & bit(i)) p[k++]=i;
			int res=f[mask];
			bool flag=true;
			I=p[k-1];
			int cur=f[mask-bit(I)]+2*d0[I];
			if(res==cur)
			{
				ans[len++]=I+1;
				ans[len++]=0;
				mask-=bit(I);
				flag=false;
			}
			for(j=0;j<k-1 && flag;j++)
			{
				J=p[j];
				int cur=f[mask-bit(I)-bit(J)]+d0[I]+d[I][J]+d0[J];
				if(res==cur)
				{
					ans[len++]=I+1;
					ans[len++]=J+1;
					ans[len++]=0;
					mask-=bit(I)+bit(J);
					flag=false;
				}
			}
		};
		for(i=0;i<len;i++)
			printf("%d%c",ans[i],i<len-1?' ':'\n');
	}
	return 0;
}