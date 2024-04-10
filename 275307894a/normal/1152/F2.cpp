#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (100000+5)
#define M (220+5)
#define K (12+5)
#define mod 1000000007
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
int n,m,k,Ks,H,x,y,z,G[17],Id[20][20];ll ToT;
struct MaT{
	ll A[M][M];I MaT(){Me(A,0);}MaT operator *(const MaT &B)const{
		MaT C;int i,j,h;for(h=1;h<=H;h++) for(i=1;i<=H;i++) for(j=1;j<=H;j++) C.A[i][j]=(C.A[i][j]+A[i][h]*B.A[h][j])%mod;return C;
	}
}Ans,Cl;
int main(){
//	freopen("1.in","r",stdin);
	int i,j,h;scanf("%d%d%d",&n,&k,&m);Ks=(1<<m)-1;for(i=1;i<=Ks;i++) G[i]=G[i/2]+(i&1);
	for(i=0;i<=k;i++) for(j=0;j<=Ks;j++) i>=G[j]&&(Id[i][j]=++H);Ans.A[1][Id[0][0]]=1;
	for(i=0;i<=k;i++){
		for(j=0;j<=Ks;j++) Id[i][j]&&(Cl.A[Id[i][j]][Id[i][(j<<1)&Ks]]=1,i&&(Cl.A[Id[i-1][j]][Id[i][(j<<1|1)&Ks]]=G[j]+1));
	}while(n) n&1&&(Ans=Ans*Cl,0),Cl=Cl*Cl,n>>=1;
	for(i=0;i<=Ks;i++) Id[k][i]&&(ToT+=Ans.A[1][Id[k][i]]);printf("%lld\n",ToT%mod);
}