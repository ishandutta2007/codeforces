#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 100000
#define M 20000
#define mod 2520
#define eps (1e-7)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
using namespace std;
int T,G[2521],Y[2521],cnt,Lcm[2521][2521];ll po,l,r,tot,pus,now,dp[20][2521][50][10],F[20][2521][50],Ans;
I int lcm(int x,int y){return x*y/__gcd(x,y);} 
I ll solve(ll x){
	re int i,j,k,h;Ans=pus=tot=0;for(po=1e18,i=19;i;i--){//printf("%lld\n",dp[1][3][3][3]);
		for(j=0;j<x/po;j++){
			for(k=1;k<=48;k++){now=Lcm[pus][Y[k]];
				for(h=0;h<mod;h+=now) Ans+=dp[i][(h-tot+mod)%mod][k][j]/*,printf("%lld\n",Ans)*/;
			}
		}tot=(tot+x/po*po)%mod;pus=Lcm[pus][x/po];x%=po;po/=10;
	}return Ans+(!pus||tot%pus==0);
}
int main(){
//	freopen("1.in","r",stdin);
	int i,j,h,k;for(i=1;i<=mod;i++)if(mod%i==0)Y[G[i]=++cnt]=i;dp[0][0][1][0]=1;//printf("%d\n",cnt);
	for(i=1;i<=mod;i++) Lcm[i][0]=Lcm[0][i]=i;for(i=1;i<=mod;i++) for(j=1;j<=mod;j++) Lcm[i][j]=lcm(i,j);
	for(po=1,i=0;i<=18;i++){
		for(j=0;j<mod;j++){
			for(k=1;k<=48;k++) for(h=0;h<=9;h++) F[i][j][k]+=dp[i][j][k][h];
		}
		for(j=0;j<mod;j++){
			for(k=1;k<=48;k++){
				for(h=0;h<=9;h++) dp[i+1][(h*po+j)%mod][G[Lcm[Y[k]][h]]][h]+=F[i][j][k];
			}
		}po*=10;
	}//printf("%lld\n",dp[2][15][5][1]);
	scanf("%d",&T);while(T--) scanf("%I64d%I64d",&l,&r),printf("%I64d\n",solve(r)-solve(l-1));
}