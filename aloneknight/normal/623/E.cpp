#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
const int N=1e5+5,mod=1e9+7;
struct atom
{
    double x,y;
    atom (double _x=0,double _y=0) { x=_x,y=_y;}
    atom operator + (const atom &ch){ return atom(x+ch.x,y+ch.y); }
    atom operator - (const atom &ch){ return atom(x-ch.x,y-ch.y); }
    atom operator * (const atom &ch){ return atom(x*ch.x-y*ch.y,x*ch.y+y*ch.x); }
}A[N],B[N],C[N],D[N],w,w0,tmp,wi[16][65536];;
long long n;
int M,l,k,b,r[N],f[N],g[N],fac[N],inv[N],ans;
void FFT(atom *A,int f)
{
	for(int i=0;i<M;i++) if(r[i]>i) swap(A[r[i]],A[i]);
	int gg=0;
	for(int i=1;i<M;i<<=1)
	{
		w.x=cos(pi/i),w.y=sin(pi/i)*f;
		for(int j=0;j<M;j+=(i<<1))
		{
			for(int k=0;k<i;k++)
			{
				w0=wi[gg][k],w0.y*=f;
				atom x=A[j+k],y=w0*A[i+j+k];
				A[j+k]=x+y,A[i+j+k]=x-y;
			}
		}
		gg++;
	}
	if(f==-1) for(int i=0;i<M;i++) A[i].x/=M;
}
void init()
{
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(int i=2;i<N;i++)fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=2;i<N;i++)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<N;i++)inv[i]=1ll*inv[i]*inv[i-1]%mod;
	for(int i=2,k=0;i<=N;i<<=1,k++)for(int j=0;j<i;j++)wi[k][j]=atom(cos(j*pi/(i/2)),sin(j*pi/(i/2)));
}
void doit(int*a,int*b,int n)
{
	memset(A,0,sizeof(A));memset(B,0,sizeof(B));memset(C,0,sizeof(C));memset(D,0,sizeof(D));
	for(int i=0;i<M;i++){A[i].x=a[i]>>15;B[i].x=a[i]&32767;C[i].x=b[i]>>15;D[i].x=b[i]&32767;}
    FFT(A,1),FFT(B,1),FFT(C,1),FFT(D,1);
    for(int i=0;i<M;i++){tmp=A[i]*D[i]+B[i]*C[i];A[i]=A[i]*C[i];C[i]=B[i]*D[i];B[i]=tmp;}
	FFT(A,-1),FFT(B,-1),FFT(C,-1),memset(a,0,sizeof(a));
	for(int i=0;i<=n;i++)a[i]=((llround(A[i].x)%mod<<30)+(llround(B[i].x)%mod<<15)+llround(C[i].x)%mod)%mod;
}
int c[N];
void work(int*a,int*b,int n,int p)
{
	int t=1;memset(c,0,sizeof(c));
	for(int i=0;i<=n;i++)c[i]=1ll*a[i]*t%mod,t=1ll*t*p%mod;
	doit(c,b,n);
	memcpy(a,c,sizeof c);
}
int Calc(int n,int m){return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;}
int main()
{
	cin>>n>>k;
	if(n>k){puts("0");return 0;}
	for(M=1;M<=k+k;M<<=1,l++);
	for(int i=0;i<M;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	init(),g[0]=1,b=2;
	for(int i=1;i<=k;i++) f[i]=inv[i];
	for(;n;n>>=1,work(f,f,k,b),b=1ll*b*b%mod)if(n&1)work(g,f,k,b);
	for(int i=n;i<=k;i++) (ans+=1ll*g[i]*fac[i]%mod*Calc(k,i)%mod)%=mod;
	printf("%d\n",ans);
}