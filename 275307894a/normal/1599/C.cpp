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
#define M 5
#define mod 1000000007
#define Mod 998244352
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
using namespace std;
int n,m,k,ToT;db p,now;
I db calc(db x){
	db y=n-x;return (y*(y-1)*(y-2)/6+x*y*(y-1)/4)/(1.0*n*(n-1)*(n-2)/6);
}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d%lf",&n,&p);
	for(i=0;i<=n;i++)if(1-calc(i)>=p){printf("%d\n",i);return 0;}
}