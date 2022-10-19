#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (5000+5)
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
int n;ll Ans=1e18,ToT,A[N],B[N];
int main(){
//	freopen("1.in","r",stdin);
	int i,j;scanf("%d" ,&n);for(i=1;i<=n;i++) scanf("%lld",&A[i]);
	for(i=1;i<=n;i++){
		Me(B,0);ToT=0;for(j=i-1;j;j--) B[j]=(B[j+1]+A[j])/A[j]*A[j],ToT+=B[j]/A[j];
		for(j=i+1;j<=n;j++) B[j]=(B[j-1]+A[j])/A[j]*A[j],ToT+=B[j]/A[j];Ans=min(ToT,Ans);
	}printf("%lld\n",Ans);
}