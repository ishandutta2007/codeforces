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
#define N (300000+5)
#define M (500000+5)
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
#define PB push_back
using namespace std;
int n,m,k,T,Mx,F[N+5],A[N+5],La;vector<int> S[N];
I void Solve(){
	RI i,j;scanf("%d",&n);for(i=1;i<=n;i++) S[i].clear(),S[i].PB(0),F[i]=1e9;for(i=1;i<=n;i++) scanf("%d",&A[i]),S[A[i]].PB(i);
	for(i=1;i<=n;i++) S[i].PB(n+1);
	for(i=1;i<=n;i++) {
		if(!S[i].size()) continue;Mx=0;for(j=1;j<S[i].size();j++) Mx=max(Mx,S[i][j]-S[i][j-1]);F[Mx]=min(i,F[Mx]);
	}for(i=1;i<=n;i++) F[i]=min(F[i-1],F[i]),printf("%d ",F[i]==1e9?-1:F[i]);Pc('\n');
}
int main(){
//	freopen("1.in","r",stdin);
	F[0]=1e9;scanf("%d",&T);while(T--) Solve();
}