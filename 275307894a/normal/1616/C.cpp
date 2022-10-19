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
#define N (200000+5)
#define M (1<<20)
#define mod 100003
#define Mod (mod-1)
#define eps (1e-7)
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
int n,T,A[N+5],cnt,Ans;db Ns;
I void Solve(){
	RI i,j,h;scanf("%d",&n);cnt=0;for(i=1;i<=n;i++)scanf("%d",&A[i]);
	if(n==1){puts("0");return;}Ans=1e9;
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			Ns=(A[j]-A[i])*1.0/(j-i);
			cnt=0;for(h=1;h<=n;h++)if(fabs(A[h]-(A[i]-i*Ns+h*Ns))<=eps) cnt++;Ans=min(Ans,n-cnt);
		}
	}printf("%d\n",Ans);
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}