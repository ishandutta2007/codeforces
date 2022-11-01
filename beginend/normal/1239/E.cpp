#include<bits/stdc++.h>

const int N=26;

int n,tot,pos[N],a[N*2];
bool vis[N*2];
std::bitset<N*50000> f[N];

void dp(int m)
{
	for (int i=1;i<=std::min(m,n);i++) f[i].reset();
	f[0][0]=1;
	for (int i=1;i<=m;i++)
		for (int j=std::min(n,i);j>=1;j--)
			f[j]|=f[j-1]<<a[i];
}

void pri(int i,int j,int k)
{
	if (!j) return;
	dp(i-1);
	if (k>=a[i]&&f[j-1][k-a[i]]) pos[++tot]=i,pri(i-1,j-1,k-a[i]);
	else pri(i-1,j,k);
}

int main()
{
	scanf("%d",&n);
	int sum=0;
	for (int i=1;i<=n*2;i++) scanf("%d",&a[i]),sum+=a[i];
	std::sort(a+1,a+n*2+1);
	int p1=a[1],p2=a[2];
	sum-=p1+p2;
	n--;
	for (int i=1;i<=n*2;i++) a[i]=a[i+2];
	dp(n*2);
	for (int i=(sum+1)/2;i<=sum;i++)
		if (f[n][i])
		{
			pri(n*2,n,i);
			break;
		}
	printf("%d ",p1);
	for (int i=1;i<=n;i++) vis[pos[i]]=1,printf("%d ",a[pos[n-i+1 ]]);
	puts("");
	for (int i=n*2;i>=1;i--)
		if (!vis[i]) printf("%d ",a[i]);	
	printf("%d\n",p2);
	return 0;
}