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
int cnt[N],n,tt,a[N];
int main()
{
	scanf("%d%d",&n,&tt);cnt[0]++;
	for(int i=1;i<=n;i++){int v;scanf("%d",&v);cnt[a[i]=a[i-1]+(v<tt?1:0)]++;}
	for(int i=0;i<=n;i++)x[i].x=cnt[i],y[i].x=cnt[n-i];
	int nn=1,L=0;while(nn<=(n<<2))nn<<=1,L++;
	for(int i=1;i<nn;i++)r[i]=(r[i>>1]>>1)|((i&1)<<(L-1));
	fft(x,nn,1);fft(y,nn,1);
	for(int i=0;i<nn;i++)x[i]=x[i]*y[i]; 
	fft(x,nn,-1);
	x[n].x-=n+1;x[n].x/=2;
	for(int i=0;i<=n;i++)printf("%I64d ",(long long)(x[n+i].x+0.5));
	return 0;
}