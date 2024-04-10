#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=305;
struct node
{
	int x,y;
}a[N],e[N*N];
int n,i,j,k,cnt;
ll f[N][N][10],ans;
node operator -(node a,node b)
{
	return (node){a.x-b.x,a.y-b.y};
}
ll mult(node a,node b)
{
	return 1ll*a.x*b.y-1ll*a.y*b.x;
}
int xx(node a)
{
	if(a.x>0)
	{
		if(a.y>0)
			return 1;
		else
			return 4;
	}
	else
	{
		if(a.y>0)
			return 2;
		else
			return 3;
	}
}
bool cmp(node p,node q)
{
	node g=a[p.y]-a[p.x],h=a[q.y]-a[q.x];
	int xx1=xx(g),xx2=xx(h);
	if(xx1!=xx2)
		return xx1<xx2;
	return mult(g,h)>0;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d%d",&a[i].x,&a[i].y);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			if(i!=j)
				e[++cnt]=(node){i,j};
	sort(e+1,e+1+cnt,cmp);
	for(i=1;i<=cnt;++i)
	{
		f[e[i].x][e[i].y][1]++;
		for(j=1;j<=n;++j)
			for(k=1;k<=4;++k)
			{
				f[j][e[i].y][k+1]+=f[j][e[i].x][k]*f[e[i].x][e[i].y][1];
				//printf("%d %d %d %lld\n",j,e[i].y,k+1,f[j][e[i].y][k+1]);
			}
	}
	for(i=1;i<=n;++i)
		ans+=f[i][i][5];
	printf("%lld",ans);
	return 0;
}