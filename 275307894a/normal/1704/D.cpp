#include<bits/stdc++.h>
#define I inline
#define ll long long
#define db double
#define lb long db
#define N (300000+5)
#define M ((N<<1)+5)
#define K (1500+5)
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-5)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((k+1)*(x)+(y))
#define R(n) (1ll*rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;
int n,m,k;ll B[N],Sum[N],Mx;
I void Solve(){
	int i,j;Mx=0;scanf("%d%d",&n,&m);for(i=1;i<=n;i++){Sum[i]=0;for(j=1;j<=m;j++) scanf("%lld",&B[j]),B[j]+=B[j-1],Sum[i]+=B[j];Mx=max(Mx,Sum[i]);}
	for(i=1;i<=n;i++) if(Sum[i]^Mx){printf("%d %lld\n",i,Mx-Sum[i]);return;}
}
int main(){
////	freopen("1.in","r",stdin);
	int T;scanf("%d",&T);while(T--) Solve();
}