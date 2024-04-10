#include<bits/stdc++.h>

const int N=200005;

int n,f[N],id[30];
char str[55];

int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		f[i]=i;
		scanf("%s",str);
		int k=strlen(str);
		for (int j=0;j<k;j++)
		{
			int t=str[j]-'a';
			if (!id[t]) id[t]=i;
			else f[find(i)]=find(id[t]);
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++) ans+=f[i]==i;
	printf("%d\n",ans);
	return 0;
}