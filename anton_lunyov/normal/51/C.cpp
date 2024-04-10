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
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))
#define X first
#define Y second

//clock_t start=clock();
//fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));

#define N 202020
LL x[N];

void print(LL x,char c)
{
	printf("%I64d.%06d%c",x/2,int(x%2*500000),c);
}

int main()
{
	//freopen("C.in","r",stdin);
	int n;
	while(scanf("%d",&n)>0)
	{
		int i,j;
		for(i=0;i<n;i++)
			scanf("%I64d",x+i);
		sort(x,x+n);
		LL L=-1;
		LL R=inf+1,M;
		while(L+1<R)
		{
			M=(L+R)/2;
			for(i=0;i<n && x[i]<=M+x[0];i++);
			for(j=n-1;j>=0 && x[j]>=x[n-1]-M;j--);
			if(i>=j || x[j]-x[i]<=M) R=M; else L=M;
		}
		M=R;
		print(M,'\n');
		for(i=0;i<n && x[i]<=M+x[0];i++);
		for(j=n-1;j>=0 && x[j]>=x[n-1]-M;j--);
		print(2*x[0]+M,' ');
		print(2*x[n-1]-M,' ');
		if(i<=j) print(x[i]+x[j],'\n'); else
			print(1,'\n');
	}
	return 0;
}