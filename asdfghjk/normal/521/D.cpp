#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int N=500005;
struct node
{
	int id,num,ty;
	long double c;
}g[N];
struct mode
{
	int id,ty;
}h[N];
ll u,w[N];
int K,n,m,a[N],mx[N],cnt,tot,i,j,k,t[N],id[N],b[N],bl[N],phh[N],ty[N];
vector<mode> vct[N];
bool tk[N];
bool cmp(mode a,mode b)
{
	return a.ty>b.ty;
}
bool cmq(node a,node b)
{
	return a.c>b.c;
}
bool cmr(mode a,mode b)
{
	return a.ty<b.ty;
}
int main()
{
	scanf("%d%d%d",&K,&n,&m);
	for(i=1;i<=K;++i)
	{
		scanf("%d",a+i);
		mx[i]=0;
	}
	for(i=1;i<=n;++i)
	{
		scanf("%d%d%d",t+i,id+i,b+i);
		if(t[i]==1)
		{
			if(b[i]-a[id[i]]>mx[id[i]])
			{
				bl[id[i]]=i;
				mx[id[i]]=b[i]-a[id[i]];
			}
		}
		else if(t[i]==2)
			vct[id[i]].push_back((mode){i,b[i]});
		else
			g[++cnt]=(node){i,0,-1,b[i]};
	}
	for(i=1;i<=K;++i)
	{
		sort(vct[i].begin(),vct[i].end(),cmp);
		for(j=0;j<=vct[i].size()+1;++j)
			w[j]=a[i],tk[j]=false;
		for(j=0,u=a[i];j<vct[i].size();++j)
		{
			u+=vct[i][j].ty;
			w[j+1]=max(w[j+1],u);
		}
		w[j+1]=max(w[j+1],u);
		if(mx[i]>0)
		{
			for(j=vct[i].size();j>=0;--j)
			if(w[j]+mx[i]>w[j+1])
			{
				w[j+1]=w[j]+mx[i];
				tk[j+1]=true;
			}
		}
		for(j=1;j<=vct[i].size()+1;++j)
			g[++cnt]=(node){i,j,tk[j],(long double)w[j]/(long double)w[j-1]};
	}
	sort(g+1,g+1+cnt,cmq);
	while(m>0&&(m>cnt||g[m].c<=1))
		--m;
	printf("%d\n",m);
	for(i=m;i>=1;--i)
		if(g[i].ty==-1)
			h[++tot]=(mode){g[i].id,3};
		else if(g[i].num>phh[g[i].id])
		{
			phh[g[i].id]=g[i].num;
			ty[g[i].id]=g[i].ty;
		}
	for(i=1;i<=K;++i)
		if(phh[i])
		{
			k=phh[i]-ty[i];
			for(j=0;j<k;++j)
				h[++tot]=(mode){vct[i][j].id,2};
			if(ty[i])
				h[++tot]=(mode){bl[i],1};
		}
	sort(h+1,h+1+tot,cmr);
	for(i=1;i<=tot;++i)
		printf("%d ",h[i].id);
	return 0;
}