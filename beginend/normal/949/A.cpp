#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=200005;

int n,s[N],a[N],stack[N],nx[N];
char str[N];
bool vis[N];

int main()
{
	scanf("%s",str+1);n=strlen(str+1);
	for (int i=1;i<=n;i++) s[i]=str[i]-'0';
	int top=0;
	for (int i=1;i<=n;i++)
		if (s[i]==0) stack[++top]=i;
		else
		{
			if (!top) {puts("-1");return 0;}
			nx[stack[top]]=i;top--;
		}
	top=0;
	for (int i=n;i>=1;i--)
		if (s[i]==0) stack[++top]=i;
		else
		{
			if (!top) {puts("-1");return 0;}
			nx[i]=stack[top];top--;
		}
	int ans=0;
	for (int i=1;i<=n;i++)
		if (!vis[i])
		{
			ans++;
			int x=i;vis[x]=1;a[i]=1;
			while (nx[x]) x=nx[x],vis[x]=1,a[i]++;
		}
	printf("%d\n",ans);
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++)
		if (!vis[i])
		{
			printf("%d ",a[i]);
			int x=i;printf("%d ",x);
			while (nx[x]) x=nx[x],vis[x]=1,printf("%d ",x);
			puts("");
		}
	return 0;
}