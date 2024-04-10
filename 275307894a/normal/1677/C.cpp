#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (100000+5)
#define M (220+5)
#define K (12+5)
#define mod 1000000007
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
int T,n,cnt,Fl[N],A[N],B[N],F[N],x,Ns;ll Ans;
I ll calc(int l,int r){return 1ll*(l+r)*(r-l+1)/2;}
I void Solve(){
	int i,j;scanf("%d",&n);Ns=0;for(i=1;i<=n;i++)scanf("%d",&A[i]),F[A[i]]=i,Fl[i]=0;for(i=1;i<=n;i++) scanf("%d",&B[i]),B[i]=F[B[i]];
	for(i=1;i<=n;i++){if(Fl[i]) continue;
		x=i;cnt=1;while(B[x]^i) x=B[x],cnt++,Fl[x]=1;Ns+=cnt/2;
	}printf("%lld\n",(calc(n-Ns+1,n)-calc(1,Ns))*2);
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}