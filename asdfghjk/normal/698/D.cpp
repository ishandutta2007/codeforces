#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct node
{
	int x,y;
}a[1005],b[1005];
node operator -(node a,node b)
{
	return (node){a.x-b.x,a.y-b.y};
}
long long Mult(node a,node b)
{
	return 1ll*a.x*b.y-1ll*a.y*b.x;
}
int K,n,i,j,k,x,y,z,p[10][1005][15],cnt[10][1005],q[1005],g[1005],len,ans,dzx,col[1005];
bool work(int i)
{
	if(i>len)
		return true;
	if(len>K)
		return false;
	int tk=len;
	for(int j=1;j<=cnt[q[i]][g[i]];++j)
		if(col[p[q[i]][g[i]][j]]!=dzx)
		{
			g[++len]=p[q[i]][g[i]][j];
			col[g[len]]=dzx;
		}
	if(work(i+1))
		return true;
	len=tk;
	return false;
}
int main()
{
	scanf("%d%d",&K,&n);
	for(i=1;i<=K;++i)
		scanf("%d%d",&a[i].x,&a[i].y);
	for(i=1;i<=n;++i)
		scanf("%d%d",&b[i].x,&b[i].y);
	for(i=1;i<=K;++i)
		for(j=1;j<=n;++j)
		{
			for(k=1;k<=n;++k)
				if(k!=j&&Mult(b[j]-a[i],b[k]-a[i])==0&&(a[i].x!=b[j].x&&b[k].x>min(a[i].x,b[j].x)&&b[k].x<max(a[i].x,b[j].x)||a[i].y!=b[j].y&&b[k].y>min(a[i].y,b[j].y)&&b[k].y<max(a[i].y,b[j].y)))
				{
					p[i][j][++cnt[i][j]]=k;
					if(cnt[i][j]>=K)
						break;
				}
			//printf("%d %d %d\n",i,j,cnt[i][j]);
		}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=K;++j)
			q[j]=j;
		while(1)
		{
			++dzx;
			g[len=1]=i;
			col[i]=dzx;
			if(work(1))
			{
				++ans;
				break;
			}
			if(!next_permutation(q+1,q+1+K))
				break;
		}
	}
	printf("%d",ans);
	return 0;
}