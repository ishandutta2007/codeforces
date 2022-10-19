#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (1000+5)
#define M (100+5)
#define K (1000+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
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
using namespace std;vector<int> S[N];
int n,m,k,x,y,Dp[N],Si[N],fa[N],Bh,C1,C2,Ps,W[N];
I void dfs(int x,int La){fa[x]=La;Si[x]=1;for(int i:S[x]) i^La&&(dfs(i,x),Si[x]+=Si[i],Dp[x]=max(Dp[x],Si[i]));Dp[x]=max(Dp[x],n-Si[x]);}
struct Ques{int w,id;}B[N];I bool cmp(Ques x,Ques y){return x.w<y.w;}
I void Make1(int x,int La){W[x]=++C1;printf("%d %d %d\n",x,La,W[x]-W[La]);for(int i:S[x]) i^La&&(Make1(i,x),0);}
I void Make2(int x,int La){W[x]=(C2+=Ps);printf("%d %d %d\n",x,La,W[x]-W[La]);for(int i:S[x]) i^La&&(Make2(i,x),0);}
I void calc(int x){
	for(int i:S[x]) B[++Bh]=(Ques){Si[i]>Si[x]?n-Si[x]:Si[i],i};sort(B+1,B+Bh+1,cmp);
	for(int i=Bh;i;i--)if(Ps<=n/3) Ps+=B[i].w,Make1(B[i].id,x);else Make2(B[i].id,x);exit(0);
}
int main(){
//	freopen("1.in","r",stdin);
	int i;scanf("%d",&n);for(i=1;i<n;i++) scanf("%d%d",&x,&y),S[x].PB(y),S[y].PB(x);
	dfs(1,0);for(i=1;i<=n;i++) if(Dp[i]<=n/2) calc(i);
}