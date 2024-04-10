#include<bits/stdc++.h>

const int N=100005;

int n,m,nx[N][26],ls[26];
char s[N],t[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1);m=strlen(t+1);
		memset(ls,0,sizeof(ls));
		for (int i=n;i>=0;i--)
		{
			for (int j=0;j<26;j++) nx[i][j]=ls[j];
			if (i) ls[s[i]-'a']=i;
		}
		int ans=0,p=1;
		while (p<=m)
		{
			int now=0;
			ans++;
			while (p<=m&&now<n)
				if (!nx[now][t[p]-'a']) break;
				else now=nx[now][t[p]-'a'],p++;
			if (!now) {ans=-1;break;}
		}
		printf("%d\n",ans);
	}
	return 0;
}