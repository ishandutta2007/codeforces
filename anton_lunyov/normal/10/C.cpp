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

#define N 1010101
char a[N];
int d[N];

int main()
{
	//freopen("in.txt","r",stdin);
	int i,j,k;
	for(i=1;i<N;i++) d[i]=1;
	for(i=2;i<N;i++) if(!a[i])
		for(j=i;j<N;j+=i)
		{
			a[j]=1;
			int q=1;
			for(k=j;k%i==0;k/=i) q++;
			d[j]*=q;
		}
	LL n;
	while(scanf("%I64d",&n)>0)
	{
		LL ans=0;
		LL x,y,z;
		for(x=1;x<=9;x++)
			for(y=1;y<=9;y++)
			{
				z=x*y%9;
				if(z==0) z=9;
				ans+=((n+9-x)/9) * ((n+9-y)/9) * ((n+9-z)/9);
			}
		for(i=1;i<=n;i++) ans-=d[i];
		/*int num=0;
		for(x=1;x<=n;x++)
			for(y=1;y<=n;y++)
				for(z=1;z<=n;z++)
					if(z!=x*y && z%9==x*y%9) num++;
		printf("cor=%d ans=",num);*/
		printf("%I64d\n",ans);
	}
	return 0;
}