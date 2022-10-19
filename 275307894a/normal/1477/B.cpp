#include<cstdio>
#define N 200000
#define l(x) x<<1
#define r(x) x<<1|1
#define I inline
using namespace std;
int T,n,m,k,x[N+5],y[N+5],f[N+5<<2],sum[N+5<<2],flag,now;
char s[N+5],a[N+5];
I void up(int x){f[x]=f[l(x)]+f[r(x)];}
I void build(int l=1,int r=n,int now=1){
	sum[now]=0;if(l==r) return (void)(f[now]=a[l]-'0');
	int m=l+r>>1;build(l,m,l(now));build(m+1,r,r(now));up(now);
}
I void push(int l,int r,int x){
	if(!sum[x]) return;int m=l+r>>1;sum[l(x)]=sum[r(x)]=sum[x];
	f[l(x)]=(sum[x]+1)/2*(m-l+1);f[r(x)]=(sum[x]+1)/2*(r-m);sum[x]=0;
}
I void get(int x,int y,int z,int l=1,int r=n,int now=1){
	if(x<=l&&r<=y) {sum[now]=z;f[now]=(z+1)*(r-l+1)/2;return;}int m=l+r>>1;push(l,r,now);
	(x<=m)&&(get(x,y,z,l,m,l(now)),0);(y>m)&&(get(x,y,z,m+1,r,r(now)),0);up(now);
}
I int find(int x,int y,int l=1,int r=n,int now=1){
	if(x<=l&&r<=y) return f[now];int m=l+r>>1,fs=0;push(l,r,now);
	x<=m&&(fs+=find(x,y,l,m,l(now)));y>m&&(fs+=find(x,y,m+1,r,r(now)));return fs;
}
I int finds(int l=1,int r=n,int now=1){
	push(l,r,now);if(l==r) return s[l]-'0'==f[now];int m=l+r>>1;
	return finds(l,m,l(now))&finds(m+1,r,r(now));
}
int main(){
//	freopen("1.in","r",stdin);
	register int i;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);flag=1;scanf("%s%s",s+1,a+1);build();
		for(i=1;i<=m;i++) scanf("%d%d",&x[i],&y[i]);
		for(i=m;i;i--){
			now=find(x[i],y[i]);
			if(now==(y[i]-x[i]+1)/2&&(y[i]-x[i]+1)%2==0){flag=0;break;}get(x[i],y[i],now<=(y[i]-x[i]+1)/2?-1:1);
		}
		flag&=finds();printf("%s\n",flag?"YES":"NO");
	}
}