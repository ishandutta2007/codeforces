#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,x,y,a[500039],sum[2000039],f[2000039],z,sx,ans;
inline void jianshu(int l,int r,int now){
	if(l==r) {f[now]=a[l];return;}
	int m=(l+r)>>1;
	jianshu(l,m,now<<1);
	jianshu(m+1,r,now<<1|1);
	f[now]=__gcd(f[now<<1],f[now<<1|1]);
}
inline void find(int l,int r,int now){
	if(ans>1) return;
	if(l==r) {ans++;return;}
	int m=(l+r)>>1;
	if(x<=m&&f[now<<1]%z) find(l,m,now<<1);
	if(y>m&&f[now<<1|1]%z) find(m+1,r,now<<1|1);
	return;
}
inline void get(int l,int r,int now){
	if(l==r){f[now]=z;return;}
	int m=(l+r)>>1;
	if(x<=m) get(l,m,now<<1);
	else get(m+1,r,now<<1|1);
	f[now]=__gcd(f[now<<1],f[now<<1|1]);
}
int main(){
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	jianshu(1,n,1);
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d",&sx);
		if(sx==1){
			ans=0;
			scanf("%d%d%d",&x,&y,&z);
			find(1,n,1);
			if(ans<=1) printf("YES\n");
			else printf("NO\n");
		}
		else{
			scanf("%d%d",&x,&z);
			get(1,n,1);
		}
	}
}