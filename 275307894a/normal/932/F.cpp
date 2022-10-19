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
#define N 100000
#define M N*N+5
#define mod 1000000007
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
using namespace std;vector<int> S[N+5];
int n,m,k,A[N+5],cnt,B[N+5],x,y,Ro[N+5];ll dp[N+5];const int INF=1e5;
struct Line{ll k,b;I ll calc(int x){return x*k+b;}};
namespace Tree{
	Line F[N+5<<5];int R[N+5<<5],L[N+5<<5];I void Ins(Line x,int &now,int l=-INF,int r=INF){
		if(!now) {now=++cnt;F[now]=x;return;}if(F[now].calc(l)>=x.calc(l)&&F[now].calc(r)>=x.calc(r)) {F[now]=x;return;}if(l==r) return;if(F[now].calc(l)<=x.calc(l)&&F[now].calc(r)<=x.calc(r))return;
		int m=l+r>>1;F[now].calc(m)>=x.calc(m)?(F[now].calc(l)>=x.calc(l)?Ins(F[now],R[now],m+1,r):Ins(F[now],L[now],l,m),F[now]=x,0):(F[now].calc(l)>=x.calc(l)?Ins(x,L[now],l,m):Ins(x,R[now],m+1,r),0);
	}
	I int ME(int x,int y,int l=-INF,int r=INF){if(!x||!y) return x|y;Ins(F[y],x,l,r);if(l==r) return x;int m=l+r>>1;L[x]=ME(L[x],L[y],l,m);R[x]=ME(R[x],R[y],m+1,r);return x;}
	I ll Qry(int x,int now,int l=-INF,int r=INF){if(!now) return 1e18;int m=l+r>>1;ll Fs=(x<=m?Qry(x,L[now],l,m):Qry(x,R[now],m+1,r));return min(Fs,F[now].calc(x));}
}
I void dfs(int x,int La){int Fl=0;for(RI i:S[x]) i^La&&(dfs(i,x),Ro[x]=Tree::ME(Ro[x],Ro[i]),Fl=1);dp[x]=Fl*Tree::Qry(A[x],Ro[x]);Tree::Ins((Line){B[x],dp[x]},Ro[x]);}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]);for(i=1;i<=n;i++) scanf("%d",&B[i]);for(i=1;i<n;i++)scanf("%d%d",&x,&y),S[x].push_back(y),S[y].push_back(x);dfs(1,0);for(i=1;i<=n;i++) printf("%lld ",dp[i]);
}