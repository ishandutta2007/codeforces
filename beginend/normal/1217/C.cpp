#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=200005;

int n,a[N],ls[N];
char str[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%s",str+1);
		n=strlen(str+1);
		for (int i=1;i<=n;i++) a[i]=str[i]-'0';
		for (int i=1;i<=n;i++)
			if (a[i]) ls[i]=i;
			else ls[i]=ls[i-1];
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			int s=0;
			for (int j=ls[i];j&&i-j<=20;j=ls[j-1])
			{
				s+=1<<(i-j);
				if (s>=i-j+1&&s<i-ls[j-1]+1) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}