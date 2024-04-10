#include<bits/stdc++.h>

const int N=300005;

int n,a[N],b[N];
char str[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%s",str+1);
		n=strlen(str+1);
		int t1=0,t2=0;
		for (int i=1;i<=n;i++)
			if ((str[i]-'0')&1) a[++t1]=str[i]-'0';
			else b[++t2]=str[i]-'0';
		std::reverse(a+1,a+t1+1);
		std::reverse(b+1,b+t2+1);
		for (int i=1;i<=n;i++)
			if (!t1||t1&&t2&&b[t2]<a[t1]) printf("%d",b[t2--]);
			else printf("%d",a[t1--]);
		puts("");
	}
	return 0;
}