#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (1000+5)
#define M (100+5)
#define K (1500+5)
#define mod 998244353
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
using namespace std;queue<int> Q;
int n,m,k,x,y,z,cnt,A[N],d[N],S,T,ToT,Ns[N],X[N],Y[N],H;
struct yyy{int to,w,z;}tmp;struct ljb{int head=1,h[N];yyy f[N*N];I void add(int x,int y,int z){f[++head]=(yyy){y,z,h[x]};h[x]=head;}}s;
I void Ins(int x,int y,int z){/*cerr<<x<<' '<<y<<'\n';*/s.add(x,y,z);s.add(y,x,0);}
I int BFS(){
	int i;Q.push(S);Me(d,0x3f);Mc(Ns,s.h);d[S]=0;while(!Q.empty()) for(x=Q.front(),Q.pop(),cnt++,i=s.h[x];i;i=tmp.z){tmp=s.f[i];/*cerr<<tmp.to<<' '<<tmp.w<<'\n';*/if(!tmp.w||d[tmp.to]<=d[x]+1) continue;d[tmp.to]=d[x]+1;Q.push(tmp.to);}return d[T]<=1e9;
}
I int DFS(int x,int Sum){
	if(x==T)return Sum;yyy tmp;int k,pus=0;for(int i=Ns[x];i;i=tmp.z){Ns[x]=i;
		tmp=s.f[i];if(!tmp.w||d[tmp.to]!=d[x]+1) continue;k=DFS(tmp.to,min(tmp.w,Sum));if(!k) d[tmp.to]=1e9+1;s.f[i].w-=k;s.f[i^1].w+=k;Sum-=k;pus+=k;if(!Sum) break;
	}Ns[x]=0;return pus;
}
int main(){
//r/////eopen("1.in","r",stdin);freopen("1.out","w",stdout);
	int i,j;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) scanf("%d",&A[i]);S=0;T=n+1;for(i=1;i<=n;i++) A[i]<=m/3?Ins(S,i,1):(ToT++,Ins(i,T,1));
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) A[i]>m/3&&A[j]<=m/3&&A[i]%A[j]==0&&A[i]*2ll+A[j]<=m&&(Ins(j,i,1),0);
	while(BFS()) ToT-=DFS(S,1e9)/*,cerr<<ToT<<'\n'*/;if(ToT){puts("-1");return 0;}for(i=s.h[S];i;i=tmp.z) {tmp=s.f[i];if(tmp.w) X[++H]=2*A[tmp.to],Y[H]=3*A[tmp.to];}
	for(i=1;i<=n;i++){if(A[i]<=m/3) continue;for(int j=s.h[i];j;j=tmp.z){tmp=s.f[j];if(tmp.to==T) continue;if(tmp.w) X[++H]=2*A[i]+A[tmp.to],Y[H]=A[i]+A[tmp.to];}}
	printf("%d\n",H);while(H--) printf("%d %d\n",X[H+1],Y[H+1]);
}