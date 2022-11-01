#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn=100000+5;

int n,m,A[maxn];
int G[maxn],C[maxn];

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	int ncmd;
	scanf("%d%d",&n,&ncmd);
	m=(int)sqrt((double)n)+1;
	for (;m&(m-1);m=(m|(m-1))+1);
	m=(int)(log((double)m)/log(2.0)+0.5);
	for (int i=0;i<n;i++)
	{
		int d;
		scanf("%d",&d);
		A[i]=i+d;
	}
	for (int i=n-1;i>=0;i--)
		if (A[i]<n && (A[i]>>m)==(i>>m))
			C[i]=C[A[i]]+1,G[i]=G[A[i]];
		else
			C[i]=0,G[i]=i;
	for (;ncmd>0;ncmd--)
	{
		int cmd,a,b;
		scanf("%d",&cmd);
		if (cmd==0)
		{
			scanf("%d%d",&a,&b);
			a--;
			A[a]=a+b;
			int s=(a>>m)<<m;
			for (int i=a;i>=s;i--)
				if (A[i]<n && (A[i]>>m)==(i>>m))
					C[i]=C[A[i]]+1,G[i]=G[A[i]];
				else
					C[i]=0,G[i]=i;
		}
		else
		{
			scanf("%d",&a);
			a--;
			b=1;
			while (A[a]<n)
			{
				if (G[a]!=a) b+=C[a],a=G[a];
				if (A[a]<n) b++,a=A[a];
			}
			printf("%d %d\n",a+1,b);
		}
	}
	return 0;
}