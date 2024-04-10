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
using namespace std;const int N=200+5,M=6000+5,K=(1<<16)+5,mod=998244353,M1=998244353,M2=1e9+7,Mod=mod-1;const db eps=1e-5;
int n,m,P1[N],P2[N],Ct,f[N][M],Ans;ll x;
int main(){
//	freopen("1.in","r",stdin);
	int i,j,h;scanf("%d%d",&n,&m);for(i=1;i<=n;i++){scanf("%lld",&x);while(x%2==0) P1[i]++,x/=2;while(x%5==0) P2[i]++,x/=5;Ct+=P2[i];}
	Me(f,-0x3f);f[0][0]=0;for(i=1;i<=n;i++){
		for(j=m;j;j--){
			for(h=Ct;h>=P2[i];h--) f[j][h]=max(f[j][h],f[j-1][h-P2[i]]+P1[i]);
		}
	}for(i=0;i<=Ct;i++) Ans=max(Ans,min(i,f[m][i]));printf("%d\n",Ans);
}