#include<bits/stdc++.h>
using std::min;
using std::max;
typedef long long ll;

int n,k,a[1<<20],b[1<<20];
int c[1<<20],d[1<<20];
void exec()
{
	scanf("%d%d",&n,&k);
	for(int i=n-k+1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	if(k==1)
	{
		puts("Yes");
		return;
	}
	for(int i=n-k+1;i<n;i++)
	{
		d[i]=a[i+1]-a[i];
	}
	for(int i=n-k+1;i<(n-1);i++)
		if(d[i]>d[i+1])
		{
			puts("No");
			return;
		}
	
	if(d[n-k+1]*1ll*(n-k+1) < a[n-k+1])
		{
			puts("No");
			return;
		}
	puts("Yes");
}

int main()
{
	int T=1;
	scanf("%d",&T);
	while(T--)exec();
}