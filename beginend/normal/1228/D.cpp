#include<bits/stdc++.h>
#define mp std::make_pair

typedef std::pair<int,int> pi;
typedef long long LL;

const int N=100005;

int n,m,tot[4],a[4][N],col[N];
std::map<pi,int> ma;

int main()
{
	scanf("%d%d",&n,&m);
	if (!m) {puts("-1");return 0;}
	int u,v;
	for (int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		ma[mp(x,y)]=ma[mp(y,x)]=1;
		u=x;v=y;
	}
	col[u]=1;col[v]=2;
	a[1][++tot[1]]=u;
	a[2][++tot[2]]=v;
	for (int i=1;i<=n;i++)
	{
		if (i==u||i==v) continue;
		if (!ma[mp(i,u)]&&!ma[mp(i,v)]) {puts("-1");return 0;}
		if (!ma[mp(i,u)]) col[i]=1,a[1][++tot[1]]=i;
		else if (!ma[mp(i,v)]) col[i]=2,a[2][++tot[2]]=i;
		else col[i]=3,a[3][++tot[3]]=i;
	}
	if ((LL)tot[1]*tot[2]+(LL)tot[2]*tot[3]+(LL)tot[3]*tot[1]!=(LL)m||!tot[3]) {puts("-1");return 0;}
	for (int i=1;i<3;i++)
		for (int j=i+1;j<=3;j++)
			for (int k=1;k<=tot[i];k++)
				for (int l=1;l<=tot[j];l++)
					if (!ma[mp(a[i][k],a[j][l])]) {puts("-1");return 0;}
	for (int i=1;i<=n;i++) printf("%d ",col[i]);
	return 0;
}