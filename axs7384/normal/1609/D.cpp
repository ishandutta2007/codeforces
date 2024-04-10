#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,tot;
int fa[N],si[N];
vector<int> v;
inline int getfa(int x)
{
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
inline void merge(int x,int y)
{
	x=getfa(x);
	y=getfa(y);
	if (x==y)
	{
		++tot;
		return;
	}
	if (si[x]<si[y])
		swap(x,y);
	si[x]+=si[y];
	fa[y]=x;
}

int main()
{
	scanf("%d%d",&n,&m);
	tot=1;
	for (int i=1;i<=n;++i)
	{
		fa[i]=i;
		si[i]=1;
	}
	for (int i=1,x,y;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		merge(x,y);
		int sum=0;
		v.clear();
		for (int j=1;j<=n;++j)
		{
			getfa(j);
			if (fa[j]==j)
				v.push_back(si[j]);
		}
		sort(v.begin(),v.end(),greater<int>());
		for (int j=0;j<(int)v.size()&&j<tot;++j)
			sum+=v[j];
		printf("%d\n",sum-1);
	}
	return 0;
}