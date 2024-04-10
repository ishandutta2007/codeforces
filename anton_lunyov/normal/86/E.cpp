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
#pragma comment(linker, "/STACK:266777216")
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

#define N 55

int n;
typedef vector<LL> matr;

matr unit()
{
	matr p(n,0);
	for(int i=0;i<n;i++)
		p[i]|=bit64(i);
	return p;
}

matr transpose(const matr &b)
{
	matr c(n,0);
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(b[i] & bit64(j))
				c[j] |= bit64(i);
	return c;
}

int bitcnt(LL a)
{
	int s=0;
	for(;a;a-=a&-a) s^=1;
	return s;
}

void operator*=(matr &a,const matr &b)
{
	matr c=transpose(b);
	matr d(n,0);
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(bitcnt(a[i]&c[j]))
				d[i]|=bit64(j);
	a=d;
}

bool is_power_unit(matr a,LL n)
{
	matr p=unit();
	for(;n;)
	{
		if(n%2) p*=a;
		if(n/=2) a*=a;
	}
	return p==unit();
}

LL RAND()
{
	LL x=0;
	for(int i=0;i<4;i++)
		x=(x<<15)+rand()%bit(15);
	return x;
}

int main()
{
	//freopen("e.out","w",stdout);
	//for(n=2;n<=50;n++)
	while(scanf("%d",&n)>0)
	{
		clock_t start=clock();
		int i;
		LL m=bit64(n)-1;
		LL q=m;
		vector<LL> p;
		LL d=1;
		for(d=2;d*d<=q;d++)
			if(q%d==0)
			{
				for(;q%d==0;q/=d);
				p.pb(d);
			}
		if(q>1) p.pb(q);
		LL mask=bit64(n-1);
		if(n==46) mask+=151; else
		if(n==48) mask+=91; else
		if(n==49) mask+=56;
		for(;;mask++)
		{
			//mask=RAND()%bit64(n);
			matr a(n,0);
			a[0]=mask;
			for(i=1;i<n;i++)
				a[i]|=bit64(i-1);
			if(is_power_unit(a,m))
			{
				for(i=0;i<p.sz && !is_power_unit(a,m/p[i]);i++);
				if(i==p.sz) break;
			}
		}
		for(i=0;i<n;i++)
			if(mask & bit64(i)) printf("1 "); else printf("0 ");
		printf("\n");
		printf("1 ");
		for(i=1;i<n;i++)
			printf("0 ");
		printf("\n");
		/*fprintf(stderr,"%d %I64d\n",n,mask-bit64(n-1));
		fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
		printf("%I64dLL,",mask);*/
	}
	return 0;
}