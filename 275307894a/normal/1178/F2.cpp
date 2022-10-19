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
#define N 1000
#define K 1000000
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
using namespace std;
int n,m,B[N+5],x,Bh,Mi,L,R;ll dp[N+5][N+5],T1,T2;vector<int> S[N+5];
int main(){
//	freopen("1.in","r",stdin);
	RI i,j,h;scanf("%d%d",&n,&m);for(i=1;i<=m;i++) {scanf("%d",&x);if(!Bh||B[Bh]^x) B[++Bh]=x;if(Bh>2*m){Pc('0');return 0;}}
	for(i=1;i<=Bh;i++) S[B[i]].push_back(i);for(i=1;i<=Bh+1;i++) dp[i][i-1]=1;
	for(i=Bh;i;i--){
		for(j=i;j<=Bh;j++){
			Mi=1e9;for(h=i;h<=j;h++) Mi=min(Mi,B[h]);L=S[Mi][0];R=S[Mi][S[Mi].size()-1];if(L<i||R>j) continue;
			dp[i][j]=1;for(h=1;h<S[Mi].size();h++) dp[i][j]=dp[i][j]*dp[S[Mi][h-1]+1][S[Mi][h]-1]%mod;T1=T2=0;
			for(h=i;h<=L;h++) T1=(T1+dp[i][h-1]*dp[h][L-1])%mod;for(h=R;h<=j;h++) T2=(T2+dp[R+1][h]*dp[h+1][j])%mod;dp[i][j]=dp[i][j]*(T1%mod)%mod*(T2%mod)%mod;
		}
	}printf("%lld\n",dp[1][Bh]);
}