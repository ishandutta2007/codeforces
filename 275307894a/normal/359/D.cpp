#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,f[1200039],st[300039][20],lg[300039],l,r,mid,a[300039],s[300039],ans,sh,pus;
inline void jianshu(int l,int r,int now){
	if(l==r){f[now]=a[l];return;}
	int m=l+r>>1;
	jianshu(l,m,now<<1);jianshu(m+1,r,now<<1|1);
	f[now]=__gcd(f[now<<1],f[now<<1|1]);
}
inline int find(int x,int y,int z,int l,int r,int now){
	if(x<=l&&r<=y)return (f[now]%z)?0:1;
	int fs=1,m=l+r>>1;
	if(x<=m) fs&=find(x,y,z,l,m,now<<1);
	if(y>m) fs&=find(x,y,z,m+1,r,now<<1|1);
	return fs;
}
inline int finds(int x,int y){
	pus=lg[y-x+1];
	return min(st[x][pus],st[y-(1<<pus)+1][pus]);
}
inline int check(int mid){
	register int i;
	for(i=1;i<=n-mid;i++){
		if(find(i,i+mid,finds(i,i+mid),1,n,1)) return 1;
	}
	return 0;
}
int main(){
	//freopen("1.in","r",stdin);
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	for(i=1;i<=n;i++) lg[i]--;
	for(i=n;i;i--){
		st[i][0]=a[i];
		for(j=1;i+(1<<j)-1<=n;j++)st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
	}
	jianshu(1,n,1);
	l=0;r=n+1;
	while(l+1<r){
		mid=(l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	for(i=1;i<=n-l;i++){
		if(find(i,i+l,finds(i,i+l),1,n,1)) s[++sh]=i;
	}
	printf("%d %d\n",sh,l);
	for(i=1;i<=sh;i++) printf("%d ",s[i]);
}