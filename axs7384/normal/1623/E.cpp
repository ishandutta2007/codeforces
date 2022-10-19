#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m;
char s[N];
int l[N],r[N],g[N],f[N],nx[N],a[N],cnt;
inline void dfs(int x)
{
	if (!x)
		return;
	dfs(l[x]);
	a[++cnt]=x;
	dfs(r[x]);
}
inline void work(int x)
{
	if (!g[x])
		return;
	if (l[x])
	{
		g[l[x]]=g[x]-1;
		work(l[x]);
		f[x]=f[l[x]];
	}
	if (nx[x]||f[l[x]])
	{
		f[x]++;
		if (r[x])
		{
			g[r[x]]=g[x]-f[x];
			work(r[x]);
			f[x]+=f[r[x]];
		}
	}
}
inline void sc(int x)
{
	if (!x)
		return;
	sc(l[x]);
	putchar(s[x]);
	if (f[x])
		putchar(s[x]);
	sc(r[x]);
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for (int i=1;i<=n;++i)
		scanf("%d%d",&l[i],&r[i]);
	dfs(1);
	for (int i=n;i>=1;--i)
		if (s[a[i]]==s[a[i+1]])
			nx[a[i]]=nx[a[i+1]];
		else
			nx[a[i]]=(s[a[i]]<s[a[i+1]]);
	g[1]=m;
	work(1);
	sc(1);
	putchar('\n');
	return 0;
}