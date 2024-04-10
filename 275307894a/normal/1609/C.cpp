#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define U unsigned int
#define db double
#define lb long db
#define N (1000000+5)
#define M ((1<<11)+5)
#define mod 1000000001
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
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
int Fl[N],R[N],L[N],pr[N],Q[N],ph,T,n,A[N],e;ll Ans;
I void Solve(){
	int i,j;scanf("%d%d",&n,&e);for(i=1;i<=n+e;i++) Q[i]=0;
	for(i=1;i<=n;i++) scanf("%d",&A[i]);for(i=n;i;i--) Q[i]=(i+e<=n?Q[i+e]+(!Fl[A[i]]&&A[i]^1):(!Fl[A[i]]&&A[i]^1)); 
	Ans=0;for(i=n;i;i--){
		if(Fl[A[i]]) {R[i]=i;L[i]=i;continue;}if(i+e>n){R[i]=i+e;L[i]=i+e;continue;}R[i]=R[i+e];L[i]=L[i+e];
		while(Q[i]-1>Q[R[i]]) R[i]-=e;while(Q[i]>Q[L[i]]) L[i]-=e;Ans+=(R[i]-L[i])/e;if(L[i]==i) Ans--;//cerr<<i<<' '<<R[i]<<' '<<L[i]<<' '<<Ans<<'\n';
	}printf("%lld\n",Ans);
}
int main(){
////	freopen("1.in","r",stdin);
	int i,j;for(i=2;i<N;i++){
		!Fl[i]&&(pr[++ph]=i);for(j=1;j<=ph&&i*pr[j]<N;j++){Fl[i*pr[j]]=1;if(i%pr[j]==0)break;}
	}
	scanf("%d",&T);while(T--) Solve();
}