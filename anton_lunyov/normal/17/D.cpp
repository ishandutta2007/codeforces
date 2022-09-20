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


LL powmod(LL a_,LL n,LL m)
{
	LL a=a_;
	LL p=1;
	for(;n;)
	{
		if(n%2) p=p*a%m;
		if(n/=2) a=a*a%m;
	}
	return p;
}

#define N 1010101
char sb[N],n[N];
int nL;
int valn;
LL b;

LL f(LL p,LL q)//b^(n-1)%q q=p^i (p \in P)
{
	int i;
	if(b%p==0)
	{
		if(nL>2) return 0;
		LL ans=1;
		for(i=0;i<valn-1;i++)
			ans=ans*b%q;
		return ans;
	}
	LL deg=0;
	LL phi=q/p*(p-1);
	for(i=0;i<nL;i++)
		deg=(10*deg+n[i]-'0')%phi;
	deg=(deg+phi-1)%phi;
	return powmod(b,deg,q);
}

int main()
{
	//freopen("in.txt","r",stdin);
	LL k;
	while(scanf("%s %s %I64d",sb,n,&k)>0)
	{
		b=0;
		int i;
		for(i=0;sb[i];i++)
			b=(10*b+sb[i]-'0')%k;
		nL=strlen(n);
		valn=0;
		for(i=0;i<nL && i<4;i++)
			valn=10*valn+n[i]-'0';
		LL r[11];
		LL p[11];
		LL q[11];
		LL len=0;
		LL K=k;
		LL d;
		for(d=2;d*d<=k;d++)
			if(k%d==0)
			{
				LL cur=1;
				for(i=0;k%d==0;i++) k/=d,cur*=d;
				r[len]=f(d,cur);
				p[len]=d;
				q[len++]=cur;
			}
		if(k>1)
		{
			r[len]=f(k,k);
			p[len]=k;
			q[len++]=k;
		}
		LL ans=0;
		for(i=0;i<len;i++)
			ans=(ans+r[i]*powmod(K/q[i],q[i]/p[i]*(p[i]-1),K))%K;
		ans=(b-1)*ans%K;
		if(ans<=0) ans+=K;
		printf("%d\n",int(ans));
	}
	return 0;
}