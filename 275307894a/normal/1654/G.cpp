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
#define N (200000+5)
#define M ((1<<19)+5)
#define mod 998244353
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
using namespace std;vector<int> S[N],P[N];
int n,m,k,H[N],F[N],x,y,G[N];queue<int> Q;
int main(){
//	freopen("1.in","r",stdin);
	Me(H,0x3f);RI i,j;scanf("%d",&n);for(i=1;i<=n;i++)scanf("%d",&x),x&&(H[i]=0,Q.push(i),0);for(i=1;i<n;i++)scanf("%d%d",&x,&y),S[x].PB(y),S[y].PB(x);
	while(!Q.empty()){x=Q.front();Q.pop();for(RI i:S[x]) H[i]>H[x]+1&&(H[i]=H[x]+1,Q.push(i),0);};for(i=1;i<=n;i++) for(RI j:S[i]) if(H[i]==H[j]){P[H[i]].PB(i);break;}
	Mc(F,H);for(i=0;i<=n;i++) {
		if(!P[i].size()) continue;Me(G,-0x3f);for(RI j:P[i]) G[j]=0,Q.push(j);
		while(!Q.empty()) {x=Q.front();Q.pop();for(RI j:S[x]) H[j]>=H[x]&&G[j]<min(G[x],0)+(H[j]>H[x]?1:-1)&&(G[j]=min(G[x],0)+(H[j]>H[x]?1:-1),Q.push(j),0);};
		for(j=1;j<=n;j++) G[j]>=0&&(F[j]=min(F[j],i));
	}for(i=1;i<=n;i++) printf("%d ",2*H[i]-F[i]);
}