#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (500000+5)
#define M (100+5)
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
int n,m,k,x,y,z,dp[N],Nh,A[N],P[N];ll Q[N],Ns[N];
namespace Tree{
	int F1[N],F2[N];I void I1(int x,int w){while(x<=Nh) F1[x]=max(F1[x],w),x+=x&-x;}I void I2(int x,int w){while(x<=Nh) F2[x]=max(F2[x],w),x+=x&-x;}
	I int Q1(int x){int Ans=-1e9;while(x) Ans=max(Ans,F1[x]),x-=x&-x;return Ans;}I int Q2(int x){int Ans=-1e9;while(x) Ans=max(Ans,F2[x]),x-=x&-x;return Ans;}
}
I void Solve(){
	int i,j;scanf("%d",&n);Q[0]=0;for(i=1;i<=n;i++) dp[i]=-1e9,scanf("%d",&A[i]),Ns[i]=Q[i]=Q[i-1]+A[i];Nh=n;Ns[++Nh]=0;sort(Ns+1,Ns+Nh+1);
	Nh=unique(Ns+1,Ns+Nh+1)-Ns-1;for(i=1;i<=Nh;i++) P[i]=Tree::F1[i]=Tree::F2[i]=-1e9;
	for(i=0;i<=n;i++) Q[i]=LB(Ns+1,Ns+Nh+1,Q[i])-Ns;Tree::I1(Q[0],0);Tree::I2(Nh-Q[0]+1,0);P[Q[0]]=0;
	for(i=1;i<=n;i++) x=Tree::Q1(Q[i]-1)+i,y=Tree::Q2(Nh-(Q[i]+1)+1)-i,z=P[Q[i]],dp[i]=max(max(x,y),z),P[Q[i]]=max(P[Q[i]],dp[i]),Tree::I1(Q[i],dp[i]-i),Tree::I2(Nh-Q[i]+1,dp[i]+i);
	printf("%d\n",dp[n]);
}
int main(){
//	freopen("1.in","r",stdin);
	int T;scanf("%d",&T);while(T--) Solve();
}