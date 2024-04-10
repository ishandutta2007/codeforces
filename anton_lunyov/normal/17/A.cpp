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

#define N 1111
int a[N]={1,1};
int p[N];
int plen=0;
int b[2*N]={0};

int main()
{
	//freopen("in.txt","r",stdin);
	int i,j,n,k;
	for(i=2;i<N;i++) if(!a[i])
	{
		p[plen++]=i;
		for(j=i+i;j<N;j+=i) a[j]=1;
	}
	for(i=0;i<plen-1;i++)
		b[p[i]+p[i+1]+1]=1;
	while(scanf("%d%d",&n,&k)>0)
	{
		int num=0;
		for(i=2;i<=n;i++)
			if(b[i] && !a[i]) num++;
		puts(num>=k?"YES":"NO");
	}
	return 0;
}