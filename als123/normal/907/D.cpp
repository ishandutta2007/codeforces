#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
const int N=100005;
int n,m;
vector<int> lalal[N];
vector<int> a[N],b[N];
int fx[4]={-1,0,0,1};
int fy[4]={0,-1,1,0};
bool ok[N];
bool check (int o,int x,int y)
{
	if (x<=0||y<=0) return false;
	int size=lalal[o].size();
	for (int u=0;u<size;u++)
		if (lalal[o][u]==b[x][y])
			return true;
	return false;
}
int myrand ()
{
	return rand()*rand()%(n*m)+1;
}
void solve ()
{
	int num;
	for (int u=1;u<=n;u++)
		for (int i=1;i<=m;i++)
		{
			num=0;
			int x=myrand();
			while ((num<=(n*m)*2)&&(ok[x]==false||check(x,u-1,i)||check(x,u,i-1)))
			{
				x=myrand();
				num++;
			}
			if (num>(n*m)*2)	return ;
			ok[x]=false;
			b[u][i]=x;
		}
	printf("YES\n");
	for (int u=1;u<=n;u++)
	{
		for (int i=1;i<=m;i++)
			printf("%d ",b[u][i]);
		printf("\n");
	}
	exit(0);
}
int main()
{
	srand(87);
	scanf("%d%d",&n,&m);
	for (int u=1;u<=n;u++)
	{
		a[u].resize(m+5);
		b[u].resize(m+5);
		for (int i=1;i<=m;i++)
			a[u][i]=(u-1)*m+i;
	}
	for (int u=1;u<=n;u++)
		for (int i=1;i<=m;i++)
			for (int j=0;j<4;j++)
			{
				int nx=u+fx[j],ny=i+fy[j];
				if (nx>=1&&nx<=n&&ny>=1&&ny<=m)
					lalal[a[u][i]].push_back(a[nx][ny]);
			}
	for (int u=1;u<=100;u++)
	{
		memset(ok,true,sizeof(ok));
		solve();
	}
	printf("NO\n");
	return 0;
}