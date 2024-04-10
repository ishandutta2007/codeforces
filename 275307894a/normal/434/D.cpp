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
using namespace std;const int N=1e4+5,M=N*10+5,K=1e5+5,mod=998244353,Mod=mod-1;const db eps=1e-5;
int n,m,k,x,y,z,d[N],Ns[N],A[N],B[N],C[N],S,T,Ts[N],R[N],L[N];ll Ans;const ll INF=1e15;
struct yyy{int to;ll w;int z;};struct ljb{int head=1,h[N];yyy f[M];void add(int x,int y,ll z){f[++head]=(yyy){y,z,h[x]};h[x]=head;}}s;void con(int x,int y,ll z){s.add(x,y,z);s.add(y,x,0);}
queue<int> Q;int BFS(){
	yyy tmp;int i;while(!Q.empty()) Q.pop();Q.push(S);Me(d,0x3f);d[S]=0;Ns[S]=s.h[S];while(!Q.empty()) for(x=Q.front(),Q.pop(),i=s.h[x];i;i=tmp.z){
		tmp=s.f[i];if(!tmp.w||d[tmp.to]<1e9) continue;d[tmp.to]=d[x]+1;Ns[tmp.to]=s.h[tmp.to];Q.push(tmp.to);if(tmp.to==T) return 1; 
	}return 0;
}
ll DFS(int x,ll Sum){
	if(x==T)return Sum;int i;ll pus=0,k;yyy tmp;for(i=Ns[x];i;i=tmp.z){
		Ns[x]=i;tmp=s.f[i];if(!tmp.w||d[tmp.to]!=d[x]+1) continue;k=DFS(tmp.to,min(tmp.w,Sum));if(!k) d[tmp.to]=1e9;Sum-=k;pus+=k;s.f[i].w-=k;s.f[i^1].w+=k;if(!Sum) break;
	}return pus; 
}
int main(){
//	freopen("1.in","r",stdin);
	int i,j;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) scanf("%d%d%d",&A[i],&B[i],&C[i]);for(i=1;i<=n;i++) scanf("%d%d",&L[i],&R[i]),L[i]--,T+=R[i]-L[i]+1;T++;
	S=0;for(i=1;i<=n;i++) for(Ts[i]=Ts[i-1]+R[i]-L[i]+1,con(Ts[i],T,INF*100),j=L[i];j<=R[i];j++) con((j==L[i]?S:Ts[i-1]+j-L[i]),Ts[i-1]+j-L[i]+1,(j==L[i]?INF*100:INF-A[i]*j*j-B[i]*j-C[i]));
	while(m--) for(scanf("%d%d%d",&x,&y,&z),j=L[x];j<=R[x];j++) j-z<=R[y]&&(con(Ts[x-1]+j-L[x]+1,Ts[y-1]+max(j-z,L[y])-L[y]+1,INF*100),0);
	while(BFS()) Ans+=DFS(S,INF*100),cerr<<Ans<<'\n';printf("%lld\n",INF*n-Ans);
}