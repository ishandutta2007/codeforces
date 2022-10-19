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
#define M 10
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int T,n,m;ll Ans,Ts[N+5];
struct Ques{int id,w;}S[N+5];I bool cmp(Ques x,Ques y){return x.w>y.w;}
I void Solve(){
	scanf("%d",&n);Ans=0;RI i;for(i=1;i<=n;i++) scanf("%d",&S[i].w),S[i].id=i;sort(S+1,S+n+1,cmp);
	for(i=1;i<=n;i++) Ts[S[i].id]=(i+1)/2*(i&1?1:-1),Ans+=1ll*S[i].w*(i+1>>1);printf("%lld\n",Ans*2);for(i=0;i<=n;i++) printf("%d ",Ts[i]);Pc('\n');
}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d",&T);while(T--) Solve();
}