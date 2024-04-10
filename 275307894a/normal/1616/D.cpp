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
#define N (50000+5)
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
int n,T,A[N+5],x,Ans,dp[N+5],La;ll Q[N+5];const ll INF=1e11;
I void Solve(){
	RI i,j;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]);
	scanf("%d",&x);for(i=1;i<=n;i++) A[i]-=x;Ans=0;
	for(i=1;i<=n;i=j+1){
		for(j=i+1;j<=n;j++) {
			if(j==i+1){
				if(A[j]+A[j-1]<0) break;
			}else if(A[j]+A[j-1]<0||A[j]+A[j-1]+A[j-2]<0) break;
		}Ans+=j-i;
	}printf("%d\n",Ans);
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--)Solve();
}