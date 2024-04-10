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
#define M (N*200)+5
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
int n,m,k,T,A[N+5],Bh,B[N+5],F1[N+5],F2[N+5],Tp;
I void Solve(){
	RI i,j,h;Bh=0;scanf("%d",&n);for(i=0;i<=n;i++) F1[i]=F2[i]=0;for(i=1;i<=n;i++)scanf("%d",&A[i]),F2[A[i]]++;
	for(i=1;i<=n;i=j+1){
		Tp=-1;for(j=i;j<=n;j++){
			F1[A[j]]++;F2[A[j]]--;while(F1[Tp+1]) Tp++;
			if(!F2[Tp+1]) break;
		}B[++Bh]=Tp+1;
		for(h=i;h<=j;h++) F1[A[h]]=0;
	}printf("%d\n",Bh);for(i=1;i<=Bh;i++) printf("%d ",B[i]);Pc('\n');
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}