#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
int lim=1,lg,rev[1<<20],dsu[125010][6],ans[125010],S,T;
char s[125010],t[125010];
int ask(int x,int y){
	return dsu[x][y]==y?y:dsu[x][y]=ask(x,dsu[x][y]);
}
bool merge(int x,int y,int z){
	y=ask(x,y),z=ask(x,z);
	if(y==z)return false;
	dsu[x][y]=dsu[x][z];
	return true;
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
void match(int x,int y){
	for(int i=0;i<lim;i++)f[i]=g[i]=cp(0,0);
	for(int i=0;i<S;i++)f[i]=cp(s[i]-'a'==x,0);
	for(int i=0;i<T;i++)g[i]=cp(t[i]-'a'==y,0);
	FFT(f,1),FFT(g,1);
	for(int i=0;i<lim;i++)f[i]=f[i]*g[i];
	FFT(f,-1);
	for(int i=S-1;i<T;i++)if((int)(f[i].x/lim+0.5)>=1)ans[i]+=merge(i,x,y);
}
int main(){
	scanf("%s%s",t,s),T=strlen(t),S=strlen(s),reverse(s,s+S);
	while(lim<=(S+T))lim<<=1,lg++;
	for(int i=0;i<lim;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	for(int i=S-1;i<T;i++)for(int j=0;j<6;j++)dsu[i][j]=j;
	for(int i=0;i<6;i++)for(int j=0;j<6;j++)match(i,j);
	for(int i=S-1;i<T;i++)printf("%d ",ans[i]);
	return 0;
}