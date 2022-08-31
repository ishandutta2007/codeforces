//CF 983C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 2222;
const int M = 10;
const int W = 10000;
const int inf = 1e9;
int cmin(int& x,int y){
	if(x>y)
		x=y;
}
int n,a[N],b[N],s,c[N];
int e[W],f[2][W][M],g[W],h[W][M],p[W][M];
int G(int x){
	int t[4]={x/1000,x/100%10,x/10%10,x%10};
	h[x][t[0]]++,h[x][t[1]]++,h[x][t[2]]++,h[x][t[3]]++;
	sort(t,t+4);
	return t[3]*1000+t[2]*100+t[1]*10+t[0]*1;
}
void P(int x){
	int t[4]={x/1000,x/100%10,x/10%10,x%10};
	p[x][t[0]]-=t[0]*1000;
	p[x][t[1]]-=t[1]*100;
	p[x][t[2]]-=t[2]*10;
	p[x][t[3]]-=t[3]*1;
}
int main()
{
	int i,j,k,l,o;
	cin>>n;
	for(i=1;i<=n;i=i+1)
		cin>>a[i]>>b[i];
	for(j=0;j<W;j=j+1)
		g[j]=G(j),e[g[j]]=1;
	for(j=0;j<W;j=j+1)
		if(e[j])
			c[++s]=j;
	for(j=0;j<W;j=j+1)
		for(k=1;k<M;k=k+1)
			p[j][k]=j;
	for(j=0;j<W;j=j+1)
		P(j);
	f[0][0][1]=-inf;
	for(i=1;1;i=i+1){
		o=i&1^1;
		for(l=s;l;l=l-1){
			j=c[l];
			for(k=1;k<M;k=k+1){
				int& x=f[o][j][k];
				if(k>1)
					cmin(f[o][j][k-1],x+1);
				if(k<9)
					cmin(f[o][j][k+1],x+1);
			}
			for(k=9;k;k=k-1){
				int& x=f[o][j][k];
				if(k>1)
					cmin(f[o][j][k-1],x+1);
				if(k<9)
					cmin(f[o][j][k+1],x+1);
			}
			for(k=1;k<M;k=k+1){
				int& x=f[o][j][k];
				if(h[j][k])
					cmin(f[o][g[p[j][k]]][k],x+h[j][k]);
			}
		}
		//cout<<f[o][3000][5]+inf<<endl;
		if(i>n)
			break;
		for(l=s;l;l=l-1){
			j=c[l];
			if(j%10==0)
				cmin(f[o^1][g[j+b[i]]][a[i]],f[o][j][a[i]]+1);
			for(k=0;k<M;k=k+1)
				f[o][j][k]=0;
		}
	}
	l=0;
	for(k=1;k<M;k=k+1)
		cmin(l,f[n&1][0][k]);
	cout<<l+inf<<endl;
	return 0;
}