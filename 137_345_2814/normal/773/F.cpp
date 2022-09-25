#include<cstdio>
#include<cmath>
using namespace std;
#define N 65600
struct comp{double x,y;}a[N],b[N],c[N],fft[N],tp[17][N];
double pi=acos(-1.0);
comp operator +(comp a,comp b){return (comp){a.x+b.x,a.y+b.y};}
comp operator -(comp a,comp b){return (comp){a.x-b.x,a.y-b.y};}
comp operator *(comp a,comp b){return (comp){a.x*b.x-a.y*b.y,a.y*b.x+b.y*a.x};}
comp operator /(comp a,double b){return (comp){a.x/b,a.y/b};}
int rev[N],n,m,p,s[N][2],as;
void dft(int s,comp *a,int t)
{
	for(int i=0;i<s;i++)rev[i]=(rev[i>>1]>>1)+(i&1)*(s>>1),fft[rev[i]]=a[i];
	for(int l=2,lg=1;l<=s;l<<=1,lg++)
	for(int j=0;j<s;j+=l)
	for(int k=j;k<j+(l>>1);k++)
	{
		comp sp=tp[lg][k-j];
		if(t==-1)sp.y*=-1;
		comp tp1=fft[k],tp2=fft[k+(l>>1)]*sp;
		fft[k]=tp1+tp2,fft[k+(l>>1)]=tp1-tp2;
	}
	int inv=t==-1?s:1;
	for(int i=0;i<s;i++)a[i]=fft[i]/inv;
}
void solve(int x)
{
	if(x==0)return;
	if(x==1){s[1][1]=1;as=1;return;}
	int tp=x/2;
	solve(tp);
	int l=1;while(l<=n*2+1)l<<=1;
	for(int i=0;i<l;i++)a[i].x=a[i].y=b[i].x=b[i].y=c[i].x=c[i].y=0;
	for(int i=1;i<=n;i++)a[i].x=s[i][0],b[i].x=s[i][1];
	dft(l,a,1),dft(l,b,1);
	for(int i=0;i<l;i++)c[i]=(a[i]+b[i]+(comp){1,0})*a[i];
	dft(l,c,-1);
	for(int i=1;i<=n;i++)s[i][tp&1]=(s[i][tp&1]+(long long)(c[i].x+0.1))%p;
	for(int i=0;i<l;i++)c[i]=(a[i]+b[i]+(comp){1,0})*b[i];
	dft(l,c,-1);
	for(int i=1;i<=n;i++)s[i][~tp&1]=((long long)(c[i].x+0.1)+s[i][~tp&1])%p;
	if(x&1)for(int i=n;i>1;i--)s[i][1]=(s[i][1]+s[i-1][1]+s[i-1][0])%p;
	if(x&1)s[1][1]=(s[1][1]+1)%p;
	for(int i=1;i<=n;i+=2)as=(as+s[i][1])%p;
}
void init()
{
	for(int i=1;i<17;i++)
	for(int j=0;j<1<<i;j++)
	tp[i][j]=(comp){cos(2*pi/(1<<i)*j),sin(2*pi/(1<<i)*j)};
}
int main()
{
	scanf("%d%d%d",&n,&m,&p);init();solve(m/2);printf("%d\n",as);
}