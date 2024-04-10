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
#define N 500
#define M 5
#define mod 1000000007
#define Mod 998244352
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
using namespace std;
int n,m,Ans,A[N+5][N+5],F[N+5][N+5],ToT,Fl[N+5][N+5],S,T,d[N+5<<1],nows[N+5<<1],x;char C[N+5];
struct yyy{int to,w,z;}tmp;struct ljb{int head,h[N+5<<1];yyy f[N*N+5<<1];I void add(int x,int y,int z){f[head]=(yyy){y,z,h[x]};h[x]=head++;}}s;
I void Get(int x,int y,int z){s.add(x,y,z),s.add(y,x,0);}queue<int> Q;
I int bfs(){
	RI i;while(!Q.empty()) Q.pop();Q.push(S);Me(d,0x3f);Me(nows,-1);d[S]=0;nows[S]=s.h[S];
	while(!Q.empty())for(x=Q.front(),Q.pop(),i=s.h[x];~i;i=tmp.z){
		tmp=s.f[i];if(!tmp.w||d[tmp.to]<1e9)continue;d[tmp.to]=d[x]+1;Q.push(tmp.to);nows[tmp.to]=s.h[tmp.to];if(tmp.to==T)return 1;
	} return 0;
}
I int dfs(int x,int sum){
	if(x==T) return sum;yyy tmp;int i,pus=0,k;for(i=nows[x];~i;i=tmp.z){
		tmp=s.f[i];nows[x]=i;if(!tmp.w||d[tmp.to]!=d[x]+1) continue;k=dfs(tmp.to,min(sum,tmp.w));if(!k) d[tmp.to]=1e9;s.f[i].w-=k;s.f[i^1].w+=k;pus+=k;sum-=k;if(!sum) break;
	}return pus;
}
int main(){
//	freopen("1.in","r",stdin);
	Me(s.h,-1);RI i,j;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) for(scanf("%s",C+1),j=1;j<=m;j++) A[i][j]=(C[j]=='W'?0:1);
	for(i=n;i;i--){
		for(j=m;j;j--){
			if(A[i][j]^F[i][j])F[i][j]^=1,Ans++,Fl[i][j]=1;//printf("%d %d %d\n",i,j,Ans);
			F[i][j]&&(F[i-1][j]^=1,F[i][j-1]^=1,F[i-1][j-1]^=1);
		}
	}T=n+m+1;for(i=1;i<n;i++) Fl[i][m]&&(Get(S,i,1),0);for(i=1;i<m;i++) Fl[n][i]&&(Get(i+n,T,1),0);
	for(i=1;i<n;i++) for(j=1;j<m;j++) if(Fl[i][m]&&Fl[n][j]&&Fl[i][j])Get(i,j+n,1);
	while(bfs()) ToT+=dfs(S,1e9);if(Fl[n][m]&&ToT) ToT--,Ans-=2;printf("%d\n",Ans-ToT/2*2);
}