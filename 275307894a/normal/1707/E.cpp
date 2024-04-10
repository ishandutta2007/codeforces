#include<bits/stdc++.h>
#define I inline
#define ll long long
#define db double
#define lb long db
#define N (100000+5)
#define M ((1<<15)+5)
#define K (700+5)
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-5)
#define ui unsigned int
#define ull unsigned ll
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((k+1)*(x)+(y))
#define R(n) (rnd()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;
int n,m,A[N],lg[N],x,y,H;
struct Node{
	int L[N],R[N],Mx[N][20],Mi[N][20];I int Qi(int x,int y){int d=lg[y-x+1];return min(Mi[x][d],Mi[y-(1<<d)+1][d]);}I int Qx(int x,int y){int d=lg[y-x+1];return max(Mx[x][d],Mx[y-(1<<d)+1][d]);}
	I void BD(){int i,j;for(i=n-1;i;i--) for(Mx[i][0]=R[i],Mi[i][0]=L[i],j=1;i+(1<<j)-1<n;j++)Mx[i][j]=max(Mx[i][j-1],Mx[i+(1<<j-1)][j-1]),Mi[i][j]=min(Mi[i][j-1],Mi[i+(1<<j-1)][j-1]);}
}S[40];
int main(){
//	freopen("1.in","r",stdin);
	int i,j;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) scanf("%d",&A[i]);for(i=1;i<n;i++) lg[i+1]=lg[i+1>>1]+1,S[0].L[i]=min(A[i],A[i+1]),S[0].R[i]=max(A[i+1],A[i]);S[0].BD();cerr<<S[0].Qi(1,5)<<' '<<S[0].Qx(1,5)<<'\n';
	for(i=1;(1ll<<i)<=1ll*n*n;i++) {H=i;for(j=1;j<n;j++) S[i].L[j]=S[i-1].Qi(S[i-1].L[j],S[i-1].R[j]-1),S[i].R[j]=S[i-1].Qx(S[i-1].L[j],S[i-1].R[j]-1);S[i].BD();}
	while(m--) {
		scanf("%d%d",&x,&y);if(x==1&&y==n){puts("0");continue;}if(x==y){puts("-1");continue;}
		ll ToT=0;for(i=H;~i;i--) {int X=S[i].Qi(x,y-1),Y=S[i].Qx(x,y-1);if(X^1||Y^n) ToT+=(1ll<<i),x=X,y=Y;}if(ToT>1ll*n*n) puts("-1");else printf("%lld\n",ToT+(x^1||y^n));
	}
}