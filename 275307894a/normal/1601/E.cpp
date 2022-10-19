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
#define N (300000+5)
#define M (N*50+5)
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
#define PB push_back
using namespace std;
int n,m,k,x,y,A[N+5],W[N+5],Q[N+5],H,T,Bh,B[N+5],C[N+5];ll P[N+5],Ans[N+5];
struct Ques{int y,id;};vector<Ques> S[N+5];
int main(){
//	freopen("1.in","r",stdin);
	RI i,j,h;scanf("%d%d%d",&n,&m,&k);for(i=1;i<=n;i++) scanf("%d",&A[i]);for(i=1;i<=m;i++) scanf("%d%d",&x,&y),Ans[i]=A[x],(y-x)/k&&(S[x].PB((Ques){(y-x)/k-1,i}),0);
	H=1;T=0;for(i=n;i;i--) {
		while(H<=T&&Q[H]-k>i) H++;while(H<=T&&A[Q[T]]>A[i]) T--;Q[++T]=i;W[i]=A[Q[H]]; 
	}
	for(i=0;i<k;i++){
		Bh=0;for(j=(i?i:k);j<=n;j+=k) B[++Bh]=j,C[Bh]=W[j];reverse(B+1,B+Bh+1);reverse(C+1,C+Bh+1);
		Q[H=0]=0;for(j=1;j<=Bh;j++){
			while(H&&C[j]<=C[Q[H]]) H--;Q[++H]=j;P[H]=P[H-1]+1ll*C[j]*(Q[H]-Q[H-1]);
			for(Ques d:S[B[j]]) h=LB(Q,Q+H+1,j-d.y)-Q,Ans[d.id]+=P[H]-P[h]+1ll*(Q[h]-(j-d.y)+1)*C[Q[h]];
		}
	}for(i=1;i<=m;i++) printf("%lld\n",Ans[i]);
}