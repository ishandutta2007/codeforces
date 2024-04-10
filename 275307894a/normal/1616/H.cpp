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
#define N (150000+5)
#define M (1<<20)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define U unsigned int
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
int n,x,A[N+5],Ro;ll Ans,Po[N+5];
namespace Tree{
	int cnt,L[N*40+5],R[N*40+5],F[N*40+5];I void Ins(int x,int &now,int d){!now&&(now=++cnt);F[now]++;if(d==-1) return;Ins(x,x>>d&1?R[now]:L[now],d-1);}
	I ll calc(int N1,int N2,int d){
		if(!N1||!N2) return 0;if(d==-1)return (Po[F[N1]]-1)*(N1^N2?Po[F[N2]]-1:1)%mod;
		if(x>>d&1){
			if(N1==N2) return /*printf("%lld\n",x=calc(L[N1],R[N1],d-1)),*/(calc(L[N1],R[N1],d-1)+Po[F[L[N1]]]-1+Po[F[R[N1]]]-1)%mod;
			else{
				ll F1=calc(L[N1],R[N2],d-1),F2=calc(R[N1],L[N2],d-1);
				return ((F1+1)*(F2+1)-1+F1*(Po[F[R[N1]]]-1+Po[F[L[N2]]]-1)+F2*(Po[F[L[N1]]]-1+Po[F[R[N2]]]-1)+(Po[F[L[N1]]]-1)*(Po[F[L[N2]]]-1)+(Po[F[R[N1]]]-1)*(Po[F[R[N2]]]-1))%mod;
			} //return ((calc(L[N1],R[N2],d-1)+1)*(calc(R[N1],L[N2],d-1)+1)-1+(Po[F[L[N1]]]-1)*(Po[F[L[N2]]]-1)+(Po[F[R[N1]]]-1)*(Po[F[R[N2]]]-1))%mod;
		} 
		else return (calc(L[N1],L[N2],d-1)+calc(R[N1],R[N2],d-1))%mod;
	}
}
int main(){
//	freopen("1.in","r",stdin);//freopen("2.out","w",stdout);
	RI i;scanf("%d%d",&n,&x);for(i=1;i<=n;i++) scanf("%d",&A[i]),Tree::Ins(A[i],Ro,30);
	for(Po[0]=i=1;i<=n;i++) Po[i]=Po[i-1]*2%mod;printf("%lld\n",Tree::calc(Ro,Ro,30)%mod);
}