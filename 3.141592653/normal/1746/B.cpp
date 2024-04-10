#include<bits/stdc++.h>
typedef long long ll;
typedef double db;
using std::sort;
using std::min;
using std::max;
using std::swap;
typedef std::pair<int,int> pii;

void rddi(int*x,int _C)
{
	for(int i=1;i<=_C;i++)
	{
		scanf("%d",x+i);
	}
}
void rddl(ll*x,int _C)
{
	for(int i=1;i<=_C;i++)
	{
		scanf("%lld",x+i);
	}
}
void rddd(db*x,int _C)
{
	for(int i=1;i<=_C;i++)
	{
		scanf("%lf",x+i);
	}
}
int n,k;
int a[1<<20],b[1<<20],c[1<<20];
void clear()
{}

void exec()
{
	scanf("%d",&n);
	rddi(a,n);
	int s=0; 
	for(int i=1;i<=n;i++)
		s+=a[i];
	int t=0;
	for(int i=n-s+1;i<=n;i++)
		t+=!(a[i]);
	printf("%d\n",t);
} 
int main()
{
	int T=1;
	scanf("%d",&T);
	while(T--)exec();
}