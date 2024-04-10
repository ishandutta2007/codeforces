//Code by John Alfnov
//Please orz Qingyu
//Hydd txdy
#include<bits/stdc++.h>
using namespace std;
int f[100005],g[100005];
int a[100005],b[2005];
int zz[100005],yy[100005];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=m;++i)scanf("%d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	a[0]=-1e9,a[n+1]=1e9;
	for(int i=1;i<=n;++i){
		if(a[i]==a[i-1]+1)zz[i]=zz[i-1];
		else zz[i]=i;
	}
	for(int i=n;i>=1;--i){
		if(a[i]==a[i+1]-1)yy[i]=yy[i+1];
		else yy[i]=i;
	}
	int wz=0;
	for(int i=1;i<=n;++i){
		g[i]=max(g[i],g[i-1]);
		f[i]=max(f[i],g[zz[i]-1]);
		while(wz<=m&&b[wz]<=a[i])++wz;
		for(int j=wz-1;j>=1;--j)if(i+b[j]-a[i]>=1){
			int zuo=zz[i+b[j]-a[i]];
			f[i]=max(f[i],g[zuo-1]+(wz-j));
		}
		g[i]=max(g[i],f[i]);
		for(int j=wz;j<=m;++j)if(i+b[j]-a[i]<=n){
			int you=yy[i+b[j]-a[i]];
			g[you]=max(g[you],f[i]+(j-wz+1));
		}
	}
	cout<<g[n]<<endl;
	return 0;
}