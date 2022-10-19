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
#define N 400000
#define M 1000000
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
using namespace std;
int n,m,k,A[N+5],C[N+5],Ans,La[N+5],G[N+5],Fl[N+5],cnt;
struct Ques{int w,id;bool operator <(const Ques &B)const{return w<B.w;};}now;priority_queue<Ques> Q;
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d%d",&n,&k);for(i=1;i<=n;i++) scanf("%d",&A[i]);Me(G,0x3f);
	for(i=n;i;i--)La[i]=G[A[i]],G[A[i]]=i;Me(G,0x3f);for(i=1;i<=n;i++){
		if(Fl[A[i]]){G[A[i]]=La[i];Q.push((Ques){La[i],A[i]});Ans++;continue;}
		Fl[A[i]]=1;cnt++;if(cnt<=k){G[A[i]]=La[i];Q.push((Ques){La[i],A[i]}); continue;}now=Q.top();while(now.w^G[now.id]) Q.pop(),now=Q.top();Fl[now.id]=0;Q.pop();G[A[i]]=La[i];Q.push((Ques){La[i],A[i]});
	}printf("%d\n",n-Ans);
}