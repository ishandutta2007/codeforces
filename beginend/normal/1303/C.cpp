#include<bits/stdc++.h>

char str[205],ans[105];
bool vis[105];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%s",str+1);
		int n=strlen(str+1),l=27,r=27,now=27,flag=0;
		ans[l]=str[1];
		memset(vis,0,sizeof(vis));
		vis[str[1]-'a']=1;
		for (int i=2;i<=n;i++)
		{
			if (now>l&&ans[now-1]==str[i]) now--;
			else if (now<r&&ans[now+1]==str[i]) now++;
			else if (now==l&&!vis[str[i]-'a']) ans[--l]=str[i],now--,vis[str[i]-'a']=1;
			else if (now==r&&!vis[str[i]-'a']) ans[++r]=str[i],now++,vis[str[i]-'a']=1;
			else {flag=1;break;}
		}
		if (flag) puts("NO");
		else
		{
			puts("YES");
			for (int i=l;i<=r;i++) putchar(ans[i]);
			for (int i=0;i<26;i++)
				if (!vis[i]) putchar(i+'a');
			puts("");
		}
	}
	return 0;
}