#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (200000+5)
#define M (10+5)
#define K (3000000+5)
#define mod 1000000007
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
using namespace std;
int n,m,x,y,z,Ans,k,F[N][20],G[N][20];
int main(){
	//freopen("1.in","r",stdin);
	int i,j;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) scanf("%d",&x),G[x][0]^=1;
	for(i=m;i;i--){
		for(j=1;i+(1<<j)-1<=m;j++) G[i][j]=G[i][j-1]+G[i+(1<<j-1)][j-1],F[i][j]=F[i][j-1]^F[i+(1<<j-1)][j-1]^(G[i+(1<<j-1)][j-1]&1?(1<<j-1):0);
	}scanf("%d",&k);while(k--){Ans=0;scanf("%d%d",&x,&y);z=x;for(i=19;~i;i--) x+(1<<i)<=y+1&&(Ans=Ans^F[x][i]^(G[x][i]&1?x-z:0),x+=(1<<i));Pc(Ans?'A':'B');}
}