#include<bits/stdc++.h>
using namespace std;
#define int long long
const double pi=acos(-1);
int n,m,cnt[1<<20],lg,lim=1,h[1<<20],rev[1<<20],sum[1<<20];
struct cp{
	double x,y;
	cp(double u=0,double v=0){x=u,y=v;}
	friend cp operator +(const cp &u,const cp &v){return cp(u.x+v.x,u.y+v.y);}
	friend cp operator -(const cp &u,const cp &v){return cp(u.x-v.x,u.y-v.y);}
	friend cp operator *(const cp &u,const cp &v){return cp(u.x*v.x-u.y*v.y,u.x*v.y+u.y*v.x);}
}f[1<<20],g[1<<20];
void FFT(cp *a,int tp){
	for(int i=0;i<lim;i++)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int md=1;md<lim;md<<=1){
		cp rt=cp(cos(pi/md),tp*sin(pi/md));
		for(int stp=md<<1,pos=0;pos<lim;pos+=stp){
			cp w=cp(1,0);
			for(int i=0;i<md;i++,w=w*rt){
				cp x=a[pos+i],y=w*a[pos+md+i];
				a[pos+i]=x+y;
				a[pos+md+i]=x-y;
			}
		}
	}
}
int zero(){
	int pos=0,res=0;
	for(int i=1;i<=n;i++){
		if(sum[i]!=sum[i-1])pos=i;
		res+=i-pos;
	}
	return res;
}
signed main(){
	scanf("%lld%lld",&n,&m);
	while(lim<=n*2+1)lim<<=1,lg++;
	for(int i=0;i<lim;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	cnt[0]++;
	for(int i=1,x;i<=n;i++)scanf("%lld",&x),sum[i]=sum[i-1]+(x<m),cnt[sum[i]]++;
	for(int i=0;i<=n;i++)f[i]=cp(cnt[i],0),g[i]=cp(cnt[n-i],0);
	FFT(f,1),FFT(g,1);
	for(int i=0;i<lim;i++)f[i]=f[i]*g[i];
	FFT(f,-1);
	for(int i=0;i<=n;i++)h[n-i]=(int)(f[i].x/lim+0.5);
	printf("%lld ",zero());
	for(int i=1;i<=n;i++)printf("%lld ",h[i]);
	return 0;
}