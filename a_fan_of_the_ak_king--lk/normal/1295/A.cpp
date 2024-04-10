#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,m,tot,i,j,k,num,t,l[1005],r[1005];
long long f[55][1005],suf[55][1005],ans,inv[1005],s=1;
long long qpow(long long a,long long b)
{
	long long s=a,ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*s%M;
		s=s*s%M;
		b>>=1;
	}
	return ans;
}
long long C(int n,int m)
{
	if(n>=M)
		n%=M;
	if(n<m||n<0||m<0)
		return 0;
	int i;
	long long ans=1;
	for(i=n;i>n-m;--i)
		ans=ans*i%M;
	for(i=1;i<=m;++i)
		ans=ans*inv[i]%M;
	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n&1)
		{
			putchar('7');
			n-=3;
		}
		while(n)
		{
			putchar('1');
			n-=2;
		}
		putchar('\n');
	}
}