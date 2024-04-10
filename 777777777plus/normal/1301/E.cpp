#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e2+5;
const int M = 10;
 
int n,m,Q;
char s[N][N];
int f[N][N][10][10];

struct presum{
	int a[N][N];
	void prepare(char c){
		for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+(s[i][j]==c);
		}
	}
	int sum(int lx,int ly,int rx,int ry){
		return a[rx][ry]-a[lx-1][ry]-a[rx][ly-1]+a[lx-1][ly-1];
	}
}A[4];

int getmx(int lx,int ly,int rx,int ry){
	int k1=log2(rx-lx+1);
	int k2=log2(ry-ly+1);
	int ret=0;
	ret=max(ret,f[lx][ly][k1][k2]);
	ret=max(ret,f[rx-(1<<k1)+1][ly][k1][k2]);
	ret=max(ret,f[lx][ry-(1<<k2)+1][k1][k2]);
	ret=max(ret,f[rx-(1<<k1)+1][ry-(1<<k2)+1][k1][k2]);
	return ret;
}

int main(){
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
	A[0].prepare('R');
	A[1].prepare('G');
	A[2].prepare('Y');
	A[3].prepare('B');
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j){
		int l=0,r=min(min(i,j),min(n-i,m-j));
		while(l!=r){
			int mid=l+r+1>>1;
			bool flag=1;
			flag&=A[0].sum(i-mid+1,j-mid+1,i,j)==mid*mid;
			flag&=A[1].sum(i-mid+1,j+1,i,j+mid)==mid*mid;
			flag&=A[2].sum(i+1,j-mid+1,i+mid,j)==mid*mid;
			flag&=A[3].sum(i+1,j+1,i+mid,j+mid)==mid*mid;
			if(flag)l=mid;
			else r=mid-1;
		}
		f[i][j][0][0]=l;
	}
	for(int k=1;k<M;++k)
	for(int i=1;i<=n;++i)
	for(int j=1;j+(1<<k-1)<=m;++j){
		f[i][j][0][k]=max(f[i][j][0][k-1],f[i][j+(1<<k-1)][0][k-1]);
	}
	for(int k=1;k<M;++k)
	for(int i=1;i+(1<<k-1)<=n;++i)
	for(int j=1;j<=m;++j){
		f[i][j][k][0]=max(f[i][j][k-1][0],f[i+(1<<k-1)][j][k-1][0]);
	}
	for(int k1=1;k1<M;++k1)
	for(int k2=1;k2<M;++k2)
	for(int i=1;i+(1<<k1-1)<=n;++i)
	for(int j=1;j+(1<<k2-1)<=m;++j){
		f[i][j][k1][k2]=max(f[i][j][k1][k2],f[i][j][k1-1][k2-1]);
		f[i][j][k1][k2]=max(f[i][j][k1][k2],f[i+(1<<k1-1)][j][k1-1][k2-1]);
		f[i][j][k1][k2]=max(f[i][j][k1][k2],f[i][j+(1<<k2-1)][k1-1][k2-1]);
		f[i][j][k1][k2]=max(f[i][j][k1][k2],f[i+(1<<k1-1)][j+(1<<k2-1)][k1-1][k2-1]);
	}
	for(int i=1,lx,ly,rx,ry;i<=Q;++i){
		scanf("%d%d%d%d",&lx,&ly,&rx,&ry);
		int l=0,r=min((rx-lx+1)/2,(ry-ly+1)/2);
		while(l!=r){
			int mid=l+r+1>>1;
			if(getmx(lx+mid-1,ly+mid-1,rx-mid,ry-mid)>=mid)l=mid;
			else r=mid-1;
		}
		printf("%d\n",l*l*4);
	}
}