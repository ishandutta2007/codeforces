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

LL f(LL n)
{
	LL ans=n/2%2;
	for(LL p=2;p<=n;p*=2)
	{
		LL r=n%(2*p);
		if(r>=p && r%2) ans+=p;
	}
	return ans;
}

LL ff(LL n)
{
	LL ans=0;
	for(LL x=0;x<n;x++) ans^=x;
	return ans;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	//for(n=0;n<10000;n++) if(f(n)!=ff(n)) puts("ERROR");
	scanf("%d",&n);
	{
		LL s=0;
		for(int i=0;i<n;i++)
		{
			LL m,x;
			scanf("%I64d %I64d",&x,&m);
			s^=f(x);
			s^=f(x+m);
		}
		puts(s?"tolik":"bolik");
	}
	return 0;
}