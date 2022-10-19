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
#define N (1<<19)+5
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
int n,m,k,G[20][N],x,Mx[N],Mi[N],Gx[N],Gi[N];
int main(){
//	freopen("1.in","r",stdin);
	RI i,j,d;scanf("%d%d",&n,&k);m=(1<<k);Me(Mx,-0x3f);Me(Mi,0x3f);for(i=1;i<=n;i++) scanf("%d",&x),Mx[x]=Mi[x]=0;Me(G,0x3f);
	for(d=0;d<k;d++){
		Mc(Gx,Mx);Mc(Gi,Mi);for(i=0;i<m;i+=(1<<d+1)){
			for(j=0;j<(1<<d+1);j++) G[d][j]=min(G[d][j],(1<<d)+Gi[i+j^(1<<d)]-Gx[i+j]);
			for(j=0;j<(1<<d+1);j++) Mx[i+j]=max(Gx[i+j],Gx[i+j^(1<<d)]|(1<<d)),Mi[i+j]=min(Mi[i+j],Mi[i+j^(1<<d)]|(1<<d));
		}
	}
	for(i=0;i<m;i++) {x=1e9;for(j=0;j<k;j++) x=min(x,G[j][i&((1<<j+1)-1)]);printf("%d ",x);}
}