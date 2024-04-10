#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (500000+5)
#define M (5000000-5)
#define K (1500+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (1ll*rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;
int T,n,A[N],B[N];
I void Solve(){
	int i;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]);if(n&1){puts("NO");return ;}
	sort(A+1,A+n+1);for(i=1;i<=n;i++) i<=n/2?(B[i*2-2]=A[i]):(B[(i-n/2)*2-1]=A[i]);
	for(i=0;i<n;i++)if(!(B[i]<B[(i+1)%n]&&B[i]<B[(i-1+n)%n])&&!(B[i]>B[(i+1)%n]&&B[i]>B[(i-1+n)%n])){puts("NO");return;}puts("YES");
	for(i=0;i<n;i++) printf("%d ",B[i]);Pc('\n');
}
int main(){
////	freopen("1.in","r",stdin);
	int i,j;scanf("%d",&T);while(T--) Solve();
}