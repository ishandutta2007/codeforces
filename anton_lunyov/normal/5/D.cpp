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

int main()
{
	//freopen("in.txt","r",stdin);
	int a,v,l,d,w;
	while(scanf("%d%d%d%d%d",&a,&v,&l,&d,&w)>0)
	{
		double t=0;
		if(w>=v || w*w>=2*d*a)
		{
			if(v*v>=2*a*l) t=sqrt(2.*l/a); else
				t=1.*v/a+(l-v*v/2./a)/v;
		}
		else
		{
			double t0=(1.*v-w)/a;
			double t1=(-w+sqrt(w*w+2.*a*(l-d)))/a;
			if(t0<=t1) t=t0+(l-d-w*t0-a*t0*t0/2)/v; else
				t=t1;
			double v0=sqrt(w*w/2.+d*a);
			if(v0<=v) t+=(2*v0-w)/a; else
			{
				t0=1.*v/a;
				double s0=a*t0*t0/2;
				t1=1.*(v-w)/a;
				double s1=v*t1-a*t1*t1/2;
				t+=t0+t1+(d-s0-s1)/v;

			}
		}
		printf("%.9lf\n",t);
	}
	return 0;
}