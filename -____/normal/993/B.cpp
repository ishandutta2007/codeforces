//CF 993B
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
const int N = 111;
int n,m,a[N],b[N],c[N],d[N],e[N][N],f[N],g[N];
int main()
{
	int i,j,x,y;
	cin>>n>>m;
	for(i=1;i<=n;i=i+1)
		cin>>a[i]>>b[i];
	for(i=1;i<=m;i=i+1)
		cin>>c[i]>>d[i];
	y=0;
	for(i=1;i<=n;i=i+1){
		for(j=1;j<=m;j=j+1){
			if(a[i]==c[j]&&b[i]!=d[j])
				x=a[i],e[i][j]=1;
			if(a[i]==d[j]&&b[i]!=c[j])
				x=a[i],e[i][j]=1;
			if(a[i]!=c[j]&&b[i]==d[j])
				x=b[i],e[i][j]=1;
			if(a[i]!=d[j]&&b[i]==c[j])
				x=b[i],e[i][j]=1;
			if(e[i][j]){
				if(!f[i])
					f[i]=x;
				if(f[i]>0&&x!=f[i])
					f[i]=-1;
				if(!g[j])
					g[j]=x;
				if(g[j]>0&&x!=g[j])
					g[j]=-1;
				if(!y)
					y=x;
				if(y>0&&x!=y)
					y=-1;
			}
		}
	}
	if(y>0){
		cout<<y;
		return 0;
	}
	y=0;
	for(i=1;i<=n;i=i+1)
		if(f[i]<0)
			y=-1;
	for(i=1;i<=m;i=i+1)
		if(g[i]<0)
			y=-1;
	cout<<y;
	return 0;
}