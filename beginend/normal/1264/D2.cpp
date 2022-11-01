#include<bits/stdc++.h>

typedef long long LL;

const int N=1000005;
const int MOD=998244353;

int n,pre[N],s1[N],s2[N],jc[N],ny[N];
char str[N];

int C(int n,int m)
{
	if (n<m||m<0) return 0;
	return (LL)jc[n]*ny[m]%MOD*ny[n-m]%MOD;
}

int main()
{
	scanf("%s",str+1);
	n=strlen(str+1);
	for (int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1];
		s1[i]=s1[i-1];s2[i]=s2[i-1];
		if (str[i]=='?') pre[i]++;
		else if (str[i]=='(') s1[i]++;
		else s2[i]++;
	}
	jc[0]=jc[1]=ny[0]=ny[1]=1;
	for (int i=2;i<=n;i++) jc[i]=(LL)jc[i-1]*i%MOD,ny[i]=(LL)(MOD-MOD/i)*ny[MOD%i]%MOD;
	for (int i=2;i<=n;i++) ny[i]=(LL)ny[i-1]*ny[i]%MOD;
	int ans=0;
	for (int i=1;i<n;i++)
	{
		int lef1=s1[i],rig1=s2[n]-s2[i];
		int lef2=pre[i],rig2=pre[n]-pre[i];
		(ans+=(LL)lef1*C(lef2+rig2,rig1-lef1+rig2)%MOD)%=MOD;
		(ans+=(LL)lef2*C(lef2+rig2-1,rig1-lef1+rig2-1)%MOD)%=MOD;
	}
	printf("%d\n",ans);
	return 0;
}