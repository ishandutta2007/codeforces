#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
const int N=5e6;
int n,m,occ[N],lim=1,lg,rev[N],qwq[N],cnt;
struct cp{
	double x,y;
	cp(double u=0,double v=0){x=u,y=v;}
	friend cp operator +(const cp &u,const cp &v){return cp(u.x+v.x,u.y+v.y);}
	friend cp operator -(const cp &u,const cp &v){return cp(u.x-v.x,u.y-v.y);}
	friend cp operator *(const cp &u,const cp &v){return cp(u.x*v.x-u.y*v.y,u.x*v.y+u.y*v.x);}
}f[N];
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
int main(){
	scanf("%d%d",&n,&m);
	while(lim<m*2)lim<<=1,lg++;
	for(int i=0;i<lim;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	for(int i=0,x;i<n;i++)scanf("%d",&x),occ[x]=true;
//	for(int i=1;i<=m;i++)printf("%d ",occ[i]);puts("");
	for(int i=1;i<=m;i++)f[i]=cp(occ[i],0);
	FFT(f,1);
	for(int i=0;i<lim;i++)f[i]=f[i]*f[i];
	FFT(f,-1);
	for(int i=0;i<lim;i++)qwq[i]=(int)(f[i].x/lim+0.5);
//	for(int i=1;i<=m;i++)printf("%d ",qwq[i]);puts("");
	for(int i=1;i<=m;i++){
		if(!qwq[i])continue;
		cnt++;
		if(!occ[i]){puts("NO");return 0;}
	}
	puts("YES");
	printf("%d\n",n-cnt);
	for(int i=1;i<=m;i++)if(occ[i]&&!qwq[i])printf("%d ",i);
	return 0;
}