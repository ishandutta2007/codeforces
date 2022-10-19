#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (200000+5)
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
using namespace std;map<int,int> F;vector<int> Id[N];vector<int>::it Ps;
int T,n,m,k,x,y,z1,z2,R,A[N],La[N],Pa[N],Fl[N],cnt,F1[N][20],F2[N][20],lg[N],W[N],Ans,Mx;
I int Q1(int x,int y){int d=lg[y-x+1];return min(F1[x][d],F1[y-(1<<d)+1][d]);}
I int Q2(int x,int y){int d=lg[y-x+1];return max(F2[x][d],F2[y-(1<<d)+1][d]);}
I void Solve(){
	int i,j;scanf("%d%d",&n,&m);for(i=2;i<=n;i++) lg[i]=lg[i/2]+1;cnt=0;F.clear();for(i=1;i<=n;i++) Id[i].clear(),scanf("%d",&A[i]),!F[A[i]]&&(F[A[i]]=++cnt),Id[A[i]=F[A[i]]].PB(i);
	Me(Fl,0x3f);for(i=n;i;i--) La[i]=Fl[A[i]],Fl[A[i]]=i;for(i=n;i;i--) for(F1[i][0]=La[i],j=1;i+(1<<j)-1<=n;j++) F1[i][j]=min(F1[i][j-1],F1[i+(1<<j-1)][j-1]);
	Me(Fl,-0x3f);for(i=1;i<=n;i++) Pa[i]=Fl[A[i]],Fl[A[i]]=i;for(i=n;i;i--) for(F2[i][0]=Pa[i],j=1;i+(1<<j)-1<=n;j++) F2[i][j]=max(F2[i][j-1],F2[i+(1<<(j-1))][j-1]);
	for(i=1;i<=n;i++) W[i]=i;R=0;Mx=n+1;for(i=1;i<=m;i++) scanf("%d%d",&x,&y),z1=Q1(x,y),z2=Q2(x,y),z1<=y&&(R=max(R,z2),Mx=min(Mx,z1),W[x]=max(W[x],y));Ans=1e9;
	for(i=1;i<=min(Mx,n);i++){
	R=max(R,i-1);W[i]=max(W[i],W[i-1]);Ans=min(Ans,R-i+1);/*cerr<<Ans<<'\n';*/Ps=UB(Id[A[i]].begin(),Id[A[i]].end(),W[i]);Ps--;if((*Ps)^i||i==Mx) R=max(R,*Ps);} printf("%d\n",Ans);
}
int main(){
//	freopen("1.in","r",stdin);
	int i,j;scanf("%d",&T);while(T--) Solve();
}