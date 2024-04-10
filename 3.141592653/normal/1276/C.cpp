#include<cstdio>
#include<cstring>
#include<algorithm>
#define lowbit(x) ((x)&(-(x)))
#define errlog(...) fprintf(stderr,__VA_ARGS__)
typedef long long ll;
typedef double db;
inline int min(int x,int y)
{return(x<y)?x:y;}
inline int max(int x,int y)
{return(x>y)?x:y;}
inline int abs(int x)
{return(x>0)?x:-x;}
int n;
int a[444444];
int f[444444];
#include<queue>
struct pii
{
	int x,t,id;
}p[444444];int top=0;
std::priority_queue<pii>q;
int r[444444];
inline bool operator<(const pii x,const pii y)
{return x.t<y.t;}
#include<vector>
std::vector<int>v[444444];
void print(int x)
{
	int X=f[x],Y=x/f[x];
	printf("%d\n%d %d\n",x,f[x],x/f[x]);
	register int i,ii;
	for(i=1;i<=X+5;i++)v[i].resize(Y+5);
	int tx=1,ty=1;
	while(q.size())
	{
		pii t=q.top();q.pop();
		for(i=1;i<=t.t;i++)
		{
			v[tx][ty]=t.x;
			tx++,ty++;
			if(tx>X)tx=1;
			if(ty>Y)ty=1;
			if(v[tx][ty])ty++;
		}
	}
	for(i=1;i<=X;i++)
		for(ii=1;ii<=Y;ii++)
			printf("%d%c",v[i][ii],(ii^Y)?' ':'\n');
}
int main()
{
	scanf("%d",&n);
	register int i,ii;
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		int tot=1;while(a[i]==a[i+1])i++,tot++;
		top++,p[top]=(pii){a[i],tot,top},q.push(p[top]);
	}for(i=1;i<=n;i++)
		for(ii=i;ii<=n/i;ii++)
			if(f[i*ii]<i)f[i*ii]=i;
	for(i=n;i;i--)
	{
		pii t=q.top();
		r[i]=t.t;
		if(r[i]<=f[i])return print(i),0;
		q.pop(),q.push((pii){t.x,t.t-1,t.id});
	}//for(i=1;i<=n;i++)errlog("%d\n",r[i]);
}