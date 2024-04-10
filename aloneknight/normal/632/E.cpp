#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
const int N=2000010;
struct atom{double x,y;atom(double _x=0,double _y=0){x=_x;y=_y;}}x[N],y[N];
atom operator+(atom a,atom b){return atom(a.x+b.x,a.y+b.y);}
atom operator-(atom a,atom b){return atom(a.x-b.x,a.y-b.y);}
atom operator*(atom a,atom b){return atom(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
int r[N];
void fft(atom *a,int n,int f)
{
	for(int i=0;i<n;i++)if(i<r[i])swap(a[i],a[r[i]]);
	for(int i=1;i<n;i<<=1)
	{
		atom wn=atom(cos(pi/i),sin(pi/i)*f);
		for(int j=0;j<n;j+=(i<<1))
		{
			atom w=atom(1,0);
			for(int k=0;k<i;k++){atom u=a[j+k],v=a[i+j+k]*w;a[j+k]=u+v;a[i+j+k]=u-v;w=w*wn;}
		}
	}
	if(f==-1)for(int i=0;i<n;i++)a[i].x/=(double)n;
} 
void init(int len)
{
	int j=0;while((1<<j)<len)j++;j--;
	for(int i=0;i<len;i++)r[i]=r[i>>1]>>1|((i&1)<<j);
}
void FFT(int *a,int *b,int n,int *c)
{
	int len=n<<1;init(len);
	for(int i=0;i<len;i++)x[i].x=x[i].y=y[i].x=y[i].y=0;
	for(int i=0;i<n;i++)x[i].x=a[i],y[i].x=b[i];
	fft(x,len,1);fft(y,len,1);
	for(int i=0;i<len;i++)x[i]=x[i]*y[i];
	fft(x,len,-1);
	for(int i=0;i<len;i++)if((int)(x[i].x+0.5))c[i]=1;else c[i]=0;
}
int f[N],g[N]; 
void pw(int *f,int len,int k,int *g)
{
	g[0]=1;
	while(k)
	{
		if(k&1)FFT(g,f,len,g);
		FFT(f,f,len,f);
		k>>=1;len<<=1;
	}
}
int main()
{
	int n,k,a;scanf("%d%d",&n,&k);
	while(n--){scanf("%d",&a);f[a]=1;}
	pw(f,1024,k,g);
	for(int i=1;i<=1000000;i++)if(g[i])printf("%d ",i);
	return 0;
}