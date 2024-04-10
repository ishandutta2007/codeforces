#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define U unsigned int
#define db double
#define lb long db
#define N ((1<<18)+5)
#define M (220+5)
#define K (650+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;
int n,m,k,x,y,z,A[N],F1[N],F2[N],tr[N];ll Ans,Q[N],Po[N],Inv[N],F[N],G[N],H[N],D[N],C[N];
I ll mpow(ll x,int y=mod-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%mod),y>>=1,x=x*x%mod;return Ans;}const int g=3,Invg=mpow(3);
I void Init(int n){for(k=1;k<n;k<<=1);for(int i=0;i<k;i++) tr[i]=(tr[i>>1]>>1)|((i&1)?k/2:0),D[i]=C[i]=0;}
I void NTT(ll *A,int n,int Fl){
	int i,j,h;ll pus,key,now;for(i=0;i<n;i++) i<tr[i]&&(swap(A[i],A[tr[i]]),0);for(i=2;i<=n;i<<=1){
		for(key=mpow(Fl?g:Invg,(mod-1)/i),j=0;j<n;j+=i){
			for(now=1,h=j;h<j+i/2;h++) pus=now*A[h+i/2]%mod,A[h+i/2]=(A[h]-pus+mod)%mod,A[h]=(A[h]+pus)%mod,now=now*key%mod;
		}
	}if(Fl) return;ll Invn=mpow(n);for(i=0;i<n;i++) A[i]=A[i]*Invn%mod;
}
I void Solve(int l,int r){
	if(l==r) return;int i,m=l+r>>1,L1=m-l+1,L2=r-m;Solve(l,m);Solve(m+1,r);Init(L1+L2);
	for(i=l;i<=m;i++) C[i-l]=F[i];for(i=m+1;i<=r;i++) D[i-m-1]=G[i];NTT(C,k,1);NTT(D,k,1);for(i=0;i<k;i++) C[i]=C[i]*D[i]%mod;
	NTT(C,k,0);for(i=0;i<L1+L2;i++) if((i+l+m)&1) H[i+l+m+1>>1]=(H[i+m+l+1>>1]+C[i])%mod;
}
int main(){
//	freopen("1.in","r",stdin); 
	int i,j;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) scanf("%d",&A[i]);for(i=1;i<=m;i++)scanf("%d",&x),F1[x]++,F2[x]++;
	for(Po[0]=Inv[0]=i=1;i<=m;i++) Po[i]=Po[i-1]*2%mod;
	for(i=1;i<=n;i++) F1[i]+=F1[i-1],F[i]=Po[F1[i]];for(i=n;i;i--) F2[i]+=F2[i+1],G[i]=Po[F2[i]];
	for(i=1;i<=n;i++) Q[i]=Q[i-1]+F[i]-1;for(i=n/2+1;i<=n;i++) H[i]=Q[2*i-n-1]%mod;Me(Q,0);for(i=n;i;i--) Q[i]=Q[i+1]+G[i]-1;for(i=1;i<=n/2;i++) H[i]=(H[i]+Q[i*2])%mod;
	/*for(i=1;i<=n;i++) for(j=i+2;j<=n;j+=2) H[j+i>>1]=(H[j+i>>1]+F[i]*G[j])%mod;*/Solve(1,n);
	for(i=1;i<=n;i++) Ans+=(H[i]-min(i-1,n-i))*A[i]%mod;printf("%lld\n",(Ans%mod+mod)%mod*mpow(Po[m]-1)%mod);
}