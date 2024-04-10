#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 666;
int n,m,a[N],b[N],d[N][N],f[N][N];
int e[N],c[N],s[N];
int solve(int x,int y){
	int i,j,k,z=d[x][y],o,u,r;
	memset(e,0,sizeof(e));
	memset(c,0,sizeof(c));
	memset(s,0,sizeof(s));
	for(i=1;i<=n;i=i+1)
		if(d[x][i]+d[y][i]==z)
			e[d[x][i]]++;
	for(i=0;i<=z;i=i+1)
		if(e[i]!=1)
			return 0;
	for(i=1;i<=n;i=i+1){
		o=d[x][i]-d[y][i];
		if((o-z)&1)
			return 0;
		c[i]=o;
	}
	for(k=1;k<=m;k=k+1){
		i=a[k],j=b[k];
		o=d[x][i]+d[y][i];
		u=d[x][j]+d[y][j];
		if(o==z&&u==z)
			continue;
		if(c[i]!=c[j])
			continue;
		if(abs(o-u)==2){
			if(o>u)
				s[i]++;
			else
				s[j]++;
		}
	}
	r=1;
	for(i=1;i<=n;i=i+1){
		o=d[x][i]+d[y][i];
		if(o!=z)
			r=(LL)r*s[i]%998244353;
	}
	return r;
}
int main(){
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i=i+1){
		for(j=1;j<=n;j=j+1)
			d[i][j]=N;
		d[i][i]=0;
	}
	for(i=1;i<=m;i=i+1){
		scanf("%d%d",a+i,b+i);
		d[a[i]][b[i]]=1;
		d[b[i]][a[i]]=1;
	}
	for(k=1;k<=n;k=k+1)
		for(i=1;i<=n;i=i+1)
			for(j=1;j<=n;j=j+1)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	for(i=1;i<=n;i=i+1)
		for(j=i;j<=n;j=j+1)
			f[i][j]=solve(i,j);
	for(i=1;i<=n;i=i+1)
		for(j=1;j<i;j=j+1)
			f[i][j]=f[j][i];
	for(i=1;i<=n;i=i+1){
		for(j=1;j<=n;j=j+1)
			printf("%d ",f[i][j]);
		printf("\n");
	}
	return 0;
}