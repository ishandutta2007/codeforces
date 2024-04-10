#include<bits/stdc++.h>
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((k+1)*(x)+(y))
#define R(n) (rnd()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using ll=long long;using db=double;using lb=long db;using ui=unsigned;using ull=unsigned ll;
using namespace std;const int N=50+5,M=1<<18|5,K=200+5,mod=1e9+7,Mod=mod-1;const db eps=1e-5;
int n,m;ll g[N][N],z,Po[N],Inv[N];
ll mpow(ll x,int y=mod-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%mod),y>>=1,x=x*x%mod;return Ans;}
int main(){
//	freopen("1.in","r",stdin);
	int i,j,h,k,a,b,c;scanf("%d%d",&n,&m);g[0][0]=1;for(i=1;i<=n;i++) Inv[i]=mpow(i);
	for(i=0;i<=n;i++){
		for(j=0;j*2<=i;j++){
			z=0;for(h=j;h+j<=i;h++) for(k=h;k+j<=i;k++) z=(z+g[k][h]*g[i-k][j])%mod;
			for(h=j+1;h+j<=i;h++) for(k=h;k+j<=i;k++) z=(z+g[k][h]*g[i-k][j])%mod;
			for(Po[0]=c=1;c<=n;c++) Po[c]=Po[c-1]*(z+c-1)%mod*Inv[c]%mod;
			for(a=n;a>i;a--) for(b=n;b>j;b--) for(c=1;c*(i+1)<=a&&c*(j+1)<=b;c++)g[a][b]=(g[a][b]+g[a-(i+1)*c][b-(j+1)*c]*Po[c])%mod;
		}
	}printf("%lld\n",g[n][m-1]);
}