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
#define N (100000+5)
#define M (100000)
#define mod 998244353
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
int n,A[N],Maxn,k,H;int Ans=1e9;ll B[N];
int main(){
//	freopen("1.in","r",stdin);
	RI i,j,h;scanf("%d",&n);Ans=n-1;for(i=1;i<=n;i++)scanf("%d",&A[i]),Maxn=max(Maxn,A[i]);k=sqrt(Maxn);
	for(i=-k;i<=k;i++){
		for(j=1;j<=n;j++) B[j]=A[j]-1ll*i*j;sort(B+1,B+n+1);
		for(j=1;j<=n;j=h){
			for(h=j;h<=n;h++) if(B[j]^B[h]) break;
			Ans=min(Ans,n-(h-j));
		}
	}
	for(i=1;i<=n;i++){
		H=0;for(j=1;j<=min(n-i,Maxn/k+1);j++)if((A[i]-A[i+j])%j==0&&abs((A[i]-A[i+j])/j)>k) B[++H]=(A[i]-A[i+j])/j;
		sort(B+1,B+H+1);for(j=1;j<=H;j=h){
			for(h=j;h<=H;h++) if(B[j]^B[h]) break;
			Ans=min(Ans,n-(h-j+1));
		}
	}printf("%d\n",Ans);
}