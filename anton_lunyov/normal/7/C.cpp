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

LL gcd(LL a,LL b,LL &x,LL &y)
{
	LL c;
	LL x0=1,y0=0;
	LL x1=0,y1=1;
	while(b)
	{
		LL q=a/b;
		c=a-q*b,a=b,b=c;
		x=x0-q*x1,x0=x1,x1=x;
		y=y0-q*y1,y0=y1,y1=y;
	}
	x=x0;
	y=y0;
	return a;
}

void print(LL x,LL y)
{
	printf("%I64d %I64d\n",x,y);
}

int main()
{
	//freopen("in.txt","r",stdin);
	LL a,b,c;
	while(scanf("%I64d %I64d %I64d\n",&a,&b,&c)>0)
	{
		if(a==0)
		{
			if(c%b==0) print(0,-c/b); else puts("-1");
			continue;
		}
		if(b==0)
		{
			if(c%a==0) print(-c/a,0); else puts("-1");
			continue;
		}
		int sx=1,sy=1;
		if(a<0) sx=-1,a=-a;
		if(b<0) sy=-1,b=-b;
		LL x,y;
		LL d=gcd(a,b,x,y);
		if(c%d==0) print(-sx*x*(c/d),-sy*y*(c/d)); else puts("-1");
	}
	return 0;
}