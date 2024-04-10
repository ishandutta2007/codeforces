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
#define N 30000
#define K 400
#define mod 20170408
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar()
#define Pc(x) putchar(x) 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*(x-1)+(y))
using namespace std;
int T,n,m;
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--){
		scanf("%d%d",&n,&m);if((n+m)&1){puts("-1");continue;}if(!n&&!m){puts("0");continue;}
		printf("%d\n",2-(n==m));
	}
}