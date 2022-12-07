#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const double PI=M_PI;
struct qq
{
	double x,y;
	qq() {};
	qq (double _x,double _y)	{x=_x;y=_y;}
};
qq operator + (qq x,qq y)	{return qq(x.x+y.x, x.y+y.y);}
qq operator - (qq x,qq y)	{return qq(x.x-y.x, x.y-y.y);}
qq operator * (qq x,qq y)	{return qq(x.x*y.x-x.y*y.y, x.x*y.y+x.y*y.x);}
const int N=200005*4;
int n,m,k;
char ss[N],ss1[N];
qq a[N],b[N];
int now;
int bin[N];
void fft (qq *a,int n,int o)
{
	for (int u=0;u<n;u++) bin[u]=(bin[u>>1]>>1)|((u&1)*(n>>1));
	for (int u=1;u<n;u++)
		if (u<bin[u])
			swap(a[u],a[bin[u]]);
	for (int u=1;u<n;u<<=1)
	{
		qq wn=qq(cos(2*PI/(u<<1)),o*sin(2*PI/(u<<1)));
		for (int i=0;i<n;i+=(u<<1))
		{
			qq w=qq(1,0);
			for (int j=0;j<u;j++)
			{
				qq t=w*a[u+i+j];
				a[u+i+j]=a[i+j]-t;
				a[i+j]=a[i+j]+t;
				w=w*wn;
			}
		}
	}
}
int f[N];
void solve (char x)
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	int mx=-1;
	for (int u=0;u<=n;u++)	
	{
		if (ss[u]==x)	mx=u+k;
		if (u<=mx) a[u].x=1;
	}
	mx=n+1;
	for (int u=n;u>=0;u--)
	{
		if (ss[u]==x) mx=u-k;
		if (u>=mx) a[u].x=1;
	}
	for (int u=0;u<=m;u++)
		if (ss1[u]==x)	
			b[u].x=1;
/*	for (int u=0;u<now;u++) printf("%lf ",a[u].x);
	printf("\n");
	for (int u=0;u<now;u++) printf("%lf ",b[u].x);
	printf("\n");*/
	for (int u=0;u<=n/2;u++) swap(a[u],a[n-u]);
	fft(a,now,1);fft(b,now,1);
	for (int u=0;u<now;u++)	a[u]=a[u]*b[u];
	fft(a,now,-1);
/*	for (int u=0;u<now;u++) printf("%d ",(int)(a[u].x/now+0.5));
	printf("\n");
	system("pause");*/
	for (int u=0;u<=n;u++)	f[n-u]=f[n-u]+(int)(a[u].x/now+0.5);
	/*for (int u=0;u<=n;u++)
		printf("%d ",f[u]);*/
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);n--;m--;
	now=1;while (now<=n+m) now<<=1;
	scanf("%s%s",ss,ss1);
	solve('A');solve('T');solve('G');solve('C');
/*	for (int u=0;u<=n;u++)
		printf("%d ",f[u]);*/
	int ans=0;
	for (int u=0;u<=n;u++)
		if (f[u]==m+1)
			ans++;
	printf("%d\n",ans);	
	return 0;
}