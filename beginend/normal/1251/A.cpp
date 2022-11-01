#include<bits/stdc++.h>

const int N=505;

int n;
bool vis[26];
char s[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%s",s);
		memset(vis,0,sizeof(vis));
		n=strlen(s);
		int now=s[0]-'a',w=1;
		for (int i=1;i<n;i++)
			if (s[i]-'a'==now) w++;
			else
			{
				if (w&1) vis[now]=1;
				now=s[i]-'a';
				w=1;
			}
		if (w&1) vis[now]=1;
		for (int i=0;i<26;i++)
			if (vis[i]) putchar(i+'a');
		puts("");
	}
	return 0;
}