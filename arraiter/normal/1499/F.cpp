#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
  #define nc getchar()
  int x=0;char c=nc;bool f=0;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
const int maxn=5010,P=998244353;
int Inc(int x,int y){return x+y<P?x+y:x+y-P;}
int Dec(int x,int y){return x<y?x-y+P:x-y;}
void Add(int &x,int y){x+=y;if(x>=P)x-=P;}
void Sub(int &x,int y){x-=y;if(x<0)x+=P;}
int qp(int a,int k){int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;}
int n,k;vi E[maxn];

int dp[maxn][maxn];
void dfs(int u,int f){
  for(int v:E[u])if(v!=f)dfs(v,u);
  static int G[2][maxn],tag[maxn],pre[maxn];int sel=0;
  memset(G,0,sizeof G),G[0][0]=1;
  for(int v:E[u])if(v!=f){
    memset(tag,0,sizeof tag);
    memcpy(pre,dp[v],sizeof pre);
    memset(G[sel^1],0,sizeof G[sel^1]);
    rep(i,1,k)Add(pre[i],pre[i-1]);
    int su=0;
    rep(i,0,k){
      Add(su,dp[v][i]);
      int x=G[sel][i];
      if(!x)continue;
      int p=k-i-1;
      int tr=min(p,i-1);
      if(tr>=0)Add(G[sel^1][i],1ll*x*pre[tr]%P);
      if(i<=p)Add(tag[i+1],x),Add(tag[p+2],(P-x)%P);
      
//      rep(j,0,min(k-i-1,i-1)){
//        int tp=1ll*x*dp[v][j]%P;
//        Add(G[sel^1][i],tp);
//      }
//      rep(j,i,k-i-1){
//        int tp=1ll*x*dp[v][j]%P;
//        Add(G[sel^1][j+1],tp);
//      }

//      rep(j,0,k-i-1){
//        int tp=1ll*x*dp[v][j]%P;
//        Add(G[sel^1][max(i,j+1)],tp);
//      }
//      rep(j,0,k){
//        int tp=1ll*x*dp[v][j]%P;
//        Add(G[sel^1][i],tp);
//      }
    }
    rep(i,0,k){
      if(i)Add(tag[i],tag[i-1]),Add(G[sel^1][i],1ll*tag[i]*dp[v][i-1]%P);
      Add(G[sel^1][i],1ll*su*G[sel][i]%P);
    }
    sel^=1;
  }
  memcpy(dp[u],G[sel],sizeof dp[u]);
//  printf("###%d\n",u);
//  rep(i,0,k)printf("(%d) : %d\n",i,dp[u][i]);
}

void solve(){
  cin>>n>>k;
  rep(i,2,n){
    int u=read(),v=read();E[u].push_back(v),E[v].push_back(u);
  }
  dfs(1,0);
  int ans=0;rep(i,0,k)Add(ans,dp[1][i]);
  cout<<ans<<endl;
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}