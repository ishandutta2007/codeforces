#include<bits/stdc++.h>
#define pb push_back

typedef long long LL;

const int N=500005;

int n,m,id[N];
LL a[N];
std::vector<int> e[N];

LL gcd(LL x,LL y)
{
	if (!y) return x;
	else return gcd(y,x%y);
}

bool cmp(int x,int y)
{
	int k=std::min(e[x].size(),e[y].size());
	for (int i=0;i<k;i++)
		if (e[x][i]<e[y][i]) return 1;
		else if (e[x][i]>e[y][i]) return 0;
	return e[x].size()<e[y].size();
}

bool cmp1(int x,int y)
{
	int k=std::min(e[x].size(),e[y].size());
	if (e[x].size()!=e[y].size()) return 0; 
	for (int i=0;i<k;i++)
		if (e[x][i]!=e[y][i]) return 0;
	return 1;
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) scanf("%lld",&a[i]),e[i].clear();
		for (int i=1;i<=m;i++)
		{
			int x,y;scanf("%d%d",&x,&y);
			e[y].pb(x); 
		}
		for (int i=1;i<=n;i++) std::sort(e[i].begin(),e[i].end());
		for (int i=1;i<=n;i++) id[i]=i;
		std::sort(id+1,id+n+1,cmp);
		LL ans=0;
		for (int i=1;i<=n;i++)
		{
			if (!e[id[i]].size()) continue;
			LL s=a[id[i]];
			int j=i;
			while (j<n&&cmp1(id[i],id[j+1])) j++,s+=a[id[j]];
			ans=gcd(ans,s);
			i=j;
		}
		printf("%lld\n",ans);
	}
	return 0;
}