#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
int T,n,lim=1,lg,p[1<<20],rev[1<<20],cnt;
char s[500100];
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
bool ok[1<<20];
int main(){
	scanf("%d",&T);

	while(T--){
		scanf("%d%s",&n,s),cnt=0;
		lim=1,lg=0;
		while(lim<=2*n)lim<<=1,lg++;
		for(int i=0;i<lim;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
		for(int i=0;i<lim;i++)f[i]=g[i]=cp(0,0);
		for(int i=0;i<n;i++)f[i]=g[n-i-1]=cp(s[i]=='V'||s[i]=='?',0);
		FFT(f,1),FFT(g,1);
		for(int i=0;i<lim;i++)f[i]=f[i]*g[i];
		FFT(f,-1);
		for(int i=1;i<=n;i++)p[i]=(int)(f[n+i-1].x/lim+0.5);
		
		for(int i=0;i<lim;i++)f[i]=g[i]=cp(0,0);
		for(int i=0;i<n;i++)f[i]=g[n-i-1]=cp(s[i]=='K'||s[i]=='?',0);
		FFT(f,1),FFT(g,1);
		for(int i=0;i<lim;i++)f[i]=f[i]*g[i];
		FFT(f,-1);
		for(int i=1;i<=n;i++)p[i]+=(int)(f[n+i-1].x/lim+0.5);
		
		for(int i=0;i<lim;i++)f[i]=g[i]=cp(0,0);
		for(int i=0;i<n;i++)f[i]=g[n-i-1]=cp(s[i]=='?',0);
		FFT(f,1),FFT(g,1);
		for(int i=0;i<lim;i++)f[i]=f[i]*g[i];
		FFT(f,-1);
		for(int i=1;i<=n;i++)p[i]-=(int)(f[n+i-1].x/lim+0.5);
		
//		for(int i=1;i<=n;i++)printf("%d ",p[i]);puts("");
		
		for(int i=1;i<=n;i++)ok[i]=(p[i]==n-i);
		for(int i=1;i<=n;i++)for(int j=i;j<=n;j+=i)ok[i]&=ok[j];
		for(int i=1;i<=n;i++)cnt+=ok[i];
		printf("%d\n",cnt);
		for(int i=1;i<=n;i++)if(ok[i])printf("%d ",i);puts("");
	}
	return 0;
}