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

#define N 111111
char s[2*N];
char w[N],a[N],b[N];
int z[2*N];
int n,k,l,r;

void update(int beg)
{
	int i;
	for(i=beg;i+k<n && s[i]==s[i+k];i++);
	if(i>0)	z[k]=i,l=k,r=k+i-1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	while(gets(w))
	{
		int nw=strlen(w);
		gets(a);
		int na=strlen(a);
		gets(b);
		int nb=strlen(b);

		bool forw=false;

		strcpy(s,b);
		strcat(s,w);
		n=nb+nw;
		int R=0;
		for(l=r=0,k=1;k<n;k++)
		{
			z[k]=0;
			if(r-k<0) update(0); else
			if(z[k-l]<r-k) z[k]=z[k-l]; else update(r-k);
			if(k>=nb && z[k]>=nb) R=k-nb;
		}

		strcpy(s,a);
		strcat(s,w);
		n=na+nw;
		for(l=r=0,k=1;k<n;k++)
		{
			z[k]=0;
			if(r-k<0) update(0); else
			if(z[k-l]<r-k) z[k]=z[k-l]; else update(r-k);
			if(k>=na && z[k]>=na && k<=R) forw=true;
		}

		bool backw=false;
		reverse(w,w+nw);

		strcpy(s,b);
		strcat(s,w);
		n=nb+nw;
		R=0;
		for(l=r=0,k=1;k<n;k++)
		{
			z[k]=0;
			if(r-k<0) update(0); else
			if(z[k-l]<r-k) z[k]=z[k-l]; else update(r-k);
			if(k>=nb && z[k]>=nb) R=k-nb;
		}

		strcpy(s,a);
		strcat(s,w);
		n=na+nw;
		for(l=r=0,k=1;k<n;k++)
		{
			z[k]=0;
			if(r-k<0) update(0); else
			if(z[k-l]<r-k) z[k]=z[k-l]; else update(r-k);
			if(k>=na && z[k]>=na && k<=R) backw=true;
		}
		if(forw && backw) puts("both"); else
		if(forw) puts("forward"); else
		if(backw) puts("backward"); else puts("fantasy");
	}
	return 0;
}