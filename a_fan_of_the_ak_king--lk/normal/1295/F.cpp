#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,m,tot,i,j,k,num,t[1005],l[1005],r[1005];
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
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d %d",&l[i],&r[i]);
		s=s*qpow(r[i]-l[i]+1,M-2)%M;
		r[i]+=2;
		++l[i];
		t[++k]=l[i],t[++k]=r[i];
	}
	for(i=1;i<=1000;++i)
		inv[i]=qpow(i,M-2);
	sort(t+1,t+1+k);
	for(i=1;i<=k;++i)
		if(t[i]!=t[num])
			t[++num]=t[i];
	for(j=num;j>=1;--j)
		suf[0][j]=1;
	for(i=1;i<=n;++i)
		for(j=num-1;j>=1;--j)
		{
			for(k=i;k>=1;--k)
			{
				if(l[k]>=t[j+1]||r[k]<=t[j])
					break;
				f[i][j]=(f[i][j]+C(t[j+1]-t[j]+i-k,i-k+1)*suf[k-1][j+1])%M;
			}
			suf[i][j]=(suf[i][j+1]+f[i][j])%M;
		}
	for(j=1;j<num;++j)
		ans=(ans+f[n][j])%M;
	cout<<(ans*s%M+M)%M;
}