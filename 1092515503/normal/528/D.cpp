#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
int S,T,k,BIT[4][200100],lim=1,lg,rev[1<<20],p[200100],cnt;
void add(int x,int y,int z){
	x++;
	x=max(x,1);
	while(x<=T)BIT[y][x]+=z,x+=x&-x;
}
int sum(int x,int y){
	x++;
	x=min(x,T);
	int sum=0;
	while(x>0)sum+=BIT[y][x],x-=x&-x;
	return sum;
}
char s[200100],t[200100];
int tran(char ip){
	if(ip=='A')return 0;
	if(ip=='G')return 1;
	if(ip=='C')return 2;
	if(ip=='T')return 3;
	return 19260817;
}
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
void func(int ip){
	for(int i=0;i<lim;i++)f[i]=g[i]=cp(0,0);
	for(int i=0;i<S;i++)f[i]=cp(s[i]==ip,0);
	for(int i=0;i<T;i++)g[i]=cp(sum(i,ip)>=1,0);
	FFT(f,1),FFT(g,1);
	for(int i=0;i<lim;i++)f[i]=f[i]*g[i];
	FFT(f,-1);
	for(int i=S-1;i<T;i++)p[i]+=(int)(f[i].x/lim+0.5);
}
int main(){
	scanf("%d%d%d",&T,&S,&k);
	scanf("%s%s",t,s),reverse(s,s+S);
	for(int i=0;i<S;i++)s[i]=tran(s[i]);
	for(int i=0;i<T;i++)t[i]=tran(t[i]),add(i-k,t[i],1),add(i+k+1,t[i],-1);
	while(lim<=(S+T))lim<<=1,lg++;
	for(int i=0;i<lim;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	for(int i=0;i<4;i++)func(i);
	for(int i=S-1;i<T;i++)cnt+=(p[i]==S);
	printf("%d\n",cnt);
	return 0;
}