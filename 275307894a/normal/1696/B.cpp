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
int T,n,A[N],x,y,z;
I void Solve(){
	int i,j;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]);
	x=y=z=0;for(i=1;i<=n;i++) A[i]?(x++):(z+=(x>0),x=0);z+=(x>0);printf("%d\n",min(z,2));
}
int main(){
////	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}