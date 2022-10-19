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
#define N 1000
#define M 500000
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
#define LB lower_bound
#define UB upper_bound 
using namespace std;
int T,n,k;
I void Solve(){
	RI i;scanf("%d%d",&n,&k);if(k==n-1) {
		if(n==4){puts("-1");return;}printf("%d %d\n",n-1,n-2);printf("%d %d\n",1,3);printf("%d %d\n",0,n-4);printf("%d %d\n",2,n-3);
		for(i=4;i<n/2;i++)printf("%d %d\n",i,(n-1)^i);
	    return;
	}
	printf("%d %d\n",n-1,k);if(k)printf("0 %d\n",(n-1)^k);     
	for(i=1;i<n/2;i++){
		if(((n-1)^i)==k||i==k) continue;printf("%d %d\n",i,(n-1)^i);
	}
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}