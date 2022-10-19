#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define RI re int
#define ll long long
#define db double
#define lb long db
#define N 200000
#define M 500000
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound 
using namespace std;
int n,m,k,x,y,z,A[N+5],Id,Fl[N+5],Pus,siz[N+5],dp[N+5],We;db W[N+5],ToT,Ans=9e18,Ns,Ps;
struct yyy{int to,w,z;};struct ljb{int head,h[N+5];yyy f[N+5<<1];I void add(int x,int y,int z){f[++head]=(yyy){y,z,h[x]};h[x]=head;}}s;
I int GS(int x,int La){int S=1;yyy tmp;for(RI i=s.h[x];i;i=tmp.z) tmp=s.f[i],!Fl[tmp.to]&&tmp.to^La&&(S+=GS(tmp.to,x));return S;}
I void Make(int x,int La){yyy tmp;siz[x]=1;dp[x]=0;for(RI i=s.h[x];i;i=tmp.z) tmp=s.f[i],!Fl[tmp.to]&&tmp.to^La&&(Make(tmp.to,x),dp[x]=max(dp[x],siz[tmp.to]),siz[x]+=siz[tmp.to]);dp[x]=max(dp[x],Pus-siz[x]);dp[x]<dp[We]&&(We=x);/*printf("%d %d\n",dp[x],We)*/;}
I void GA(int x,int La,ll d){yyy tmp;ToT+=A[x]*pow(d,1.5);/*printf("%.8lf\n",ToT)*/;Ns+=A[x]*pow(d,0.5);for(RI i=s.h[x];i;i=tmp.z) tmp=s.f[i],tmp.to^La&&(GA(tmp.to,x,d+tmp.w),0);}
I void Solve(int x,int La){
	yyy tmp;Pus=GS(x,La);We=0;Make(x,La);x=We;/*printf("%d\n",dp[We]);*/Fl[x]=1;ToT=Ps=0;for(RI i=s.h[x];i;i=tmp.z)tmp=s.f[i],Ns=0,GA(tmp.to,x,tmp.w),W[tmp.to]=Ns,Ps+=Ns;ToT<Ans&&(Ans=ToT,Id=x);
	for(RI i=s.h[x];i;i=tmp.z) tmp=s.f[i],!Fl[tmp.to]&&(W[tmp.to]*2>Ps&&(Solve(tmp.to,x),0));
}
int main(){
//	freopen("1.in","r",stdin);
	RI i;dp[0]=1e9;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]);for(i=1;i<n;i++)scanf("%d%d%d",&x,&y,&z),s.add(x,y,z),s.add(y,x,z);Solve(1,0);printf("%d %.8lf\n",Id,Ans);
}