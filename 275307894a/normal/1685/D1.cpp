#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (200+5)
#define M (30000+5)
#define K (6)
#define mod 1000000007
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
int T,n,H,x,A[N],B[N],C[N],fa[N];I int GF(int x){return fa[x]^x?fa[x]=GF(fa[x]):x;} 
struct Ques{int x,id;}S[N];I bool cmp(Ques x,Ques y){return x.x<y.x;}
I void Solve(){
	int i,j;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]),B[i]=A[i],fa[i]=i,S[i]=(Ques){A[i],i};
	for(i=1;i<=n;i++) fa[GF(i)]=GF(A[i]);sort(S+1,S+n+1,cmp);for(i=2;i<=n;i++) GF(S[i].id)^GF(S[i-1].id)&&(swap(B[S[i].id],B[S[i-1].id]),fa[GF(S[i].id)]=GF(S[i-1].id));
	C[H=1]=1;x=B[1];while(x^1) C[++H]=x,x=B[x];for(i=H;i;i--) printf("%d ",C[i]);Pc('\n');
}
int main(){
////	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}