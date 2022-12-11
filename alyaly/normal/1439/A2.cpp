//#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
using namespace std;
struct opt{
	int xa,ya,xb,yb,xc,yc;
}ans[4000001];
int T,n,m,a[2001][2001],pans;
int b[2][2];
char c;
void pp(int xa,int ya,int xb,int yb,int xc,int yc){
	a[xa][ya]^=1,a[xb][yb]^=1,a[xc][yc]^=1;
	ans[++pans]=(opt){xa,ya,xb,yb,xc,yc};
}
bool pd(int ns){
	int np=pans;
	for(int i=0;i<=3;i++){
		if(ns&(1<<i)){
			if(i==0)pp(n-1,m-1,n,m-1,n-1,m);
		if(i==1)pp(n-1,m-1,n-1,m,n,m);
		if(i==2)pp(n-1,m-1,n,m-1,n,m);
		if(i==3)pp(n,m,n,m-1,n-1,m);
		}
	}
	if(!a[n-1][m-1]&&!a[n][m-1]&&!a[n-1][m]&&!a[n][m])return 1;
	else{
		for(int i=pans;i>np;i--)pp(ans[i].xa,ans[i].ya,ans[i].xb,ans[i].yb,ans[i].xc,ans[i].yc);
		pans=np;return 0;
	}
}
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>m;pans=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>c,a[i][j]=c-'0';
		for(int i=1;i<n-1;i++){
			for(int j=1;j<m;j++){
				if(a[i][j]&&a[i][j+1])pp(i,j,i,j+1,i+1,j);
				else if(a[i][j])pp(i,j,i+1,j,i+1,j+1);
				else if(a[i][j+1])pp(i+1,j,i,j+1,i+1,j+1);
			}
		}
		for(int j=1;j<m-1;j++){
			if(a[n-1][j]&&a[n][j])pp(n-1,j,n,j,n-1,j+1);
			else if(a[n-1][j])pp(n-1,j,n-1,j+1,n,j+1);
			else if(a[n][j])pp(n,j,n-1,j+1,n,j+1);
		}
		for(int i=0;i<=15;i++){
			if(pd(i))break;
		}
		cout<<pans<<endl;
		for(int i=1;i<=pans;i++)printf("%lld %lld %lld %lld %lld %lld\n",ans[i].xa,ans[i].ya,ans[i].xb,ans[i].yb,ans[i].xc,ans[i].yc);
//		for(int i=1;i<=n;i++,cout<<endl)for(int j=1;j<=m;j++)cout<<a[i][j];
	}
	return 0;
}
/*

*/