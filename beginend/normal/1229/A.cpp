#include<bits/stdc++.h>

typedef long long LL;

const int N=10005;

int n,id[N];
LL a[N],b[N];
bool vis[N];

bool cmp(int x,int y)
{
	return a[x]<a[y];
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++) scanf("%lld",&b[i]),id[i]=i;
	std::sort(id+1,id+n+1,cmp);
	LL s=0;int t=0;
	for (int i=n;i>=1;i--)
	{
		int j=i;
		while (j>1&&a[id[j-1]]==a[id[j]]) j--;
		if (j<i)
		{
			for (int k=j;k<=i;k++) s+=b[id[k]],vis[k]=1,t++;
		}
		else
		{
			for (int k=i+1;k<=n;k++)
				if (vis[k]&&(a[id[k]]&a[id[i]])==a[id[i]]) {s+=b[id[i]];vis[i]=1;t++;break;}
		}
		i=j;
	}
	if (t<=1) s=0;
	printf("%lld\n",s);
	return 0;
}