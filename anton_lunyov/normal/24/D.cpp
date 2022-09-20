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
typedef long double LD;

#define N 1111

int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,x,y,q,i;
	while(scanf("%d%d%d%d",&n,&m,&x,&y)>0)
	{
		if(m==1)
		{
			printf("%.5lf\n",2.*(n-x));
			continue;
		}
		LD M[N]={0};
		for(q=n-1;q>=x;q--)
		{
			LD a[N];
			LD b[N];
			a[2]=1./2;
			b[2]=(M[1]+3)/2;
			for(i=2;i<m;i++)
			{
				a[i+1]=1/(3-a[i]);
				b[i+1]=(M[i]+4+b[i])/(3-a[i]);
			}
			M[m]=(M[m]+3+b[m])/(2-a[m]);
			for(i=m-1;i>0;i--)
				M[i]=a[i+1]*M[i+1]+b[i+1];
		}
		printf("%.5lf\n",M[y]);
	}
	return 0;
}