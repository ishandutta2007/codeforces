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
using namespace std;map<int,int> F;
int A[N],n,m,k,Ts,P[N],H,l,r,ToT,x,cnt,C1;
struct Ques{int to,w;}S[N];I bool cmp(Ques x,Ques y){return x.w<y.w;} 
I void Solve(){
	int i,j;scanf("%d%d",&n,&k);cnt=n;F.clear();for(i=1;i<=n;i++) scanf("%d",&A[i]),A[i]>n&&(!F[A[i]]&&(F[A[i]]=++cnt),A[i]=F[A[i]]);
	for(i=0;i<=cnt;i++) P[i]=0;for(i=1;i<=n;i++) P[A[i]]++;ToT=n;C1=0;x=n-1;for(i=0;i<=n;i++){ToT-=P[i];C1+=(!P[i]);if(C1>k) {x=i-1;break;}}
	H=0;for(i=x+1;i<=cnt;i++)if(P[i]) S[++H]=(Ques){i,P[i]};sort(S+1,S+H+1,cmp);cnt=H;for(i=1;i<=H;i++) if(S[i].w<=k){k-=S[i].w;cnt--;}else break;printf("%d\n",cnt); 
}
int main(){
/////	freopen("1.in","r",stdin);
	scanf("%d",&Ts);while(Ts--) Solve();
}