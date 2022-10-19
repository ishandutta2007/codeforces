#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
int n,m,rev[1<<20],lim=1<<20,lg=20,qwq[1<<20],bs[1<<20];
struct cp{
	double x,y;
	cp(double u=0,double v=0){x=u,y=v;}
	friend cp operator +(const cp &u,const cp &v){return cp(u.x+v.x,u.y+v.y);}
	friend cp operator -(const cp &u,const cp &v){return cp(u.x-v.x,u.y-v.y);}
	friend cp operator *(const cp &u,const cp &v){return cp(u.x*v.x-u.y*v.y,u.x*v.y+u.y*v.x);}
}f[1<<20],g[1<<20];
inline void FFT(cp *a,int tp){
	for(register int i=0;i<lim;i++)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(register int md=1;md<lim;md<<=1){
		cp rt=cp(cos(pi/md),tp*sin(pi/md));
		for(register int stp=md<<1,pos=0;pos<lim;pos+=stp){
			cp w=cp(1,0);
			for(register int i=0;i<md;i++,w=w*rt){
				cp x=a[pos+i],y=w*a[pos+md+i];
				a[pos+i]=x+y;
				a[pos+md+i]=x-y;
			}
		}
	}
}
inline void mul(int *a,int *b,int *c){
	for(register int i=0;i<lim;i++)f[i]=cp(a[i],0);
	for(register int i=0;i<lim;i++)g[i]=cp(b[i],0);
	FFT(f,1),FFT(g,1);
	for(register int i=0;i<lim;i++)f[i]=f[i]*g[i];
	FFT(f,-1);
	for(register int i=0;i<lim;i++){
		c[i]=(int)(f[i].x/lim+0.5);
		c[i]=(c[i]>=1);
	}
}
inline void ksm(int x){
	if(x==1){memcpy(qwq,bs,sizeof(bs));return;}
	ksm(x>>1);
	mul(qwq,qwq,qwq);
	if(x&1)mul(qwq,bs,qwq);
}
int main(){
	for(register int i=0;i<lim;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	scanf("%d%d",&n,&m);
	for(register int i=1,x;i<=n;i++)scanf("%d",&x),bs[x]=true;
	ksm(m);
	for(register int i=0;i<lim;i++)if(qwq[i])printf("%d ",i);
	return 0;
}