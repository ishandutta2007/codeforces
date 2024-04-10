// LUOGU_RID: 90445564
#include<bits/stdc++.h>
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((m)*(x-1)+(y))
#define R(n) (rnd()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using ll=long long;using db=double;using lb=long db;using ui=unsigned;using ull=unsigned ll;
using namespace std;const int N=1e4+5,M=2e3+5,K=2e3+5,mod=998244353,Mod=mod-1;const db eps=1e-5;const int INF=1e9+7;mt19937 rnd(time(0));
int n,m,k,x,y,z,f[N][M],A,B,D[N];ll Ans=1e18;
struct Node{int x,y,w;};deque<Node> Q;
int main(){
	int i,j;scanf("%d%d",&n,&m);for(i=1;i<=m;i++) scanf("%d",&D[i]);sort(D+1,D+m+1);Q.push_front((Node){1,0,0});Me(f,0x3f);f[1][0]=0;scanf("%d%d",&A,&B);
	while(!Q.empty()){
		Node x=Q.front();Q.pop_front();if(f[x.x][x.y]^x.w) continue;if(x.y==A&&f[x.x][0]>x.w+1)Q.push_back((Node){x.x,0,f[x.x][0]=x.w+1}); 
		if(x.x>1&&x.y+D[x.x]-D[x.x-1]<=A&&x.w<f[x.x-1][x.y+D[x.x]-D[x.x-1]]) Q.push_front((Node){x.x-1,x.y+D[x.x]-D[x.x-1],f[x.x-1][x.y+D[x.x]-D[x.x-1]]=x.w});
		if(x.x^m&&x.y+D[x.x+1]-D[x.x]<=A&&x.w<f[x.x+1][x.y+D[x.x+1]-D[x.x]])  Q.push_front((Node){x.x+1,x.y+D[x.x+1]-D[x.x],f[x.x+1][x.y+D[x.x+1]-D[x.x]]=x.w});
	}
	for(j=0;j<=A;j++) f[m][j]<1e9&&(Ans=min(Ans,1ll*(A+B)*f[m][j]+j));printf("%lld\n",Ans<1e18?Ans:-1);
}