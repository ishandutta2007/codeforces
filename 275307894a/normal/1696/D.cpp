#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (300000+5)
#define M (30000+5)
#define K (6)
#define mod 1000000007
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
int T,n,cnt,z,x,y,F1[N][20],F2[N][20],A[N],L1[N],L2[N],R1[N],R2[N],st[N],H;
I void Solve(){
	int i,j;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]);for(i=1;i<=n;i++) L1[i]=L2[i]=0,R1[i]=R2[i]=n+1;H=0;
	H=0;for(i=1;i<=n;i++) {while(H&&A[st[H]]<A[i]) R1[st[H]]=i,H--;L1[i]=st[H];st[++H]=i;}
	H=0;for(i=1;i<=n;i++) {while(H&&A[st[H]]>A[i]) R2[st[H]]=i,H--;L2[i]=st[H];st[++H]=i;}
	for(i=n;i;i--) for(F1[i][0]=L1[i],j=1;i+(1<<j)-1<=n;j++) F1[i][j]=min(F1[i][j-1],F1[i+(1<<j-1)][j-1]);
	for(i=n;i;i--) for(F2[i][0]=L2[i],j=1;i+(1<<j)-1<=n;j++) F2[i][j]=min(F2[i][j-1],F2[i+(1<<j-1)][j-1]);
	z=1;cnt=0;while(z^n){
		x=R1[z]-1;for(i=20;~i;i--) x-(1<<i)+1>=z&&F2[x-(1<<i)+1][i]>z&&(x-=(1<<i));
		y=R2[z]-1;for(i=20;~i;i--) y-(1<<i)+1>=z&&F1[y-(1<<i)+1][i]>z&&(y-=(1<<i));
		z=max(y,x);cnt++;
	}printf("%d\n",cnt);
}
int main(){
////	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}