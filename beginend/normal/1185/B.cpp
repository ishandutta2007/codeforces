#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=1000005;

int n,m,a1[N],b1[N],a2[N],b2[N];
char s[1000005],t[1000005];

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s%s",s,t);
		n=strlen(s);
		m=strlen(t);
		int n1=0,m1=0;
		for (int i=0;i<n;i++)
			if (!n1||a1[n1]!=s[i]-'a') a1[++n1]=s[i]-'a',a2[n1]=1;
			else a2[n1]++;
		for (int i=0;i<m;i++)
			if (!m1||b1[m1]!=t[i]-'a') b1[++m1]=t[i]-'a',b2[m1]=1;
			else b2[m1]++;
		bool flag=0;
		if (n1!=m1) flag=1;
		for (int i=1;i<=n1;i++)
			if (a1[i]!=b1[i]||a2[i]>b2[i]) flag=1;
		if (flag) puts("NO");
		else puts("YES");
	}
	return 0;
}