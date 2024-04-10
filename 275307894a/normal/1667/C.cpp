#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (500000+5)
#define M (100+5)
#define K (1000+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
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
int n,m,k,ks;
int main(){
//	freopen("1.in","r",stdin);
	int i;scanf("%d",&n);k=(2*n+1)/3;
	if(k&1){printf("%d\n",k);
		ks=k/2;for(i=1;i<=ks;i++) printf("%d %d\n",i,ks-i+1);
		for(i=ks+1;i<=k;i++) printf("%d %d\n",i,k+ks+1-i); 
	}else{printf("%d\n",k);
		ks=k/2;for(i=1;i<ks;i++) printf("%d %d\n",i,ks-i);printf("%d %d\n",ks,ks);
		for(i=ks+1;i<=k;i++) printf("%d %d\n",i,k+ks+1-i); 
	}
	
}