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
#define N 300000
#define K 1000000
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
ll n,m,F1,F2,F3,c;
struct MaT{
	ll A[3][3];MaT(){Me(A,0);}MaT operator *(const MaT &B)const{
		MaT C;RI i,j,h;for(h=0;h<3;h++){
			for(i=0;i<3;i++) for(j=0;j<3;j++) C.A[i][j]=(C.A[i][j]+A[i][h]*B.A[h][j])%Mod;
		}return C;
	}
}Bas,Ans;
I ll mpow(ll x,ll y=mod-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%mod),y>>=1,x=x*x%mod;return Ans;}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%lld%lld%lld%lld%lld",&n,&F1,&F2,&F3,&c);m=n;Bas.A[0][0]=Bas.A[1][0]=Bas.A[2][0]=Bas.A[0][1]=Bas.A[1][2]=1;
	Ans.A[0][0]=Ans.A[1][1]=Ans.A[2][2]=1;n-=3;while(n) n&1&&(Ans=Ans*Bas,0),n>>=1,Bas=Bas*Bas;
	printf("%lld\n",mpow(c,Ans.A[0][0]*3+Ans.A[1][0]*2+Ans.A[2][0])*mpow(F1,Ans.A[2][0])%mod*mpow(F2,Ans.A[1][0])%mod*mpow(F3,Ans.A[0][0])%mod*mpow(mpow(c,m))%mod);
}