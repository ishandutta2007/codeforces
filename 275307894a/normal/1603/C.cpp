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
#define M (N*50+5)
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
int n,A[N+5],T,La,Ne,P,x,y,Maxn,H;ll Ans,ToT;
struct Pa{int id,w;};vector<Pa> S[2];
I void Solve(){
	RI i,j,h;S[0].clear();S[1].clear();
	Ans=0;Maxn=0;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]),Maxn=max(Maxn,A[i]+1);
	for(i=n;i;i--){
		Ne=i&1;La=Ne^1;x=A[i]-1;S[Ne].clear();H=0;
		for(j=1;j<=x;j=h+1){
			h=x/(x/j),P=x/j;
			y=0;while(H<S[La].size()&&S[La][H].id<=h) y+=S[La][H].w,H++;
			Ans+=1ll*P*y%mod*i%mod;S[Ne].push_back((Pa){A[i]/(P+1),y});
		} 
		j=x+1;h=Maxn;P=x/j;y=0;while(H<S[La].size()&&S[La][H].id<=h) y+=S[La][H].w,H++;
		Ans+=1ll*P*y%mod*i%mod;S[Ne].push_back((Pa){A[i]/(P+1),y});
		S[Ne].PB((Pa){A[i],1});
	}printf("%lld\n",Ans%mod);
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--)Solve();
}