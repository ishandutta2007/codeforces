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
#define N 1200000
#define M 10
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int n,A[N+5],C[N+5];
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]);for(i=1;i<=n;i++) scanf("%d",&C[i]);
	if(A[1]^C[1]||A[n]^C[n]){puts("No");return 0;}
	for(i=1;i<n;i++) A[i]-=A[i+1],C[i]-=C[i+1];sort(A+1,A+n);sort(C+1,C+n);for(i=1;i<n;i++) if(A[i]^C[i]){puts("No");return 0;}puts("Yes"); 
}