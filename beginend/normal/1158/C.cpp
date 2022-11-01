#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=500005;

int n,nx[N],a[N];
bool vis[N],flag;

void work(int l,int r,int L,int R)
{
	if (l>r) return;
	if (R-L+1<r-l+1) flag=1;
	while (l<=r)
	{
		while (nx[l]==-1&&l<=r) a[l]=L,l++,L++;
		if (l>r) return;
		if (nx[l]>r+1) {flag=1;return;}
		int t=nx[l]-l;
		a[l]=L+t-1;
		work(l+1,nx[l]-1,L,L+t-2);
		l=nx[l];L+=t;
	}
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&nx[i]),a[i]=0;
		flag=0;
		work(1,n,1,n);
		if (flag) {puts("-1");continue;}
		for (int i=1;i<=n;i++) printf("%d ",a[i]);
		puts("");
	}
	return 0;
}