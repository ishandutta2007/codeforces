#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (1000000+5)
#define M (6000000+5)
#define K (1500+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-5)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((k+1)*(x)+(y))
#define R(n) (1ll*rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;const int B1=3,M1=998244353;
int n,m,k,x,y,z,A[N],B[N];ll Po[N],Inv[N];
I ll mpow(ll x,int y=M1-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%M1),y>>=1,x=x*x%M1;return Ans;}
namespace BT{
	ll F1[N],F2[N];I void I1(int x,ll y){while(x<=n) F1[x]+=y,x+=x&-x;}I void I2(int x,ll y){while(x<=n) F2[x]+=y,x+=x&-x;}
	I ll Q1(int x){ll Ans=0;while(x) Ans+=F1[x],x-=x&-x;return Ans;}I ll Q2(int x){ll Ans=0;while(x) Ans+=F2[x],x-=x&-x;return Ans;}
}
int main(){
//	freopen("1.in","r",stdin);
	int i,j;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]);for(Po[0]=i=1;i<=n;i++) Po[i]=Po[i-1]*B1%M1;Inv[1]=mpow(Po[1]);for(i=2;i<=n;i++) Inv[i]=Inv[i-1]*Inv[1]%M1;
	for(i=1;i<=n;i++){x=min(A[i]-1,n-A[i]);if(((BT::Q1(A[i]-1)-BT::Q1(A[i]-x-1))%M1*Inv[A[i]-x]%M1)^((BT::Q2(A[i]+x)-BT::Q2(A[i]))%M1*Inv[n-A[i]-x+1]%M1)){puts("YES");return 0;}BT::I1(A[i],Po[A[i]]);BT::I2(A[i],Po[n-A[i]+1]);}puts("NO");
}