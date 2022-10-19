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
#define N 2000
#define M N*N+5
#define mod 123456789
#define Mod (mod-1)
#define eps (1e-9)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound 
using namespace std;
int n,P[N+5],H,l,r,mid;ll m;
struct Node{ll x,y;Node operator -(const Node &B)const{return (Node){x-B.x,y-B.y};};}S[N+5],G[N+5];I bool C1(Node x,Node y){return x.x<y.x;}
struct Line{int x,y;Node L;}F[M+5];I bool C2(Line x,Line y){return x.L.x*y.L.y>x.L.y*y.L.x;}
I ll check(Node x,Node y){return x.x*y.y-x.y*y.x;}
int main(){
//	freopen("triangle.in","r",stdin);freopen("triangle.out","w",stdout);
	RI i,j;scanf("%d%lld",&n,&m);for(i=1;i<=n;i++) scanf("%lld%lld",&S[i].x,&S[i].y);sort(S+1,S+n+1,C1);memcpy(G,S,sizeof(G));
	for(i=1;i<=n;i++) for(P[i]=i,j=i+1;j<=n;j++) F[++H]=(Line){i,j,S[i]-S[j]};
	sort(F+1,F+H+1,C2);for(i=1;i<=H;i++){
		l=0;r=min(P[F[i].x],P[F[i].y]);while(l+1<r) mid=l+r>>1,(abs(check(F[i].L,G[mid]-S[F[i].y]))<=m*2?r:l)=mid;
		if(check(F[i].L,G[r]-S[F[i].y])==2*m) {puts("Yes");printf("%lld %lld \n%lld %lld\n%lld %lld\n",S[F[i].x].x,S[F[i].x].y,S[F[i].y].x,S[F[i].y].y,G[r].x,G[r].y);return 0;};
		swap(P[F[i].x],P[F[i].y]);swap(G[P[F[i].x]],G[P[F[i].y]]);
	}puts("No");
}