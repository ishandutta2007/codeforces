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
#define N 200000
#define M 100
#define mod 1000000007
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
using namespace std;
int n,k,dp[2][N+5],Ne,La,Ans=1e9,Len,Q[N+5],H,T;
struct Ques{int l,r;}S[M+5];I bool cmp(Ques x,Ques y){return x.l<y.l;}
int main(){
	//freopen("1.in","r",stdin);
	RI i,j,h;scanf("%d%d",&n,&k);for(i=1;i<=k;i++) scanf("%d%d",&S[i].l,&S[i].r);sort(S+1,S+k+1,cmp);
	Me(dp,0x3f);dp[0][0]=0;for(i=1;i<=k;i++){
		Ne=i&1;La=Ne^1;Mc(dp[Ne],dp[La]);Len=S[i].r-S[i].l;Q[H=T=0]=0;
		for(j=1;j<=S[i].r;j++){
			while(H<=T&&dp[La][Q[T]]>dp[La][j]) T--;Q[++T]=j;while(H<=T&&j-Q[H]>min(Len,j)) H++;H<=T&&(dp[Ne][j]=min(dp[Ne][j],dp[La][Q[H]]+2));
		}Q[H=T=0]=0;
		for(j=S[i].r;j;j--){
			while(H<=T&&S[i].r-j-Q[H]>min(Len,S[i].r-j)) H++;while(H<=T&&dp[La][Q[T]]>dp[La][S[i].r-j]) T--;Q[++T]=S[i].r-j;H<=T&&(dp[Ne][j]=min(dp[Ne][j],dp[La][Q[H]]+1));
		}
		/*for(j=0;j<=S[i].r;j++){
			for(h=0;h<=min(S[i].r-j,Len);h++) dp[Ne][j]=min(dp[Ne][j],dp[La][S[i].r-j-h]+1);
		}*/Ans=min(Ans,dp[Ne][n]);
	}if(Ans<1e9) printf("Full\n%d",Ans);else puts("Hungry");
}