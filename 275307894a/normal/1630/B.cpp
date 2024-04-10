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
int T,n,k,X,Y,Q[N+5],A[N+5],F[N+5],Ans,R,ToT,Pus;
I void Solve(){
	RI i,j;for(i=1;i<=n;i++) F[i]=A[i]=0;Ans=1e9;R=0;
	scanf("%d%d",&n,&k);for(i=1;i<=n;i++) scanf("%d",&A[i]),F[A[i]]++;for(i=1;i<=n;i++) Q[i]=Q[i-1]+F[i];
	for(R=i=1;i<=n;i++){
		while(Q[i]-Q[R]-(n-(Q[i]-Q[R]))>=k)R++;if (Q[i]-Q[R-1]-(n-(Q[i]-Q[R-1]))>=k)Ans=min(Ans,i-R);
	}
	for(R=i=1;i<=n;i++){
		while(Q[i]-Q[R]-(n-(Q[i]-Q[R]))>=k)R++;if(Q[i]-Q[R-1]-(n-(Q[i]-Q[R-1]))>=k&&i-R==Ans){
			X=R;Y=i;printf("%d %d\n",X,Y);ToT=Pus=0;
			for(R=j=1;j<=n&&Pus<k-1;j++) {
				ToT+=(A[j]>=X&&A[j]<=Y?1:-1);if(ToT>0){
					printf("%d %d\n",R,j);R=j+1;Pus++;ToT=0;
				} 
			}printf("%d %d\n",R,n);break;
		}
	}
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}