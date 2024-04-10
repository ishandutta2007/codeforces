#include<bits/stdc++.h>

const int N=55;

int n,s[2],a[N];
char str[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		s[0]=s[1]=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%s",str);
			a[i]=strlen(str);
			for (int j=0;j<a[i];j++)
				s[str[j]-'0']++;
		}
		std::sort(a+1,a+n+1);
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			int w=std::min(a[i]/2,s[0]/2);
			a[i]-=w*2;s[0]-=w*2;
			w=std::min(a[i]/2,s[1]/2);
			a[i]-=w*2;s[1]-=w*2;
			if ((a[i]&1)&&(s[0]&1)) a[i]--,s[0]--;
			if ((a[i]&1)&&(s[1]&1)) a[i]--,s[1]--;
			if ((a[i]&1)&&s[0]) a[i]--,s[0]--;
			if ((a[i]&1)&&s[1]) a[i]--,s[1]--;
			if (!a[i]) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}