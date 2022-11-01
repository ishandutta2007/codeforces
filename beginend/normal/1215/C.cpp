#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=200005;

int n,a[N],b[N];
char s[N],t[N];

int main()
{
	scanf("%d%s%s",&n,s+1,t+1);
	int s1=0,s2=0;
	for (int i=1;i<=n;i++)
		if (s[i]!=t[i])
		{
			if (s[i]=='a') a[++s1]=i;
			else b[++s2]=i;
		}
	if ((s1+s2)%2==1) puts("-1");
	else
	{
		printf("%d\n",(s1+s2)/2+(s1&1));
		for (int i=1;i<s1;i+=2) printf("%d %d\n",a[i],a[i+1]);
		for (int i=1;i<s2;i+=2) printf("%d %d\n",b[i],b[i+1]);
		if ((s1&1)&&(s2&1)) printf("%d %d\n%d %d\n",a[s1],a[s1],a[s1],b[s2]);
	}
	return 0;
}