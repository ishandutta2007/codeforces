#include<bits/stdc++.h>
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((m)*(x-1)+(y))
#define R(n) (rnd()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using ll=long long;using db=double;using lb=long db;using ui=unsigned;using ull=unsigned ll;
using namespace std;const int N=1e5+5,M=N*4+5,K=2e3+5,mod=1e9+7,Mod=mod-1;const db eps=1e-5;const int INF=1e9+7;
int n,m,k,A[N],Fl;ll z;
void Solve(){
	int i,j;scanf("%d%d%d",&n,&m,&k);for(i=1;i<=k;i++)scanf("%d",&A[i]);
	Fl=z=0;for(i=1;i<=k;i++) if(A[i]>=2*n) z+=A[i]/n,A[i]/n>=3&&(Fl=1);if(z>=m&&Fl){puts("Yes");return;}if(!Fl&&m%2==0&&z>=m){puts("Yes");return;}
	Fl=z=0;for(i=1;i<=k;i++) if(A[i]>=2*m) z+=A[i]/m,A[i]/m>=3&&(Fl=1);if(z>=n&&Fl){puts("Yes");return;}if(!Fl&&n%2==0&&z>=n){puts("Yes");return;} 
	puts("No");
}
int main(){
//	freopen("1.in","r",stdin);
	int T;scanf("%d",&T);while(T--) Solve();
}