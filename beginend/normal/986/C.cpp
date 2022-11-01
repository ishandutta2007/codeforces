#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=(1<<22)+5;

int n,m,bin[25],f[N],a[N];
bool vis[N],pre[N];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int find(int x)
{
	if (f[x]==x) return x;
	else return f[x]=find(f[x]);
}

void work(int x,int y)
{
	if (!pre[x]) return;
	if (find(x)==find(y)) return;
	f[find(x)]=find(y);
	for (int i=0;i<n;i++)
		if (x&bin[i]) work(x^bin[i],y);
}

int main()
{
	n=read();m=read();
	bin[0]=1;
	for (int i=1;i<=n;i++) bin[i]=bin[i-1]*2;
	for (int i=0;i<bin[n];i++) f[i]=i;
	for (int i=1;i<=m;i++) a[i]=read(),pre[a[i]]=1;
	for (int i=1;i<bin[n];i++)
		for (int j=0;j<n;j++)
			if (i&bin[j]) pre[i]|=pre[i^bin[j]];
	for (int i=1;i<=m;i++) work(a[i]^(bin[n]-1),a[i]);
	int ans=0;
	for (int i=1;i<=m;i++)
		if (!vis[find(a[i])]) ans++,vis[find(a[i])]=1;
	printf("%d",ans);
	return 0;
}