#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=acos(-1);
const int LG=18;
const int lim=1<<LG;
int rev[lim];
struct cp{
	double x,y;
	cp(double u=0,double v=0){x=u,y=v;}
	friend cp operator+(const cp u,const cp v){return cp(u.x+v.x,u.y+v.y);}
	friend cp operator-(const cp u,const cp v){return cp(u.x-v.x,u.y-v.y);}
	friend cp operator*(const cp u,const cp v){return cp(u.x*v.x-u.y*v.y,u.x*v.y+u.y*v.x);}
}f[3][lim],g[3][lim],h[5][lim];
void FFT(cp*a,int tp){
//	for(int i=0;i<10;i++)printf("(%lf,%lf)",a[i].x,a[i].y);puts("");
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
	if(tp==-1)for(int i=0;i<lim;i++)a[i].x/=lim;
//	for(int i=0;i<10;i++)printf("(%lf,%lf)",a[i].x,a[i].y);puts("");
}
int n,m,q,a[lim],b[lim];
ll s[5][lim];
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),f[0][a[i]].x+=1;
	for(int i=1;i<=m;i++)scanf("%d",&b[i]),g[0][b[i]].x+=1;
	for(int i=1;i<n;i++)
		f[1][min(a[i],a[i+1])].x+=1,f[2][max(a[i],a[i+1])].x+=1;
	for(int i=1;i<m;i++)
		g[1][min(b[i],b[i+1])].x+=1,g[2][max(b[i],b[i+1])].x+=1;
	for(int i=0;i<lim;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(LG-1));
	for(int i=0;i<3;i++)FFT(f[i],1),FFT(g[i],1);
	for(int i=0;i<lim;i++)
		h[0][i]=f[0][i]*g[0][i],
		h[1][i]=f[0][i]*g[1][i]+f[1][i]*g[0][i],
		h[2][i]=f[1][i]*g[1][i],
		h[3][i]=f[0][i]*g[2][i]+f[2][i]*g[0][i],
		h[4][i]=f[2][i]*g[2][i];
	for(int i=0;i<5;i++)FFT(h[i],-1);
//	for(int i=0;i<5;i++,puts(""))for(int j=0;j<10;j++)printf("%d ",(ll)(h[i][j].x+0.5));
	for(int i=lim-1;i>=0;i--)
		s[0][i]=s[0][i+1]+(h[0][i].x+0.5),
		s[1][i]=s[1][i+1]+(h[1][i].x+0.5),
		s[2][i]=s[2][i+1]+(h[2][i].x+0.5);
	for(int i=1;i<lim;i++)
		s[3][i]=s[3][i-1]+(h[3][i].x+0.5),
		s[4][i]=s[4][i-1]+(h[4][i].x+0.5);
//	for(int i=0;i<5;i++,puts(""))for(int j=0;j<10;j++)printf("%d ",s[i][j]);
	for(int i=1,x;i<=q;i++){
		scanf("%d",&x);
		printf("%lld\n",(s[0][x]<<1)-1ll*n*m-s[1][x]+s[2][x]+s[3][x-1]-s[4][x-1]);
	}
	return 0;
}