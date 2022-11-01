#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int n,gd[30],m;
char g[30],s[100005],ch[100005];

int main()
{
	scanf("%s",g);
	int len=strlen(g);
	for (int i=0;i<len;i++) gd[g[i]-'a']=1;
	scanf("%s",s+1);
	n=strlen(s+1);
	int pos=0;
	for (int i=1;i<=n;i++) if (s[i]=='*') pos=i;
	scanf("%d",&m);
	while (m--)
	{
		scanf("%s",ch+1);
		len=strlen(ch+1);
		if (len<n-1&&pos||!pos&&len!=n)
		{
			puts("NO");
			continue;
		}
		int flag=0;
		if (!pos)
		{
			for (int i=1;i<=n;i++)
				if (s[i]=='?'&&!gd[ch[i]-'a']||s[i]!='?'&&s[i]!=ch[i])
				{
					flag=1;
					break;
				}
		}
		else
		{
			for (int i=1;i<pos;i++)
				if (s[i]=='?'&&!gd[ch[i]-'a']||s[i]!='?'&&s[i]!=ch[i])
				{
					flag=1;
					break;
				}
			for (int i=1;i<=n-pos;i++)
				if (s[n-i+1]=='?'&&!gd[ch[len-i+1]-'a']||s[n-i+1]!='?'&&s[n-i+1]!=ch[len-i+1])
				{
					flag=1;
					break;
				}
			for (int i=0;i<len-n+1;i++)
				if (gd[ch[pos+i]-'a'])
				{
					flag=1;
					break;
				}
		}
		if (flag) puts("NO");
		else puts("YES");
	}
	return 0;
}