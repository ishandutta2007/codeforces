#include<bits/stdc++.h>

typedef unsigned long long LL;

const int N=105;
const int M=35;
const LL BAS=2333;

int n,bin[M],a[N],t[N],s[N];
std::map<LL,int> ma;

LL get_hash(int *t)
{
	LL ans=0;
	for (int i=1;i<n;i++) ans=(LL)ans*BAS+(LL)t[i];
	return ans;
}

void dfs1(int x,int now)
{
	if (x==15)
	{
		for (int i=1;i<n;i++) t[i]=s[i+1]-s[i];
		LL w=get_hash(t);
		ma[w]=now+1;
		return;
	}
	for (int i=1;i<=n;i++)
		if (!(a[i]&bin[x])) s[i]++;
		else s[i]--;
	dfs1(x+1,now+bin[x]);
	for (int i=1;i<=n;i++)
		if (!(a[i]&bin[x])) s[i]--;
		else s[i]++;
	dfs1(x+1,now);
}

void dfs2(int x,int now)
{
	if (x==30)
	{
		for (int i=1;i<n;i++) t[i]=s[i]-s[i+1];
		LL w=get_hash(t);
		if (ma[w]) {printf("%d\n",ma[w]-1+now);exit(0);}
		return;
	}
	dfs2(x+1,now);
	for (int i=1;i<=n;i++)
		if (!(a[i]&bin[x])) s[i]++;
		else s[i]--;
	dfs2(x+1,now+bin[x]);
	for (int i=1;i<=n;i++)
		if (!(a[i]&bin[x])) s[i]--;
		else s[i]++;
}

int main()
{
	bin[0]=1;
	for (int i=1;i<=30;i++) bin[i]=bin[i-1]*2;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		for (int j=0;j<15;j++)
			if (a[i]&bin[j]) s[i]++;
	dfs1(0,0);
	memset(s,0,sizeof(s));
	for (int i=1;i<=n;i++)
		for (int j=15;j<30;j++)
			if (a[i]&bin[j]) s[i]++;
	dfs2(15,0);
	puts("-1");
	return 0;
}