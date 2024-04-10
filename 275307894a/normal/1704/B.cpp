#include<bits/stdc++.h>
#define I inline
#define ll long long
#define db double
#define lb long db
#define N (200000+5)
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
int n,x,A[N],Ns,L,R;ll Ans;
I void Solve(){
	int i,j;scanf("%d%d",&n,&x);for(i=1;i<=n;i++)scanf("%d",&A[i]);
	Ans=0;Ns=1;while(Ns<=n){
		L=A[Ns]-x;R=A[Ns]+x;for(i=Ns+1;i<=n;i++) {if(max(L,A[i]-x)>min(R,A[i]+x)){Ans++;Ns=i;break;}L=max(L,A[i]-x);R=min(R,A[i]+x);}
		if(i>n) break;
	}
	printf("%lld\n",Ans);
}
int main(){
//	freopen("1.in","r",stdin);
	int T;scanf("%d",&T);while(T--) Solve();
}