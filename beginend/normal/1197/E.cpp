#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ls d<<1
#define rs d<<1|1

const int N=200005;
const int inf=(1e9)+5;
const int MOD=1000000007;

int n,rmq[N][25],bin[25],lg[N],mn,cnt,f[N],g[N];
struct tree{int mn,s;}t[N*4];
struct data{int in,out;}a[N];

bool cmp(data a,data b)
{
	return a.out<b.out;
}

void get_rmq()
{
	for (int i=1;i<=n;i++) rmq[i][0]=a[i].in,lg[i]=log(i)/log(2);
	bin[0]=1;
	for (int i=1;i<=lg[n];i++) bin[i]=bin[i-1]*2;
	for (int j=1;j<=lg[n];j++)
		for (int i=1;i+bin[j]-1<=n;i++)
			rmq[i][j]=std::max(rmq[i][j-1],rmq[i+bin[j-1]][j-1]);
}

int get_mx(int l,int r)
{
	int w=lg[r-l+1];
	return std::max(rmq[l][w],rmq[r-bin[w]+1][w]);
}

void ins(int d,int l,int r,int x)
{
	if (l==r) {t[d].mn=f[x]-a[x].out;t[d].s=g[x];return;}
	int mid=(l+r)/2;
	if (x<=mid) ins(ls,l,mid,x);
	else ins(rs,mid+1,r,x);
	t[d]=t[ls];
	if (t[rs].mn<t[d].mn) t[d]=t[rs];
	else if (t[rs].mn==t[d].mn) (t[d].s+=t[rs].s)%=MOD;
}

void query(int d,int l,int r,int x,int y)
{
	if (x<=l&&r<=y)
	{
		if (t[d].mn<mn) mn=t[d].mn,cnt=t[d].s;
		else if (t[d].mn==mn) (cnt+=t[d].s)%=MOD;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) query(ls,l,mid,x,y);
	if (y>mid) query(rs,mid+1,r,x,y);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].out,&a[i].in);
	std::sort(a+1,a+n+1,cmp);
	get_rmq();
	g[0]=1;
	ins(1,0,n,0);
	int mxl=0;
	for (int i=1;i<=n;i++)
	{
		int l=1,r=i-1;
		while (l<=r)
		{
			int mid=(l+r)/2;
			if (a[mid].out<=a[i].in) l=mid+1;
			else r=mid-1;
		}
		int lim=l-1;
		mxl=std::max(mxl,lim);
		l=0;r=lim-1;
		while (l<=r)
		{
			int mid=(l+r)/2;
			if (a[mid].out<=get_mx(mid+1,r)) l=mid+1;
			else r=mid-1;
		}
		mn=inf;cnt=0;
		query(1,0,n,l,lim);
		f[i]=mn+a[i].in;g[i]=cnt;
		ins(1,0,n,i);
	}
	mn=inf;cnt=0;
	for (int i=mxl+1;i<=n;i++)
		if (f[i]<mn) mn=f[i],cnt=g[i];
		else if (f[i]==mn) (cnt+=g[i])%=MOD;
	printf("%d\n",cnt);
	return 0;
}