#include<cstdio>
#include<algorithm>
#define N 200100
using namespace std;
int p[N],l[N];
int c[N][20],a[N][20];
int f1[1<<19],f2[1<<19];
int cnt=0;
void fix(int *tree,int u,int l,int r,int ql,int qr,int x){
	if(l==ql&&r==qr){
		tree[u]=x;
		return;
	}
	int m=(l+r)/2;
	if(ql>=m){
		fix(tree,u*2+1,m,r,ql,qr,x);
	}
	else if(qr<=m){
		fix(tree,u*2,l,m,ql,qr,x);
	}
	else{
		fix(tree,u*2,l,m,ql,m,x);
		fix(tree,u*2+1,m,r,m,qr,x);
	}
	tree[u]=max(tree[u*2],tree[u*2+1]);
}
int rmq(int *tree,int u,int l,int r,int ql,int qr){
	if(l==ql&&r==qr){
		return tree[u];
	}
	int m=(l+r)/2;
	if(ql>=m){
		return rmq(tree,u*2+1,m,r,ql,qr);
	}
	else if(qr<=m){
		return rmq(tree,u*2,l,m,ql,qr);
	}
	else{
		return max(rmq(tree,u*2,l,m,ql,m),rmq(tree,u*2+1,m,r,m,qr));
	}
}
int bs(int x,int y){
	int s=19,ans=0;
	while(s>=0){
		if(a[a[x][s]][0]<=y){
			ans+=c[x][s];
			x=a[x][s];
		}
		s--;
	}
	return ans+c[x][0];
}
int main(){
	int n,q,x,y,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d%d",&p[i],&l[i]);
	for(i=0;i<n;i++){
		fix(f2,1,0,n,i,i+1,p[i]+l[i]);
	}
	for(i=n-1;i>=0;i--){
		fix(f1,1,0,n,i,i+1,i+1);
		fix(f1,1,0,n,i,i+1,a[i][0]=rmq(f1,1,0,n,i,upper_bound(p,p+n,p[i]+l[i])-p));
		if(a[i][0]==n) c[i][0]=0;
		else c[i][0]=p[a[i][0]]-rmq(f2,1,0,n,i,a[i][0]);
	}
	a[n][0]=n;
	c[n][0]=0;
	for(j=1;j<20;j++){
		for(i=0;i<=n;i++){
			a[i][j]=a[a[i][j-1]][j-1];
			c[i][j]=c[a[i][j-1]][j-1]+c[i][j-1];
		}
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&x,&y);
		x--;
		y--;
		if(a[x][0]>y) printf("0\n");
		else printf("%d\n",bs(x,y));
	}
	return 0;
}