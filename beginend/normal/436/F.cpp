#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>

typedef long long LL;

const int N=100005;
const int M=405;

int n,w,m,bel[N],lef[M],rig[M],tag[M],pts[M],sta[N],top[M],pos[N],Pos;
LL Val,ans[N],b[N];
struct data{int x,y;}a[N];

bool cmp(data a,data b)
{
	return a.y<b.y;
}

double get_x(int x,int y)
{
	return (double)1.0*(b[x]-b[y])/(y-x);
}

void build(int id)
{
	int l=lef[id],r=rig[id];
	for (int i=l;i<=r;i++) b[i]+=(LL)i*tag[id];
	tag[id]=0;
	top[id]=l-1;
	for (int i=l;i<=r;i++)
	{
		while (top[id]>l&&get_x(i,sta[top[id]-1])<=get_x(sta[top[id]],sta[top[id]-1])) top[id]--;
		while (top[id]>=l&&b[i]>=b[sta[top[id]]]) top[id]--;
		sta[++top[id]]=i;
	}
	pts[id]=l;
}

void init()
{
	int B=sqrt(m);
	for (int i=1;i<=m;i++)
	{
		bel[i]=(i+B-1)/B;
		if (!lef[bel[i]]) lef[bel[i]]=i;
		rig[bel[i]]=i;
	}
	for (int i=1;i<=bel[m];i++) build(i);
}

void ins(int x)
{
	for (int i=1;i<bel[x];i++)
	{
		tag[i]++;
		while (pts[i]<top[i]&&(LL)tag[i]*sta[pts[i]+1]+b[sta[pts[i]+1]]>=(LL)tag[i]*sta[pts[i]]+b[sta[pts[i]]]) pts[i]++;
	}
	for (int i=lef[bel[x]];i<=x;i++) b[i]+=i;
	build(bel[x]);
}

void query()
{
	Val=Pos=0;
	for (int i=1;i<=bel[m];i++)
	{
		LL w=(LL)tag[i]*sta[pts[i]]+b[sta[pts[i]]];
		if (w>Val) Val=w,Pos=sta[pts[i]];
	}
}

int main()
{
	scanf("%d%d",&n,&w);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y),m=std::max(m,a[i].x);
	init();
	std::sort(a+1,a+n+1,cmp);
	a[n+1].y=a[n].y+1;
	for (int i=1;i<=a[1].y;i++) ans[i]=(LL)w*i*n;
	for (int i=1;i<=n;i++)
	{
		int j=i;
		while (j<n&&a[j+1].y==a[j].y) j++;
		for (int k=i;k<=j;k++) ins(a[k].x);
		query();
		for (int k=a[j].y+1;k<=a[j+1].y;k++) ans[k]=Val+(LL)w*k*(n-j),pos[k]=Pos;
		i=j;
	}
	for (int i=0;i<=a[n+1].y;i++) printf("%lld %d\n",ans[i],pos[i]);
	return 0;
}