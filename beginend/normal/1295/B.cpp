#include<bits/stdc++.h>

const int N=100005;

int n,x,s[N];
char str[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&x);
		scanf("%s",str+1);
		for (int i=1;i<=n;i++)
		{
			s[i]=s[i-1];
			if (str[i]=='0') s[i]++;
			else s[i]--;
		}
		if (!s[n])
		{
			int ans=0;
			for (int i=0;i<=n;i++)
				if (s[i]==x) ans=-1;
			printf("%d\n",ans);
			continue;
		}
		int ans=0;
		for (int i=0;i<n;i++)
			if ((x-s[i])%s[n]==0&&(x-s[i])/s[n]>=0) ans++;
		printf("%d\n",ans);
	}
	return 0;
}