#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>

typedef long long LL;

const int N=200005;
const double pi=acos(-1);

int n,m,L,rev[N*4];
struct com
{
    double x,y;

    com operator + (const com &d) const {return (com){x+d.x,y+d.y};}
    com operator - (const com &d) const {return (com){x-d.x,y-d.y};}
    com operator * (const com &d) const {return (com){x*d.x-y*d.y,x*d.y+y*d.x};}
    com operator / (const double &d) const {return (com){x/d,y/d};}
}a[N*4],b[N*4];

void FFT(com *a,int f)
{
    for (int i=0;i<L;i++) if (i<rev[i]) std::swap(a[i],a[rev[i]]);
    for (int i=1;i<L;i<<=1)
    {
        com wn=(com){cos(pi/i),f*sin(pi/i)};
        for (int j=0;j<L;j+=(i<<1))
        {
            com w=(com){1,0};
            for (int k=0;k<i;k++)
            {
                com u=a[j+k],v=a[j+k+i]*w;
                a[j+k]=u+v;a[j+k+i]=u-v;
                w=w*wn;
            }
        }
    }
    if (f==-1) for (int i=0;i<L;i++) a[i]=a[i]/L;
}

int main()
{
	scanf("%d%d",&n,&m);
	int s=0;a[s].x+=1;LL ans=0;
	for (int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		if (x<m) s++;
		ans+=(LL)a[s].x;a[s].x+=1;
	}
	for (int i=0;i<=n;i++) b[i]=a[n-i];
	int lg=0;
	for (L=1;L<=n*2;L<<=1,lg++);
	for (int i=0;i<L;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	FFT(a,1);FFT(b,1);
	for (int i=0;i<L;i++) a[i]=a[i]*b[i];
	FFT(a,-1);
	printf("%lld ",ans);
	for (int i=1;i<=n;i++) printf("%lld ",(LL)(a[i+n].x+0.5));
	return 0;
}