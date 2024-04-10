#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
const int maxn = 1005;
int l[maxn*maxn];
int r[maxn*maxn];
int u[maxn*maxn];
int d[maxn*maxn];
int a[maxn][maxn];
int val[maxn*maxn];
int n,m,q,tot;
int main() 
{
	#ifndef ONLINE_JUDGE
		freopen("routine.in","r",stdin);
		freopen("routine.out","w",stdout);
	#endif
	scanf("%d %d %d",&n,&m,&q);
	for (int i=0;i<=n+1;i++)
	for (int j=0;j<=m+1;j++)
		a[i][j]=++tot; 
	for (int i=0;i<=n+1;i++)
	for (int j=0;j<=m;j++)
		r[a[i][j]]=a[i][j+1],
		l[a[i][j+1]]=a[i][j];
	for (int i=0;i<=n;i++)
	for (int j=0;j<=m+1;j++)
		d[a[i][j]]=a[i+1][j],
		u[a[i+1][j]]=a[i][j];
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		scanf("%d",&val[a[i][j]]);
		
	for (int i=1;i<=q;i++) {
		int x1,y1,x2,y2,h,w;
		scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&h,&w);
		int w1=a[0][0],w2=a[0][0],x,y;
		for (int j=1;j<=x1;j++) w1=d[w1];
		for (int j=1;j<=x2;j++) w2=d[w2];
		for (int j=1;j<=y1;j++) w1=r[w1];
		for (int j=1;j<=y2;j++) w2=r[w2];
		
		x=w1;y=w2;
		for (int i=1;i<=h;i++,x=d[x],y=d[y])
			swap(r[l[x]],r[l[y]]),swap(l[x],l[y]);
		x=w1;y=w2;
		for (int i=1;i<=w;i++,x=r[x],y=r[y])
			swap(d[u[x]],d[u[y]]),swap(u[x],u[y]);
		x=w1;y=w2;
		for (int j=1;j<h;j++) x=d[x],y=d[y];
		for (int i=1;i<=w;i++,x=r[x],y=r[y])
			swap(u[d[x]],u[d[y]]),swap(d[x],d[y]);
		x=w1;y=w2;
		for (int j=1;j<w;j++) x=r[x],y=r[y];
		for (int i=1;i<=h;i++,x=d[x],y=d[y])
			swap(l[r[x]],l[r[y]]),swap(r[x],r[y]);
	}
	for (int i=1;i<=n;i++) {
		for (int pos=r[a[i][0]],j=1;j<=m;j++) 
			printf("%d ",val[pos]),pos=r[pos];
		puts("");
	}
	return 0;
}