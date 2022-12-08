#include<cstdio>
const int maxn=200001;
int n,p[maxn],fa[maxn],q[maxn],c[maxn],num;
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
	int root=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		q[i]=p[i];
		if(i==p[i]&&root==0)root=i;
		int a=find(i),b=find(p[i]);
		if(a==b)c[++num]=i;
		else fa[a]=b;
	}
	if(!root)root=c[num--],p[root]=root;
	for(int i=1;i<=num;i++)p[c[i]]=root;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i==p[i])p[i]=root;
		if(p[i]!=q[i])ans++;
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)printf("%d ",p[i]);
	return 0;
}