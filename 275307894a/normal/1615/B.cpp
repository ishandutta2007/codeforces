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
#define N 200000
#define M 500
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-7)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int n,m,k,Ans[N+5],Q[N+5],L[N+5],R[N+5];
int main(){
//	freopen("1.in","r",stdin);
	RI i,j;scanf("%d",&n);Me(Ans,0x3f);for(i=1;i<=n;i++) scanf("%d%d",&L[i],&R[i]);
	for(i=0;i<=20;i++){
		for(j=0;j<=N;j++) Q[j]=Q[j-1]+(j>>i&1);
		for(j=1;j<=n;j++)Ans[j]=min(Ans[j],R[j]-L[j]+1-Q[R[j]]+Q[L[j]-1]);
	}for(i=1;i<=n;i++) printf("%d\n",Ans[i]);
}