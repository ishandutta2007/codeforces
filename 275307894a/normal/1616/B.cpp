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
#define M (1<<20)
#define mod 100003
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
int T,n,cnt,Id;char A[N+5];
I void Solve(){
	RI i;scanf("%d",&n);scanf("%s",A+1);if(A[1]==A[2]){printf("%c%c\n",A[1],A[1]);;return;}
	Id=n;for(i=2;i<=n;i++){if(A[i]>A[i-1]){Id=i-1;break;}}
	for(i=1;i<=Id;i++)Pc(A[i]);for(i=Id;i;i--) Pc(A[i]);Pc('\n');
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}