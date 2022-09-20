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

bool is_prime(int p)
{
	for(int d=2;d*d<=p;d++)
		if(p%d==0) return false;
	return true;
}

#define BOUND inf

#define N 51010
int a[N];
int primes[N];
int plen;

char b[20202020];

namespace coprimes
{
	int ans;
	int L;
	int p[N];
	int n;

	void rec(int i,int pr,int sign)
	{
		int m=n/pr;
		ans+=sign*m;
		for(int j=i;j<L && p[j]<=m;j++)
			rec(j+1,pr*p[j],-sign);
	}

	int count(int n_,int num)
	{
		L=num;
		for(int i=0;i<L;i++)
			p[i]=primes[i];
		n=n_;
		ans=0;
		rec(0,1,1);
		return ans;
	}
}

int main()
{
#ifdef MY_DEBUG
	freopen("d.in","r",stdin);
#endif
	int i,j;
	for(i=2;i<N;i++) if(!a[i])
	{
		primes[plen++]=i;
		for(j=i+i;j<N;j+=i) a[j]=1;
	}
	int L,R,p;
	while(scanf("%d%d%d",&L,&R,&p)>0)
	{
		if(!is_prime(p)){puts("0");continue;}
		if(LL(p)*p>R){printf("%d\n",L<=p && p<=R);continue;}
		L=(L+p-1)/p;
		R=R/p;
		if(p>BOUND)
		{
			fill(b,0);
			for(i=0;i<plen;i++)
			{
				int q=primes[i];
				if(q>=p) break;
				for(int x=q;x<=R;x+=q)
					b[x]=1;
			}
			int ans=0;
			for(i=L;i<=R;i++)
				ans+=!b[i];
			printf("%d\n",ans);
			continue;
		}
		for(i=0;i<plen && primes[i]<p;i++);
		int ansR=coprimes::count(R,i);
		int ansL=coprimes::count(L-1,i);
		int ans=ansR-ansL;
		printf("%d\n",ans);
	}
	return 0;
}