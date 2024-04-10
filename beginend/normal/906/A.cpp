#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int n,c,pro[26];
bool vis[26];
char ch[100005];

int main()
{
	scanf("%d",&n);
	for (int i=0;i<26;i++) pro[i]=1;
	int ans=0,flag=0;
	while (n--)
	{
		char op[2];scanf("%s%s",op,ch);
		int len=strlen(ch);
		if (flag)
		{
			if (op[0]=='?')
			{
				if (ch[0]-'a'!=c) ans++;
				continue;
			}
			for (int i=0;i<len;i++) if (ch[i]-'a'==c) {ans++;break;}
			continue;
		}
		if (op[0]=='.')
		{
			for (int i=0;i<len;i++) pro[ch[i]-'a']=0;
		}
		else if (op[0]=='!')
		{
			for (int i=0;i<len;i++) vis[ch[i]-'a']=1;
			for (int i=0;i<26;i++)
				if (!vis[i]) pro[i]=0;
			for (int i=0;i<26;i++) vis[i]=0;
		}
		else
		{
			pro[ch[0]-'a']=0;
		}
		int s=0;
		for (int i=0;i<26;i++) if (pro[i]==1) s++,c=i;
		if (s==1) flag=1;
	}
	printf("%d",ans);
	return 0;
}