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
#define N 100000
#define K 1000
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int n,a,b,T,m,A[N+5]; 
I void Solve(){
	RI i;scanf("%d%d%d",&n,&a,&b);if(abs(a-b)>1||a+b>n-2||a>(n-1)/2||b>(n-1)/2){puts("-1");return;}
	if(a==b){
		for(i=1;i<=n;i++) A[i]=i;
		for(i=1;i<=a;i++)swap(A[i*2],A[i*2+1]);
	}else if(a==b+1){
		for(i=1;i<=n;i++) A[i]=i;for(i=1;i<a;i++) swap(A[i*2],A[i*2+1]);
		reverse(A+2*b+2,A+n+1);
	}else if(a+1==b){
		for(i=1;i<=n;i++) A[i]=i;reverse(A+1,A+n+1);
		for(i=1;i<b;i++) swap(A[i*2],A[i*2+1]);
		reverse(A+2*a+2,A+n+1);
	}for(i=1;i<=n;i++) printf("%d ",A[i]);Pc('\n');
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}