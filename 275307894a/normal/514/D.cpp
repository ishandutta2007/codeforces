#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,l,r,mid,q[100039],ans,a[6][100039],st[6][100039][20],lg[100039],pus;
inline int find(int x,int y,int z){
	pus=lg[y-x+1]-1;
	return max(st[z][x][pus],st[z][y-(1<<pus)+1][pus]);
}
inline int check(int mid){
	register int i,j;
	for(i=1;i<=n-mid+1;i++){
		ans=0;
		for(j=1;j<=m;j++) ans+=find(i,i+mid-1,j);
		if(ans<=k) return 1;
	}
	return 0;
}
int main(){
//	freopen("1.in","r",stdin);
	register int i,j,h;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++) scanf("%d",&a[j][i]);
	}
	for(i=1;i<=m;i++){
		for(j=n;j;j--){
			st[i][j][0]=a[i][j];
			for(h=1;j+(1<<h)-1<=n;h++)st[i][j][h]=max(st[i][j][h-1],st[i][j+(1<<h-1)][h-1]);
		}
	}
	l=0;r=n+1;
	while(l+1<r){
		mid=(l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	for(i=1;i<=n-l+1;i++){
		ans=0;
		for(j=1;j<=m;j++) ans+=find(i,i+l-1,j);
		if(ans<=k){
			ans=0;
			for(j=1;j<m;j++) ans+=find(i,i+l-1,j),printf("%d ",find(i,i+l-1,j));
			printf("%d",k-ans);
			return 0;
		}
	}
}