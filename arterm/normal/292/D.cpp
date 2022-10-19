#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>

#define long long long
#define M 505
#define N 10100

using namespace std;

int d[2][N][M],a[N],b[N],n,m;

inline void copy(int t1, int n1, int t2, int n2){
	for (int i=1; i<=n; ++i)
	d[t2][n2][i]=d[t1][n1][i];
}

inline void ini(int t, int n){
	for (int i=0; i<M; ++i)
	d[t][n][i]=i;
}

inline int get(int t, int n, int x){
	int z,y=x;
	while (x!=d[t][n][x])
	x=d[t][n][x];
	while (y!=x){
		z=y;
		y=d[t][n][y];
		d[t][n][z]=x;
	}
	return x;
}

inline void uni(int t, int n, int x, int y){
	x=get(t,n,x);
	y=get(t,n,y);
	if (rand()&1)
	swap(x,y);
	d[t][n][x]=y;
}

void read(void){
	scanf("%d%d",&n,&m);
	for (int i=1; i<=m; ++i)
	scanf("%d%d",a+i,b+i);
}

void make(void){
	ini(0,0);
	for (int i=1; i<=m; ++i){
		copy(0,i-1,0,i);
		uni(0,i,a[i],b[i]);
	}
	ini(1,m+1);
	for (int i=m; i>=1; --i){
		copy(1,i+1,1,i);
		uni(1,i,a[i],b[i]);
	}
}

inline void que(int l, int r){
	l--,r++;
	copy(0,l,1,0);
	for (int i=1; i<=n; ++i)
	uni(1,0,i,d[1][r][i]);
	int ans=0;
	for (int i=1; i<=n; ++i)
	if (d[1][0][i]==i)
	ans++;
	printf("%d\n",ans);
}

void kill(void){
	int k;
	scanf("%d",&k);
	while (k--){
		int l,r;
		scanf("%d%d",&l,&r);
		que(l,r);
	}
}

int main()
{
	read();
	make();
	kill();
	return 0;
}