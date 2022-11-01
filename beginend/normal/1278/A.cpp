#include<bits/stdc++.h>

const int N=105;

int n,m,a[26],pre[N][26];
char h[N],p[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%s%s",p+1,h+1);
		n=strlen(p+1);
		m=strlen(h+1);
		if (m<n) {puts("NO");continue;}
		memset(a,0,sizeof(a));
		for (int i=1;i<=n;i++) a[p[i]-'a']++;
		for (int i=1;i<=m;i++)
		{
			for (int j=0;j<26;j++) pre[i][j]=pre[i-1][j];
			pre[i][h[i]-'a']++;
		}
		bool flag=0;
		for (int i=n;i<=m;i++)
		{
			int t=0;
			for (int j=0;j<26;j++)
				if (a[j]==pre[i][j]-pre[i-n][j]) t++;
			if (t==26)
			{
				flag=1;
				break;
			}
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}