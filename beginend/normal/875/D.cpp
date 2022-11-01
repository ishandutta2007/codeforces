#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long LL;

const int N=200005;

int n,rmq[N][20],lg[N],a[N],bin[40],c[40][N],low[40][N],tot[40];
LL ans;

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void get_rmq()
{
	for (int i=1;i<=n;i++) rmq[i][0]=i;
	for (int j=1;j<=lg[n];j++)
		for (int i=1;i+bin[j]-1<=n;i++)
			rmq[i][j]=a[rmq[i][j-1]]>a[rmq[i+bin[j-1]][j-1]]?rmq[i][j-1]:rmq[i+bin[j-1]][j-1];
}

int get_mx(int l,int r)
{
	int w=lg[r-l+1];
	return a[rmq[l][w]]>a[rmq[r-bin[w]+1][w]]?rmq[l][w]:rmq[r-bin[w]+1][w];
}

void solve(int l,int r)
{
	if (l>r) return;
	int mid=get_mx(l,r),L=l-1,R=r+1;
	for (int i=0;i<=30;i++)
		if (!(a[mid]&bin[i]))
		{
			if (low[i][mid]) L=max(L,c[i][low[i][mid]]);
			if (low[i][mid]<tot[i]) R=min(R,c[i][low[i][mid]+1]);
		}
	ans-=(LL)(mid-L)*(R-mid);
	solve(l,mid-1);solve(mid+1,r);
}

int main()
{
	//freopen("a.in","r",stdin);
	bin[0]=1;
	for (int i=1;i<=30;i++) bin[i]=bin[i-1]*2;
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),lg[i]=log(i)/log(2);
	get_rmq();
	for (int i=0;i<=30;i++)
		for (int j=1;j<=n;j++)
			if (a[j]&bin[i]) c[i][++tot[i]]=j,low[i][j]=tot[i];
			else low[i][j]=tot[i];
	ans=(LL)n*(n+1)/2;
	solve(1,n);
	printf("%I64d",ans);
	return 0;
}