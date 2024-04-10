#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=1000005;
const int MOD=1000000007;

int n,a[N],jc[N],ny[N];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int C(int n,int m)
{
	return (LL)jc[n]*ny[m]%MOD*ny[n-m]%MOD;
}

int main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	jc[0]=jc[1]=ny[0]=ny[1]=1;
	for (int i=2;i<=n;i++) jc[i]=(LL)jc[i-1]*i%MOD,ny[i]=(LL)(MOD-MOD/i)*ny[MOD%i]%MOD;
	for (int i=2;i<=n;i++) ny[i]=(LL)ny[i]*ny[i-1]%MOD;
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		int j=i,s=i-1;
		while (j<n&&a[j+1]==a[j]) j++;
		(ans+=(LL)jc[s]*jc[n-s-1]%MOD*C(n,s)%MOD*a[i]%MOD*(j-i+1)%MOD)%=MOD;
		i=j;
	}
	(ans+=MOD-(LL)a[n]*jc[n]%MOD)%=MOD;
	printf("%d",ans);
	return 0;
}