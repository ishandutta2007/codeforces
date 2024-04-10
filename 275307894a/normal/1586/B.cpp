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
#define M 30
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
using namespace std;
int n,m,Fl[N+5],T,x,y,z;
I void Solve(int x){
	RI i;for(i=1;i<=n;i++) i^x&&(printf("%d %d\n",i,x));
}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d",&T);while(T--){
		for(i=1;i<=n;i++) Fl[i]=0;scanf("%d%d",&n,&m);for(i=1;i<=m;i++) scanf("%d%d%d",&x,&y,&z),Fl[y]=1;
		for(i=1;i<=n;i++) if(!Fl[i]) Solve(i),i=n;; 
	}
}