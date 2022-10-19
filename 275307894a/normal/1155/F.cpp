#include<bits/stdc++.h>
#define I inline
#define ll long long
#define db double
#define lb long db
#define N (14+5)
#define M ((1<<14)+5)
#define K (700+5)
#define mod 64123
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
int n,m,k,x,y,z,lg[M],g[N][N][M],f[M],L1[M],L3[M],L4[M],H[M],L2[N][N][M],W[N];
I void DP(int i,int j){if(f[i]<=f[i^j]+H[j]+1) return;
	for(int h=1;h<=n;h++) if(j>>(h-1)&1&&H[(i^j)&W[h]]>(H[j]^1?0:1)) for(k=1;k<=n;k++) if(j>>(k-1)&1&&H[(i^j)&W[k]]>(H[j]^1?0:1)&&g[h][k][j]){f[i]=f[i^j]+H[j]+1,L1[i]=j,L3[i]=h,L4[i]=k;return;} 
}
I void GA(int Is,int x,int y,int z){
	if(H[x]==1) y=W[y]&Is,printf("%d %d\n",z,lg[y]+1),y^=(1<<lg[y]),printf("%d %d\n",z,lg[y]+1);
	else {int Lp;printf("%d %d\n%d %d\n",y,lg[W[y]&Is]+1,z,lg[W[z]&Is]+1);while(H[x]^1) printf("%d %d\n",z,L2[y][z][x]),Lp=z,z=L2[y][z][x],x^=1<<Lp-1;}
}
int main(){
//	freopen("1.in","r",stdin);
	int i,j,h,k;scanf("%d%d",&n,&m);for(i=1;i<=m;i++) scanf("%d%d",&x,&y),W[x]|=1<<y-1,W[y]|=1<<x-1;for(i=1;i<(1<<n);i++) H[i]=H[i>>1]+(i&1);
	for(i=2;i<(1<<n);i++) lg[i]=lg[i/2]+1;for(i=1;i<=n;i++) g[i][i][1<<i-1]=1;for(i=1;i<(1<<n);i++){
		for(j=1;j<=n;j++)if(i>>(j-1)&1) for(h=1;h<=n;h++) if(i>>(h-1)&1){
			for(k=1;k<=n;k++) if(i>>(k-1)&1&&g[j][k][i^(1<<h-1)]&&W[k]>>(h-1)&1){g[j][h][i]=1,L2[j][h][i]=k;break;}
		}
	}Me(f,0x3f);for(i=1;i<=n;i++) f[1<<i-1]=0;for(i=1;i<(1<<n);i++)for(j=i-1;j;j=(j-1)&i)DP(i,j);
	printf("%d\n",f[x=(1<<n)-1]);while(H[x]^1) GA(x^L1[x],L1[x],L3[x],L4[x]),x^=L1[x];
}