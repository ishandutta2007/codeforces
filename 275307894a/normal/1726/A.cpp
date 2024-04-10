#include<bits/stdc++.h>
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((m)*(x-1)+(y))
#define R(n) (rnd()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using ll=long long;using db=double;using lb=long db;using ui=unsigned;using ull=unsigned ll;
using namespace std;const int N=2e5+5,M=(1<<18)+5,K=1e5+5,mod=998244353,Mod=mod-1;const db eps=1e-5;const int INF=1e9+7;
int Ans,n,m,x,y,z,A[N];
void Solve(){
	int i,j;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]);
	Ans=0;for(i=1;i<n;i++)Ans=max(Ans,A[n]-A[i]);for(i=2;i<=n;i++) Ans=max(Ans,A[i]-A[1]);
	for(i=1;i<=n;i++) Ans=max(Ans,A[i]-A[i%n+1]);printf("%lld\n",Ans);
}
int main(){
//	freopen("1.in","r",stdin);
	int T;scanf("%d",&T);while(T--) Solve(); 
}