#include<bits/stdc++.h>

const int N=405;

int n,m,f[N][N];
char s[N],t[N];

bool check()
{
	if (m==1)
	{
		for (int i=1;i<=n;i++)
			if (s[i]==t[1]) return 1;
		return 0;
	}
	for (int k=2;k<=m;k++)
	{
		for (int i=0;i<=n;i++)
			for (int j=0;j<=m;j++)
				f[i][j]=0;
		f[0][0]=k-1;
		for (int i=0;i<=n;i++)
			for (int j=0;j<k;j++)
			{
				if (!f[i][j]) continue;
				f[i+1][j]=std::max(f[i+1][j],f[i][j]);
				if (i<n&&s[i+1]==t[j+1]) f[i+1][j+1]=std::max(f[i+1][j+1],f[i][j]);
				if (i<n&&s[i+1]==t[f[i][j]+1]) f[i+1][j]=std::max(f[i+1][j],f[i][j]+1);
			}
		if (f[n][k-1]==m) return 1;
	}
	return 0;
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1);m=strlen(t+1);
		if (check()) puts("YES");
		else puts("NO");		
	}
	return 0;
}