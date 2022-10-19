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
int n,m,k,T,A[N],Fl[N];ll ToT,cnt;
struct Ques{int w,id;}S[N];I bool cmp(Ques x,Ques y){return x.w>y.w;}
I void Solve(){
	Me(Fl,0);int i,j;scanf("%d%d",&n,&k);for(i=1;i<=n;i++) scanf("%d",&A[i]),S[i]=(Ques){A[i]-(n-i),i};sort(S+1,S+n+1,cmp);
	for(i=1;i<=k;i++) Fl[S[i].id]=1;ToT=0;cnt=0;for(i=1;i<=n;i++) Fl[i]?(cnt++):(ToT+=A[i]+cnt);printf("%lld\n",ToT);
}
int main(){
//////	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}