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
#define N 500000
#define M 10
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int x,y,n,m,Q[N+5],fa[N+5][22],Ans;
int main(){
//	freopen("1.in","r",stdin);
	RI i,j;scanf("%d%d",&n,&m);while(n--) scanf("%d%d",&x,&y),Q[x]=max(Q[x],y);
	for(i=1;i<=N;i++) Q[i]=max(Q[i-1],max(Q[i],i));
	for(i=N;~i;i--)for(fa[i][0]=Q[i],j=1;j<=20;j++) fa[i][j]=fa[fa[i][j-1]][j-1];
	while(m--){scanf("%d%d",&x,&y);Ans=0;for(i=20;~i;i--) fa[x][i]<y&&(x=fa[x][i],Ans+=(1<<i));printf("%d\n",fa[x][0]>=y?Ans+1:-1);}
}