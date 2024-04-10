#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>

const int N=125005;
const double pi=acos(-1);

int n,m,L,rev[N*4],f[N][6];
char s[N],t[N];
struct com
{
	double x,y;
	
	com operator + (const com &d) const {return (com){x+d.x,y+d.y};}
	com operator - (const com &d) const {return (com){x-d.x,y-d.y};}
	com operator * (const com &d) const {return (com){x*d.x-y*d.y,x*d.y+y*d.x};}
	com operator / (const double &d) const {return (com){x/d,y/d};}
}a[N*4],b[N*4];

int find(int x,int y)
{
	if (f[x][y]==y) return y;
	else return f[x][y]=find(x,f[x][y]);
}

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
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	int lg=0;
	for (L=1;L<=n*2;L<<=1,lg++);
	for (int i=0;i<L;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	for (int i=1;i<=n-m+1;i++)
		for (int j=0;j<=5;j++)
			f[i][j]=j;
	for (int i=0;i<=5;i++)
		for (int j=0;j<=5;j++)
		{
			if (i==j) continue;
			for (int k=0;k<L;k++) a[k]=b[k]=(com){0,0};
			for (int k=1;k<=n;k++) if (s[k]-'a'==i) a[k]=(com){1,0};
			for (int k=1;k<=m;k++) if (t[k]-'a'==j) b[m-k+1]=(com){1,0};
			FFT(a,1);FFT(b,1);
			for (int k=0;k<L;k++) a[k]=a[k]*b[k];
			FFT(a,-1);
			for (int k=1;k<=n-m+1;k++)
				if ((int)(a[k+m].x+0.5)>0)
				{
					int x=find(k,i),y=find(k,j);
					if (x!=y) f[k][x]=y;
				}
		}
	for (int i=1;i<=n-m+1;i++)
	{
		int ans=0;
		for (int j=0;j<=5;j++) ans+=(f[i][j]!=j);
		printf("%d ",ans);
	}
	return 0;
}