#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (100000+5)
#define M (50000+5)
#define K (20+5)
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
int T,n,k;
I void Solve(){
	int i,j;scanf("%d%d",&n,&k);if((n+1)/2<k){puts("-1");return;}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++) Pc(i==j&&i&1&&k?(k--,'R'):'.');Pc('\n');
	}
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}