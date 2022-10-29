#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=100005;
int n,K,a[N],ci[N],i,j,k,L,R;
long long g,f[N][22],w[N];
long long W(int l,int r)
{
	while(R<r)
	{
		++R;
		g+=ci[a[R]];
		ci[a[R]]++;
	}
	while(L>l)
	{
		--L;
		g+=ci[a[L]];
		ci[a[L]]++;
	}
	while(R>r)
	{
		--ci[a[R]];
		g-=ci[a[R]];
		--R;
	}
	while(L<l)
	{
		--ci[a[L]];
		g-=ci[a[L]];
		++L;
	}
	return g;
}
void work(int l1,int r1,int l2,int r2)
{
	if(l1>r1)
		return;
	if(l2==r2)
	{
		for(int i=l1;i<=r1;++i)
			f[i][k]=f[l2][k-1]+W(l2+1,i);
		return;
	}
	int mid=l1+r1>>1,i,j;
	long long mn=1ll<<60;
	for(i=l2;i<=r2&&i<mid;++i)
		if(f[i][k-1]+W(i+1,mid)<mn)
		{
			mn=f[i][k-1]+W(i+1,mid);
			j=i;
		}
	f[mid][k]=mn;
	work(l1,mid-1,l2,j);
	work(mid+1,r1,j,r2);
}
int main()
{
	scanf("%d%d",&n,&K);
	for(i=1;i<=n;++i)
		scanf("%d",a+i);
	for(j=2;j<=n;++j)
	{
		ci[a[j-1]]++;
		w[j]=w[j-1]+ci[a[j]];
	}
	for(i=1;i<=n;++i)
		ci[i]=0;
	L=R=1;
	ci[a[1]]++;
	g=0;
	for(i=1;i<=n;++i)
		f[i][1]=w[i];
	for(k=2;k<=K;++k)
	{
		f[k][k]=0;
		if(k+1<=n)
			work(k+1,n,0,n);
	}
	printf("%lld",f[n][K]);
	return 0;
}