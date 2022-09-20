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

#define N 5555

LL f[2][N],mf[2][N];
int a[N],b[N];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,m;
	while(scanf("%d",&n)>0)
	{
		int i,j;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		sort(b+1,b+1+n);
		for(j=0,i=1;i<=n;i++)
			if(i==1 || b[i-1]<b[i]) b[++j]=b[i];
		m=j;
		fill(f,0);
		fill(mf,0);
		int p=0;
		for(i=1;i<=n;i++)
		{
			mf[p][0]=LL(inf)*inf;
			for(j=1;j<=m;j++)
			{
				f[p][j]=abs(a[i]-b[j])+mf[!p][j];
				mf[p][j] = j==1?f[p][j]:min(mf[p][j-1],f[p][j]);
			}
			p=!p;
		}
		printf("%I64d\n",mf[!p][m]);
	}
	return 0;
}