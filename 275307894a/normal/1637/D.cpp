#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (100+5)
#define M ((1<<16)+5)
#define K (1000+5)
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
int T,n,A[N],B[N],ToT,Ans,Pus,Fl[N*N*2],G[N*N*2];
I void Solve(){
	int i,j;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]);for(i=1;i<=n;i++) scanf("%d",&B[i]);
	Ans=ToT=0;for(i=1;i<=n;i++)Ans+=A[i]*A[i]*(n-2)+B[i]*B[i]*(n-2),ToT+=A[i]+B[i];
	Me(Fl,0);Fl[0]=1;for(i=1;i<=n;i++) {Mc(G,Fl);Me(Fl,0);for(j=0;j<=ToT;j++)Fl[j]=(j>=A[i]?G[j-A[i]]:0)|(j>=B[i]?G[j-B[i]]:0); }
	Pus=2e9;for(i=0;i<=ToT;i++) Fl[i]&&(Pus=min(Pus,Ans+i*i+(ToT-i)*(ToT-i)));printf("%d\n",Pus);
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}