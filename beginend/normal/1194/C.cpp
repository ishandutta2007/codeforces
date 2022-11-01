#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=105;

int n,m,k,cnt[26],nx[N][26],ls[26];
char s[N],t[N],p[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%s%s%s",s+1,t+1,p+1);
		n=strlen(s+1);
		m=strlen(t+1);
		k=strlen(p+1);
		memset(cnt,0,sizeof(cnt));
		for (int i=1;i<=k;i++) cnt[p[i]-'a']++;
		for (int i=1;i<=m;i++) cnt[t[i]-'a']--;
		for (int i=1;i<=n;i++) cnt[s[i]-'a']++;
		memset(ls,0,sizeof(ls));
		for (int i=m;i>=1;i--)
		{
			for (int j=0;j<26;j++) nx[i][j]=ls[j];
			ls[t[i]-'a']=i;
		}
		for (int i=0;i<26;i++) nx[0][i]=ls[i];
		int now=0;
		for (int i=1;i<=n;i++)
		{
			if (!nx[now][s[i]-'a']) {now=0;break;}
			now=nx[now][s[i]-'a'];
		}
		if (!now) {puts("NO");continue;}
		bool flag=0;
		for (int i=0;i<26;i++) if (cnt[i]<0) {flag=1;break;}
		if (flag) puts("NO");
		else puts("YES");
	}
	return 0;
}