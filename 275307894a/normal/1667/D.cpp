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
#define K (1000+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
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
using namespace std;queue<int> Q;
int n,T,In[N],X[N],Y[N],x,y,B[N],C[N],Bh,Ch,Fl[N],Fs,W[N],Is[N];struct Edge{int to,w;};vector<Edge> S[N];vector<int> P[N];
I void dfs(int x,int La){if(Fs) return;Fl[x]=(In[x]+1)/2;for(Edge i:S[x]) i.to^La&&(dfs(i.to,x),Fl[x]-=Fl[i.to],W[i.w]=Fl[i.to]);if(Fl[x]<0||Fl[x]>1) Fs=1;}
I void Solve(){
	int i,j;scanf("%d",&n);for(i=1;i<=n;i++) S[i].clear(),P[i].clear(),In[i]=Is[i]=0;for(i=1;i<n;i++) scanf("%d%d",&X[i],&Y[i]),S[X[i]].PB((Edge){Y[i],i}),S[Y[i]].PB((Edge){X[i],i}),In[X[i]]++,In[Y[i]]++;
	Fs=0;dfs(1,0);if(Fs||Fl[1]){puts("NO");return;}puts("YES");for(i=1;i<=n;i++){
		Ch=Bh=0;for(Edge j:S[i]) W[j.w]?(C[++Ch]=j.w):(B[++Bh]=j.w);for(j=1;Bh&&Ch;j++) (j+In[i]+1)&1?(P[C[Ch]].PB(B[Bh]),Is[B[Bh]]++,Ch--,0):(P[B[Bh]].PB(C[Ch]),Is[C[Ch]]++,Bh--);
	}for(i=1;i<n;i++) !Is[i]&&(Q.push(i),0);while(!Q.empty()){x=Q.front();Q.pop();printf("%d %d\n",X[x],Y[x]);for(int i:P[x]) Is[i]--,!Is[i]&&(Q.push(i),0);}
}
int main(){
//////	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}