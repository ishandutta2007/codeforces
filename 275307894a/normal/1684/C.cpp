#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (300000+5)
#define M (100+5)
#define K (1500+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (1ll*rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;
int T,n,m,x,F1,F2,W[N],Id[N],Is;vector<int> S[N];
I void Solve(){
	int i,j;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) {S[i].clear();S[i].PB(0);for(j=1;j<=m;j++)scanf("%d",&x),S[i].PB(x);}
	for(i=1;i<=n;i++){Is=i;
		W[m+1]=1e9;for(j=m;j;j--) W[j]=min(W[j+1],S[i][j]);F1=F2=0;
		for(j=1;j<=m;j++) if(S[i][j]>W[j]){F1=j;F2=m;while(S[i][F2]>=S[i][F1]) F2--;break;}if(F1||F2) break;
	}
	for(i=1;i<=n;i++){
		swap(S[i][F1],S[i][F2]);for(j=2;j<=m;j++) if(S[i][j]<S[i][j-1]){puts("-1");return;}
	}
	if(!F1&&!F2){puts("1 1");return;}printf("%d %d\n",F1,F2);
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}