#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cstring>
#include<bitset>
#include<queue>
using namespace std;
const int N=155;
const int MAX=(1<<30);
int n,m;
struct qq{int x,y,d;}E[N];
struct qt{int x,y,last;}e[N];int num,last[N];
void init (int x,int y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
bool cmp (qq x,qq y){return x.d<y.d;}
struct matrix
{
	bitset<N> s[N];
	matrix()	{for (int u=0;u<N;u++) s[u].reset();}
	matrix operator * (matrix x)
	{
		bitset<N> a[N];
		for (int u=1;u<=n;u++)
			for (int i=1;i<=n;i++)
				a[u][i]=x.s[i][u];
		matrix ans;
		for (int u=1;u<=n;u++)
			for (int i=1;i<=n;i++)
				ans.s[u][i]=(s[u]&a[i]).any();
		return ans;
	}
}g,h;
matrix pow (matrix x,int y)
{
	if (y==1) return x;
	matrix lalal=pow(x,y>>1);
	lalal=lalal*lalal;
	if (y&1) lalal=lalal*x;
	return lalal;
}
int d[N];
int bfs (bitset<N> start)
{
	queue<int> q;
	for (int u=1;u<=n;u++)
		if (start[u]==1)
		{
		//	printf("%d\n",u);
			q.push(u);
			d[u]=0;
		}
		else d[u]=-1;
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (int u=last[x];u!=-1;u=e[u].last)
		{
			int y=e[u].y;
			if (d[y]==-1)
			{
				d[y]=d[x]+1;
				q.push(y);
			}
		}
	}
	return d[n];
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%d%d",&n,&m);
	for (int u=1;u<=m;u++)	scanf("%d%d%d",&E[u].x,&E[u].y,&E[u].d);
	sort(E+1,E+1+m,cmp);
	for (int u=1;u<=n;u++)	g.s[u][u]=1;
	int now=0;
	int Ans=MAX;
	for (int u=1;u<=m;u++)
	{
		if (now!=E[u].d)
		{
			g=g*pow(h,E[u].d-now);
			/*for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=n;j++)
					if (pow(h,E[u].d-now).s[i][j]) printf("1 ");
					else printf("0 ");
				printf("\n");
			}*/
			now=E[u].d;
		}
	//	printf("%d\n",now);
		int x=E[u].x,y=E[u].y;
		h.s[x][y]=1;
		init(x,y);
		int ans=bfs(g.s[1]);
		if (ans!=-1)
			Ans=min(Ans,ans+now);
	//	system("pause");
	}
	if (Ans!=MAX) printf("%d\n",Ans);
	else printf("Impossible\n");
	return 0;
}