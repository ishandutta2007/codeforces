#include<cstdio>
#include<bitset>
#include<algorithm>
#include<queue>
using namespace std;
#define N 160
int n,m,ct,a,b,c,dis[N];
struct sth{int a,b,c;friend bool operator <(sth a,sth b){return a.c<b.c;}}t[N];
bitset<N> as,as2;
struct mat{bitset<N> s[N];}s;
void mul(mat &a,mat &b)
{
	mat c;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	c.s[i][j]=(a.s[i]&b.s[j]).any();
	a=c;
}
mat pw(mat a,int p)
{
	mat c,ar,a1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	ar.s[i][j]=a.s[j][i];
	a1=a;
	for(int i=1;i<=n;i++)c.s[i].reset(),c.s[i].set(i,1);
	while(p){if(p&1)mul(c,ar);mul(a1,ar);mul(ar,a);a=a1;p>>=1;}
	return c;
}
int bfs(int ti)
{
	queue<int> tp;
	for(int i=1;i<=n;i++)dis[i]=-1;
	for(int i=1;i<=n;i++)if(as[i])tp.push(i),dis[i]=0;
	while(!tp.empty())
	{
		int q=tp.front();tp.pop();
		for(int i=1;i<=n;i++)
		if(s.s[q][i]&&dis[i]==-1)
		dis[i]=dis[q]+1,tp.push(i);
	}
	if(dis[n]==-1||dis[n]>ti)return -1;
	return dis[n];
}
int main()
{
	scanf("%d%d",&n,&m);
	as.reset();as.set(1,1);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(c==0)s.s[a].set(b,1);
		else t[++ct]=(sth){a,b,c};
	}
	sort(t+1,t+ct+1);
	t[ct+1].c=1998244353;
	int las=0;
	int tp=bfs(t[1].c-las);
	if(tp!=-1){printf("%d\n",tp+las);return 0;}
	mat t1=pw(s,t[1].c);
	as2.reset();
	for(int j=2;j<=n;j++)
	for(int k=1;k<j;k++)
	{
		int a=t1.s[j][k],b=t1.s[k][j];
		t1.s[j].set(k,b);
		t1.s[k].set(j,a);
	}
	for(int i=1;i<=n;i++)as2[i]=(as&t1.s[i]).any();
	as=as2;
	for(int i=1;i<=ct;i++)
	{
		s.s[t[i].a][t[i].b]=1;
		las=t[i].c;
		int tp=bfs(t[i+1].c-las);
		if(tp!=-1){printf("%d\n",tp+las);return 0;}
		int tp2=t[i+1].c-t[i].c;
		mat t1=pw(s,tp2);
		as2.reset();
		for(int j=2;j<=n;j++)
		for(int k=1;k<j;k++)
		{
			int a=t1.s[j][k],b=t1.s[k][j];
			t1.s[j].set(k,b);
			t1.s[k].set(j,a);
		}
		for(int i=1;i<=n;i++)as2[i]=(as&t1.s[i]).any();
		as=as2;
	}
	printf("Impossible\n");
}