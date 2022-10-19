#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (200000+5)
#define M ((1<<16)+5)
#define K (1000+5)
#define mod 998244353
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
int T,n,A[N],H,L[N],R[N];
I void Solve(){
	int i,j;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]);
	H=0;for(i=1;i<=n;i=j){for(j=i+1;j<=n;j++) if(A[i]^A[j])break;if(j-i>1) L[++H]=i,R[H]=j-1;}
	if(H==1)printf("%d\n",R[1]-L[1]+1==3?1:max(R[1]-L[1]-2,0));else printf("%d\n",max(R[H]-L[1]-2,0));
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}