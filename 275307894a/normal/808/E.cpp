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
#define M 10
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-3)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int n,m,k,x,y,H[4];ll Q[4][N+5],ToT;
I void Solve(int x,int y,int l,int r){
	if(x>y) return;int m=x+y>>1,p=l;ll Ans=0;for(RI i=l;i<=r;i++) 3*m+i*2<=k&&Q[3][m]+Q[2][i]+Q[1][min((k-3*m-2*i),H[1])]>Ans&&(p=i,Ans=Q[3][m]+Q[2][i]+Q[1][min((k-3*m-2*i),H[1])]);
	/*printf("%d %d %d %d %d %lld\n",x,y,l,r,p,Ans);*/ToT=max(ToT,Ans);Solve(x,m-1,p,r);Solve(m+1,y,l,p);
}
int main(){
//	freopen("1.in","r",stdin);
	RI i,j;scanf("%d%d",&n,&k);for(i=1;i<=n;i++) scanf("%d%d",&x,&y),Q[x][++H[x]]=y;for(i=1;i<=3;i++) for(sort(Q[i]+1,Q[i]+H[i]+1),reverse(Q[i]+1,Q[i]+H[i]+1),j=1;j<=H[i];j++) Q[i][j]+=Q[i][j-1];
	Solve(0,H[3],0,H[2]);printf("%lld\n",ToT);
}