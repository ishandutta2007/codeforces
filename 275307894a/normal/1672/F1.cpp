#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (200000+5)
#define M ((1<<16)+5)
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
using namespace std;
int n,T,A[N],Fs[N],C[N],R,H;vector<int> S1[N];
struct Ques{int id,w;}Q[N],B[N];I bool cmp(Ques x,Ques y){return x.w<y.w;}
I void Solve(){
	int i;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]);for(i=1;i<=n;i++) Fs[i]=0,S1[i].clear();
	H=0;for(i=1;i<=n;i++) Fs[A[i]]++,S1[A[i]].PB(i);for(i=1;i<=n;i++) A[i]&&(Q[++H]=(Ques){i,Fs[i]},0);sort(Q+1,Q+H+1,cmp);
	for(i=1;i<=H;i++) B[i]=Q[i];B[0]=B[H];R=H-1;for(i=H;i;i--){
		while(1){
			while(Q[i].w&&B[R].w) C[S1[Q[i].id][Q[i].w-1]]=B[R].id,Q[i].w--,B[R].w--;
			if(!Q[i].w) break;R--;
		}
	}for(i=1;i<=n;i++) printf("%d ",C[i]);Pc('\n');
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--)Solve();
}