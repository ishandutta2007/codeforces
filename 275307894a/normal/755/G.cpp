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
#define N (1<<16)
#define M 1000000
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int n,m,k,Ts,tr[N+5];
I ll mpow(ll x,int y=mod-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%mod),y>>=1,x=x*x%mod;return Ans;}const ll G=3,InvG=mpow(G);
I void NTT(ll *F,int n,int Fl){
	RI i,j,h;ll key,pus,now;for(i=0;i<n;i++) i<tr[i]&&(swap(F[i],F[tr[i]]),0);
	for(i=2;i<=n;i<<=1){
		for(key=mpow(Fl?G:InvG,(mod-1)/i),j=0;j<n;j+=i){
			for(pus=1,h=j;h<j+i/2;h++) now=pus*F[h+i/2]%mod,F[h+i/2]=(F[h]-now+mod)%mod,F[h]=(F[h]+now)%mod,pus=pus*key%mod;
		}
	}if(Fl) return;ll Invn=mpow(n);for(i=0;i<n;i++) F[i]=F[i]*Invn%mod;
}
struct Node{
	ll F[3][N+5],G[3][N+5],A[3][N+5],B[2][N+5];I void Ins(){memcpy(F[0],F[1],sizeof(F[1]));memcpy(F[1],F[2],sizeof(F[1]));for(RI i=0;i<=k;i++) F[2][i]=F[1][i],i&&(F[2][i]=(F[2][i]+F[1][i-1]+F[0][i-1])%mod);}
	I void Jump(){
		RI i,j;memcpy(G,F,sizeof(G));
		Me(A,0);Me(B,0);NTT(G[0],m,1);NTT(G[1],m,1);NTT(G[2],m,1);//NTT(G[0],m,0);NTT(G[1],m,0);NTT(G[2],m,0);
		for(i=0;i<m;i++) A[0][i]=G[1][i]*G[1][i]%mod,A[1][i]=G[2][i]*G[1][i]%mod,A[2][i]=G[2][i]*G[2][i]%mod,B[0][i]=G[0][i]*G[0][i]%mod,B[1][i]=G[0][i]*G[1][i]%mod;
		NTT(A[0],m,0);NTT(A[1],m,0);NTT(A[2],m,0);NTT(B[0],m,0);NTT(B[1],m,0);for(i=0;i<=k;i++) F[0][i]=A[0][i],F[1][i]=A[1][i],F[2][i]=A[2][i],i&&(F[0][i]+=B[0][i-1],F[1][i]+=B[1][i-1],F[2][i]+=A[0][i-1]);  
	}
}S;
I int Cnt(int x){int cnt=0;while(x) cnt++,x>>=1;return cnt;}
int main(){
//	freopen("1.in","r",stdin);
	RI i,j;scanf("%d%d",&n,&k);for(m=1;m<=(k<<1);m<<=1);for(i=0;i<m;i++) tr[i]=(tr[i>>1]>>1)|((i&1)?m/2:0);
	S.F[0][0]=1;S.F[1][0]=S.F[1][1]=1;S.F[2][0]=1;S.F[2][1]=3;S.F[2][2]=1;
	if(n==1){for(i=1;i<=k;i++) printf("%lld ",S.F[1][i]);return 0;}
	if(n>2){Ts=Cnt(n)-1;if((n>>Ts-1)&1) S.Ins();for(i=Ts-2;~i;i--) S.Jump(),n>>i&1&&(S.Ins(),0);}
	for(i=1;i<=k;i++) printf("%lld ",S.F[2][i]%mod);
}