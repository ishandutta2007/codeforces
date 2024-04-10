#include<cstdio>
#define l(x) f[x].l
#define r(x) f[x].r
using namespace std;
int n,m,k,y,x,tot,pus,root,cnt,sx,a[100039];
long long z;
struct tree{int l,r,siz;long long f;}f[10000039];
inline void get(long long x,int y,long long l,long long r,int &now){
	if(!now) now=++cnt;
	if(l==r) {f[now].f+=x*y;f[now].siz+=y;return ;}
	double m=(l+r)/2;
	if(x<=m) get(x,y,l,m,l(now));
	else get(x,y,m+1,r,r(now));
	f[now].f=f[l(now)].f+f[r(now)].f;
	f[now].siz=f[l(now)].siz+f[r(now)].siz;
}
inline double find(long long x,long long l,long long r,int now){
	long long siz=0;long long fs=0;
	while(l!=r){
		double m=(l+r)/2;
		if(x>=m*(siz+f[l(now)].siz)-fs-f[l(now)].f)l=m+1,fs+=f[l(now)].f,siz+=f[l(now)].siz,now=r(now);
		else r=m,now=l(now);
	}
	return l+(x-(l*(siz+f[l(now)].siz)-fs-f[l(now)].f))*1.0/siz;
}
inline void read(int &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9') x=(x<<3)+(x<<1)+(s^48),s=getchar();
}
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	read(n);read(m);
	for(i=1;i<=n;i++) read(a[i]),get(a[i],1,0,1e13,root);
	for(i=1;i<=m;i++){
		read(sx);
		if(sx==1) read(x),read(y),get(a[x],-1,0,1e13,root),a[x]=y,get(a[x],1,0,1e13,root);
		else scanf("%lld",&z),printf("%.5lf\n",find(z,0,1e13,root));
	}
}