#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1000005;
const int MOD=1000000007;

int n,last,sz,len[N],fail[N],ch[N][26],id[N],f[N],diff[N],nxt[N],g[N];
char str[N],s[N];

int extend(int x,int n)
{
	int p=last;
	while (s[n-len[p]-1]!=s[n]) p=fail[p];
	if (!ch[p][x])
	{
		int now=++sz,k=fail[p];len[now]=len[p]+2;
		while (s[n-len[k]-1]!=s[n]) k=fail[k];
		fail[now]=ch[k][x];ch[p][x]=now;
		diff[now]=len[now]-len[fail[now]];
		if (diff[now]==diff[fail[now]]) nxt[now]=nxt[fail[now]];
		else nxt[now]=fail[now];
	}
	last=ch[p][x];return last;
}

int main()
{
	scanf("%s",str+1);
	n=strlen(str+1);
	int now=0;
	for (int i=1;i<=n;i+=2) s[i]=str[++now];
	now=n+1;
	for (int i=2;i<=n;i+=2) s[i]=str[--now];
	fail[0]=1;len[1]=-1;sz=1;
	for (int i=1;i<=n;i++) id[i]=extend(s[i]-'a',i);
	f[0]=1;
	for (int i=1;i<=n;i++)
		for (int p=id[i];p;p=nxt[p])
		{
			g[p]=f[i-(len[nxt[p]]+diff[p])];
			if (diff[p]==diff[fail[p]]) (g[p]+=g[fail[p]])%=MOD;
			if (!(i&1)) (f[i]+=g[p])%=MOD;
		}
	printf("%d",f[n]);
	return 0;
}