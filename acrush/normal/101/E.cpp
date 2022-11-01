#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
 
using namespace std;
 
typedef unsigned int uint;
#define two(X) (((uint)1)<<(X))

const int maxsize=20000+5;
const int maxh=11000+5;

int n,m,p;
int x[maxsize],y[maxsize];
int f[maxsize],g[maxsize];
uint h[maxh][maxsize/32+1];

inline int add(int a,int b)
{
	int c=a+b;
	if (c>=p) c-=p;
	return c;
}

void solve(int n,int m,bool first_time)
{
	memset(f,0,sizeof(f));
	f[1]=0;
	for (int i=2;i<=m;i++) f[i]=f[i-1]+add(x[::n-1],y[::m-i+1]);
	memset(h,0,sizeof(h));
	for (int k=2;k<=n;k++)
	{
		uint *hmask=(n-k<maxh)?h[n-k]:NULL;
		for (int i=1;i<=m;i++)
		{
			int v1=(i==1)?-1:(g[i-1]+add(x[::n-k],y[::m-i+1]));
			int v2=f[i]+add(x[::n-k+1],y[::m-i]);
			if (v1>v2)
			{
				g[i]=v1;
				if (hmask) hmask[i>>5]|=two(i&31);
			}
			else
				g[i]=v2;
		}
		memcpy(f,g,sizeof(f));
	}
	if (first_time) printf("%d\n",f[m]+add(x[0],y[0]));
	for (int i=n,j=m;i>1 || j>1;)
		if (i==1)
		{
			printf("S");
			j--;
		}
		else if (j==1)
		{
			printf("C");
			i--;
		}
		else if (n-i>=maxh)
		{
			solve(i,j,false);
			return;
		}
		else if (h[n-i][j>>5]&two(j&31))
		{
			printf("S");
			j--;
		}
		else
		{
			printf("C");
			i--;
		}
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&p);
	for (int i=0;i<n;i++) scanf("%d",&x[i]);
	for (int i=0;i<m;i++) scanf("%d",&y[i]);
	for (int i=0;i<n;i++) x[i]%=p;
	for (int i=0;i<m;i++) y[i]%=p;
	solve(n,m,true);
	printf("\n");
	return 0;
}