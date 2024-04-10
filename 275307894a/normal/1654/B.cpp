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
#define N (200000+5)
#define M (100000)
#define mod 998244353
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
int n,F[200],T;char A[N];
I void Solve(){
	Me(F,0);RI i,j;scanf("%s",A+1);n=strlen(A+1);for(i=1;i<=n;i++) F[A[i]]++;
	for(i=1;i<=n;i++){F[A[i]]--;if(!F[A[i]]) break;}for(j=i;j<=n;j++)Pc(A[j]);Pc('\n');
}
int main(){
/////////	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}