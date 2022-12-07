#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
typedef long long LL;
const int N=5000005;
const double pi=acos(-1);
struct qq
{
	double x,y;
	qq() {}
	qq(double _x,double _y) {x=_x;y=_y;}	
}A[N],B[N];
qq operator + (qq x,qq y)	{return qq(x.x+y.x,x.y+y.y);}
qq operator - (qq x,qq y)	{return qq(x.x-y.x,x.y-y.y);}
qq operator * (qq x,qq y)	{return qq(x.x*y.x-x.y*y.y,x.x*y.y+x.y*y.x);}
char ss[N];
int n;
int a[N],b[N],d[N];
int bin[N];
void FFT (qq *a,int n,int o)
{
	for (int u=0;u<n;u++) bin[u]=(bin[u>>1]>>1)|((u&1)*(n>>1));
	for (int u=0;u<n;u++)	if (u<bin[u])	swap(a[u],a[bin[u]]);
	for (int u=1;u<n;u<<=1)
	{
		qq w,wn=qq(cos(2*pi/(u<<1)),o*sin(2*pi/(u<<1))),t;
		for (int i=0;i<n;i+=(u<<1))
		{
			w=qq(1,0);
			for (int j=0;j<u;j++)
			{
				t=w*a[u+i+j];
				a[u+i+j]=a[i+j]-t;
				a[i+j]=a[i+j]+t;
				w=w*wn;
			}
		}
	}
}
bool ok[N];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int u=1;u<=2*n;u++) d[u]=0;
		scanf("%s",ss);
		for (int u=0;u<n;u++)
		{
			if (ss[u]=='V') a[u]=1;
			if (ss[u]=='K') a[u]=-1;
			if (ss[u]=='?') a[u]=0;
			b[n-u-1]=a[u];
		}
		int nn=1;while (nn<=n+n)nn<<=1;
		for (int u=0;u<n;u++) A[u]=qq(a[u]*a[u]*a[u],0);
		for (int u=0;u<n;u++) B[u]=qq(b[u],0);
		for (int u=n;u<nn;u++) A[u]=B[u]=qq(0,0);
	//	for (int u=0;u<=nn;u++) printf("%lf ",A[u].x);printf("\n");
	//	for (int u=0;u<=nn;u++) printf("%lf ",B[u].x);printf("\n");
		FFT(A,nn,1);FFT(B,nn,1);
		for (int u=0;u<nn;u++) A[u]=A[u]*B[u];
		FFT(A,nn,-1);
	//	for (int u=0;u<=nn;u++) printf("%lf ",A[u].x/nn);printf("\n");
		for (int u=0;u<=nn;u++) d[u]=d[u]+(int)(A[u].x/nn+0.5);
		
		for (int u=0;u<n;u++) A[u]=qq(a[u],0);
		for (int u=0;u<n;u++) B[u]=qq(b[u]*b[u]*b[u],0);
		for (int u=n;u<=nn;u++) A[u]=B[u]=qq(0,0);
		FFT(A,nn,1);FFT(B,nn,1);
		for (int u=0;u<nn;u++) A[u]=A[u]*B[u];
		FFT(A,nn,-1);
		for (int u=0;u<nn;u++) d[u]=d[u]+(int)(A[u].x/nn+0.5);
		
		for (int u=0;u<n;u++) A[u]=qq(2*a[u]*a[u],0);
		for (int u=0;u<n;u++) B[u]=qq(b[u]*b[u],0);
		for (int u=n;u<=nn;u++) A[u]=B[u]=qq(0,0);
		FFT(A,nn,1);FFT(B,nn,1);
		for (int u=0;u<=nn;u++) A[u]=A[u]*B[u];
		FFT(A,nn,-1);
		for (int u=0;u<nn;u++) d[u]=d[u]-(int)(A[u].x/nn+0.5);
		/*for (int u=0;u<n;u++) printf("%d ",a[u]);printf("\n");
		for (int u=0;u<n;u++) printf("%d ",b[u]);printf("\n");
		for (int u=0;u<nn;u++) printf("%d ",d[u]);printf("\n");*/
		for (int u=1;u<=n;u++) ok[u]=(d[n+u-1]==0);
		for (int u=1;u<=n;u++)
		for (int i=u;i<=n;i+=u)
		ok[u]&=ok[i];
		int ans=0;
		for (int u=1;u<=n;u++)	if (ok[u])	ans++;
		printf("%d\n",ans);
		for (int u=1;u<=n;u++)	if (ok[u])	printf("%d ",u);
		printf("\n");
	}
	return 0;
}