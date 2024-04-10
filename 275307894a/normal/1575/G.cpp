#include<bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define RI re int
#define ll long long
#define db double
#define lb long db
#define N 100000
#define M 5
#define mod 1000000007
#define Mod 998244352
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
using namespace std;
int n,k,pr[N+5],ph,Fl[N+5],mu[N+5],A[N+5],B[N+5],Bh,S[N+5],Maxn,F[N+5];ll Ans,ToT,Pus;
I ll Solve1(int x){
	Me(S,0);RI i,j;for(i=x;i<=n;i+=x) S[A[i]]++;
	ToT=0;for(i=1;i<=Maxn;i++){
		for(Pus=0,j=i;j<=Maxn;j+=i)Pus+=S[j];ToT+=Pus*Pus*F[i];
	}return ToT%mod;
}
I ll Solve2(int x){
	RI i,j;ToT=0;Bh=0;for(i=x;i<=n;i+=x) B[++Bh]=A[i];for(i=1;i<=Bh;i++) for(ToT+=B[i],j=i+1;j<=Bh;j++) ToT+=2*__gcd(B[i],B[j]);return ToT%mod;
}
int main(){
//	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	RI i,j;scanf("%d",&n);Maxn=n;for(i=1;i<=n;i++) scanf("%d",&A[i]),Maxn=max(Maxn,A[i]);k=pow(n,0.55);
	for(mu[1]=1,i=2;i<=Maxn;i++){
		!Fl[i]&&(mu[i]=-1,pr[++ph]=i);for(j=1;j<=ph&&i*pr[j]<=Maxn;j++){
			Fl[i*pr[j]]=1;if(i%pr[j]==0)break;mu[i*pr[j]]=-mu[i];
		}
	}
	for(i=1;i<=Maxn;F[i]%=mod,i++) for(j=i;j<=Maxn;j+=i) F[j]+=mu[j/i]*i;
	for(i=1;i<=n;i++) {
		if(i<=k) Ans+=Solve1(i)*F[i]%mod; 
		else Ans+=Solve2(i)*F[i]%mod;
	}printf("%lld\n",(Ans%mod+mod)%mod);
}