#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int N=3005;
struct node
{
	int x,y;
}a[N],b[N];
int r,c,n,K,cnt,nxt[N],lst[N],w,i,j,k,x,y;
long long ans;
vector<int> vct[N];
bool cmp(node a,node b)
{
	if(a.y!=b.y)
		return a.y<b.y;
	return a.x<b.x;
}
int work(int l)
{
	int i=l;
	for(int j=1;j<K&&i;++j)
		i=nxt[i];
	if(i)
		return c-b[i].y+1;
	else
		return 0;
}
int main()
{
	scanf("%d%d%d%d",&r,&c,&n,&K);
	for(i=1;i<=n;++i)
		scanf("%d%d",&a[i].x,&a[i].y);
	for(i=1;i<=r;++i)
	{
		cnt=0;
		for(j=1;j<=n;++j)
			if(a[j].x>=i)
				b[++cnt]=a[j];
		sort(b+1,b+1+cnt,cmp);
		for(j=1;j<=cnt;++j)
			lst[j]=j-1,nxt[j]=j+1;
		nxt[0]=1,nxt[cnt]=0;
		w=0;
		for(j=1;j<=cnt;++j)
			w+=work(j)*(b[j].y-b[j-1].y);
		for(j=1;j<=r;++j)
			vct[j].clear();
		for(j=1;j<=cnt;++j)
			vct[b[j].x].push_back(j);
		for(j=r;j>=i;--j)
		{
			ans+=w;
			for(k=vct[j].size()-1;k>=0;--k)
			{
				x=vct[j][k];
				w-=work(x)*(b[x].y-b[lst[x]].y);
				for(x=lst[x],y=1;x&&y<=K;x=lst[x],++y)
					w-=work(x)*(b[x].y-b[lst[x]].y);
				x=vct[j][k];
				nxt[lst[x]]=nxt[x];
				lst[nxt[x]]=lst[x];
				if(nxt[x])
					w+=work(nxt[x])*(b[x].y-b[lst[x]].y);
				for(x=lst[x],y=1;x&&y<=K;x=lst[x],++y)
					w+=work(x)*(b[x].y-b[lst[x]].y);
			}
		}
	}
	printf("%lld",ans);
	return 0;
}