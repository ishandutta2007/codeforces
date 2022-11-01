#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
 
typedef long long LL;
 
int n,tot,b[505],t1,t2,s1[1000005],s2[1000005];

void get(int x)
{
	t2=0;
	for (int j=1,last;j<=x;j=last+1)
	{
		last=x/(x/j);
		if (s2[t2]!=last-1&&j<last&&x%(x/j)==0) s2[++t2]=last-1;
		s2[++t2]=last;
	}
}
 
int main()
{
	scanf("%d",&n);
	int t1=0;
	scanf("%d",&b[1]);
	get(b[1]);
	t1=t2;
	for (int i=1;i<=t1;i++) s1[i]=s2[i];
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&b[i]);
		get(b[i]);
		int p=1;
		for (int j=1;j<=t1;j++)
		{
			if (!s1[j]) continue;
			while (p<=t2&&s2[p]<s1[j]) p++;
			if (p>t2||s2[p]!=s1[j]) s1[j]=0;
		}
	}
	int ans;
	for (int i=t1;i>=1;i--) if (s1[i]) {ans=s1[i];break;}
	LL cnt=0;
	for (int i=1;i<=n;i++) cnt+=b[i]/(ans+1)+(b[i]%(ans+1)>0);
	printf("%lld\n",cnt);
	return 0;
}