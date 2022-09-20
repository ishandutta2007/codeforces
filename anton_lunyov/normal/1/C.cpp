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
#define eps 1e-5
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

int main()
{
	//freopen("in.txt","r",stdin);
	double x1,y1,x2,y2,x3,y3;
	while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)>0)
	{
		double ar=(x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
		double a=hypot(x1-x2,y1-y2);
		double b=hypot(x2-x3,y2-y3);
		double c=hypot(x3-x1,y3-y1);
		double r=a*b*c/2/ar;
		double A=acos(((x1-x3)*(x2-x3)+(y1-y3)*(y2-y3))/b/c)/PI;
		double B=acos(((x2-x1)*(x3-x1)+(y2-y1)*(y3-y1))/c/a)/PI;
		double C=acos(((x1-x2)*(x3-x2)+(y1-y2)*(y3-y2))/a/b)/PI;
		int n;
		for(n=3;;n++)
		{
			if(fabs(int(A*n+0.5)-A*n)>eps) continue;
			if(fabs(int(B*n+0.5)-B*n)>eps) continue;
			if(fabs(int(B*n+0.5)-B*n)>eps) continue;
			break;
		}
		printf("%.7lf\n",n*r*r*sin(2*PI/n)/2);
	}
	return 0;
}