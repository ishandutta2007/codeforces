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

#define N 101010
int n;
int x[N],y[N];

bool is_geo()
{
	bool zero=false;
	int num=0;
	int i;
	for(i=0;i<n;i++)
	{
		if(x[i]==0)
			zero=true;
		else
			if(i) num++;
	}
	if(zero)
		return num==0;
	for(i=1;i<n-1;i++)
		if(x[i]*x[i]!=x[i-1]*x[i+1]) return false;
	return true;
}

int geo()
{
	if(is_geo()) return 0;
	int i,j,k,h;
	int num=0;
	for(i=0;i<n;i++)
		if(x[i]) num++;
	if(num==1) return 1;
	if(num==2 && x[0]) return 1;
	if(num<n-1) return 2;
	if(num==n-1)
	{
		for(i=0;i<n && x[i];i++);
		for(j=i;j<n-1;j++)
			x[j]=x[j+1];
		n--;
		if(is_geo()) return 1;
		return 2;
	}
	for(i=1;i<n-1;i++)
		if(x[i]*x[i]!=x[i-1]*x[i+1]) break;
	for(k=0;k<n;k++)
		y[k]=x[k];
	for(j=i-1;j<=i+1;j++)
	{
		for(k=h=0;k<n;k++)
			if(k!=j) x[h++]=y[k];
		n--;
		if(is_geo()) return 1;
		n++;
	}
	return 2;
}

int main()
{
	//freopen("D.in","r",stdin);
	while(scanf("%d",&n)>0)
	{
		int i;
		for(i=0;i<n;i++)
			scanf("%d",x+i);
		int res=geo();
		printf("%d\n",res);
	}
	return 0;
}