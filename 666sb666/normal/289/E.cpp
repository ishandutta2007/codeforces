#include<cstdio>
const int N=1e6+5;
int n,a[N];
void solve(int n)
{
	if(n<=0)return;
	int m;
	for(int i=0;i<=20;i++)if(n&(1<<i))m=i;
	m=1<<m;
	for(int i=m-(n-m+1);i<=n;i++)a[i]=m+m-i-1;
	solve(m+m-n-2);
}
int main()
{
	scanf("%d",&n);
	printf("%lld\n",(long long)n*(n+1));
	solve(n);
	for(int i=0;i<=n;i++)printf("%d ",a[i]);
	return 0;
}