//CF1071D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 1e6+16;
const int M = 1111;
const LL inf = 1e8;
int ab(int x){
	if(x<0)
		return -x;
	return x;
}
int p[9]={2,3,5,7,11,13,17,19,23};
int n,m,a[N],c[N],f[M][M],g[M][M],h[M];
vector<int> v[N],w;
struct node{
	int s;
	int e[9];
	node(){
		s=0;
	}
}d[M];
void dfs(int k,int r){
	//cout<<k<<' '<<d[k].s<<' '<<r<<endl;
	if(!r||d[k].e[r-1]>d[k].e[r])
		if((LL)d[k].s*p[r]<=inf)
			++m,d[m]=d[k],d[m].s*=p[r],d[m].e[r]++,dfs(m,r);
	if(r<8&&d[k].e[r])
		dfs(k,r+1);
}
int main()
{
	int i,j,x,y;
	n=1e6;
	c[1]=1;
	for(i=2;i<=n;i=i+1){
		if(a[i]){
			w.clear();
			for(j=v[i].size();j--;){
				for(x=i,y=1;x%v[i][j]==0;y++)
					x/=v[i][j];
				w.push_back(y);
			}
			sort(w.begin(),w.end());
			c[i]=1;
			x=0;
			for(j=w.size();j--;){
				while(--w[j]){
					c[i]*=p[x];
				}
				x++;
			}
		}
		else{
			c[i]=2;
			for(j=i+i;j<=n;j=j+i)
				a[j]=1,v[j].push_back(i);
		}
	}
	m=1;
	d[1].s=1;
	dfs(1,0);
	for(i=1;i<=m;i=i+1){
		h[i]=1;
		for(x=0;x<9;x=x+1)
			h[i]*=d[i].e[x]+1;
	}
	for(i=1;i<=m;i=i+1)
		for(j=1;j<=m;j=j+1)
			for(x=0;x<9;x=x+1)
				f[i][j]+=ab(d[i].e[x]-d[j].e[x]);
	for(i=0;i<M;i=i+1)
		for(j=0;j<M;j=j+1)
			g[i][j]=N;
	for(i=1;i<=m;i=i+1)
		for(j=1;j<=m;j=j+1)
			g[i][h[j]]=min(g[i][h[j]],f[i][j]);
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&x,&y);
		for(i=1;i<=m;i=i+1){
			if(d[i].s==c[x]){
				x=i;
				break;
			}
		}
		for(i=1;i<=m;i=i+1){
			if(d[i].s==c[y]){
				y=i;
				break;
			}
		}
		//cout<<x<<y<<endl;
		j=N;
		for(i=1;i<M;i=i+1)
			j=min(j,g[x][i]+g[y][i]);
		cout<<j<<endl;
	}
	return 0;
}