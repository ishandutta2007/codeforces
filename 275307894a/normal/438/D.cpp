#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,a[100039],z,sx,sum[400039];
long long f[400039];
inline void jianshu(int l,int r,int now){
	if(l==r) {f[now]=a[l];sum[now]=a[l];return;}
	int m=(l+r)>>1;
	jianshu(l,m,now<<1);jianshu(m+1,r,now<<1|1);
	f[now]=f[now<<1]+f[now<<1|1];
	sum[now]=max(sum[now<<1],sum[now<<1|1]);
}
inline long long find(int l,int r,int now){
	if(x<=l&&r<=y)return f[now];
	int m=(l+r)>>1;
	long long fs=0;
	if(x<=m) fs+=find(l,m,now<<1);
	if(y>m) fs+=find(m+1,r,now<<1|1);
	return fs;
}
inline void add(int l,int r,int now){
	if(l==r) {f[now]%=z;sum[now]=f[now];return;}
	int m=(l+r)>>1;
	if(x<=m&&sum[now<<1]>=z) add(l,m,now<<1);
	if(y>m&&sum[now<<1|1]>=z) add(m+1,r,now<<1|1);
	f[now]=f[now<<1]+f[now<<1|1];
	sum[now]=max(sum[now<<1],sum[now<<1|1]);
}
inline void get(int l,int r,int now){
	if(l==r) {f[now]=z,sum[now]=z;return;}
	int m=(l+r)>>1;
	if(x<=m) get(l,m,now<<1);
	else get(m+1,r,now<<1|1);
	f[now]=f[now<<1]+f[now<<1|1];
	sum[now]=max(sum[now<<1],sum[now<<1|1]);
}
int main(){
	register int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	jianshu(1,n,1);
	for(i=1;i<=m;i++){
		scanf("%d",&sx);
		if(sx==1){
			scanf("%d%d",&x,&y);
			printf("%lld\n",find(1,n,1));
		}
		if(sx==2){
			scanf("%d%d%d",&x,&y,&z);
			add(1,n,1);
		}
		if(sx==3){
			scanf("%d%d",&x,&z);
			get(1,n,1);
		}
	}
}//