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
#define N (150000+5)
#define M (1000000+5)
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
int n,m,k,A[N+5],Fl[M+5],pr[M+5],B[45],Bh,x,ph,y,La[M+5],fa[M+5];vector<int> G[M+5];map<int,int> F[M+5];
I int GF(int x){return fa[x]^x?fa[x]=GF(fa[x]):x;}I int ME(int x,int y){fa[GF(x)]=GF(y);}
I void calc(int x){RI i,j;Bh=0;y=x;while(y^1) B[++Bh]=GF(La[y]),y/=La[y];y=x+1;while(y^1) B[++Bh]=GF(La[y]),y/=La[y];sort(B+1,B+Bh+1);Bh=unique(B+1,B+Bh+1)-B-1;for(i=1;i<=Bh;i++) for(j=i+1;j<=Bh;j++) F[GF(B[i])][GF(B[j])]=1; }
int main(){
//	freopen("1.in","r",stdin);
	RI i,j;scanf("%d%d",&n,&m);for(i=2;i<=M;i++){
		!Fl[i]&&(pr[++ph]=i,La[i]=i,fa[i]=i);for(j=1;j<=ph&&i*pr[j]<=M;j++) {Fl[i*pr[j]]=1;La[i*pr[j]]=pr[j];if(i%pr[j]==0) break;}
	}for(i=1;i<=n;i++){scanf("%d",&A[i]);x=A[i];y=La[x];x/=y;while(x^1) ME(La[x],y),x/=La[x];}
	for(i=1;i<=n;i++) calc(A[i]);while(m--) scanf("%d%d",&x,&y),x=GF(La[A[x]]),y=GF(La[A[y]]),printf("%d\n",x^y?(2-(F[x].count(y)||F[y].count(x))):0);
}