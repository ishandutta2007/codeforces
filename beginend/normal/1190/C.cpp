#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=100005;

int n,k,a[N],s0[N],s1[N],fro0[N],fro1[N],bac0[N],bac1[N];
char str[N];

int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",str+1);
	for (int i=1;i<=n;i++) a[i]=str[i]-'0';
	for (int i=1;i<=n;i++)
	{
		s0[i]=s0[i-1];s1[i]=s1[i-1];
		if (!a[i]) s0[i]++;
		else s1[i]++;
	}
	for (int i=k;i<=n;i++)
		if (s0[i]-s0[i-k]==s0[n]||s1[i]-s1[i-k]==s1[n]) {puts("tokitsukaze");return 0;}
	int a1=0,a0=0;
	for (int i=1;i<=n;i++)
	{
		if (!a[i]) a0=i;
		else a1=i;
		fro0[i]=a0;fro1[i]=a1;
	}
	a1=a0=0;
	for (int i=n;i>=1;i--)
	{
		if (!a[i]) a0=i;
		else a1=i;
		bac0[i]=a0;bac1[i]=a1;
	}
	for (int i=k;i<=n;i++)
	{
		int x1=bac0[1],y1=fro0[i-k],x2=bac0[i+1],y2=fro0[n];
		if (x1>y1||!x1||!y1) x1=y1=0;
		if (x2>y2||!x2||!y2) x2=y2=0;
		int L=0;
		if (x1&&x2) L=y2-x1+1;
		else if (x1) L=y1-x1+1;
		else if (x2) L=y2-x2+1;
		if (L>k) {puts("once again");return 0;}
		x1=bac1[1],y1=fro1[i-k],x2=bac1[i+1],y2=fro1[n];
		if (x1>y1||!x1||!y1) x1=y1=0;
		if (x2>y2||!x2||!y2) x2=y2=0;
		L=0;
		if (x1&&x2) L=y2-x1+1;
		else if (x1) L=y1-x1+1;
		else if (x2) L=y2-x2+1;
		if (L>k) {puts("once again");return 0;}
	}
	puts("quailty");
	return 0;
}