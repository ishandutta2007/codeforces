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
const int maxn=1e5+10;
int n,k,A[maxn],val[maxn][40],val2[maxn][40],ans[maxn];vi E[maxn];

void dfs(int u,int f){
  val[u][0]=A[u];
  for(int v:E[u])if(v!=f){
    dfs(v,u);
    rep(i,0,k-1)val[u][i]^=val[v][(i+k-1)%k];
  }
}
void dfs2(int u,int f){
  rep(i,k/2,k-1)ans[u]^=val[u][i]^val2[u][i];
  for(int v:E[u])if(v!=f){
    rep(i,0,k-1)val2[v][i]^=val2[u][(i+k-1)%k];
    rep(i,0,k-1)val2[v][i]^=val[u][(i+k-1)%k];
    rep(i,0,k-1)val2[v][i]^=val[v][(i+k-2)%k];
    dfs2(v,u);
  }
}

void solve(){
  cin>>n>>k,k*=2;
  rep(i,2,n){
    int u=read(),v=read();E[u].push_back(v),E[v].push_back(u);
  }
  rep(i,1,n)A[i]=read();
  dfs(1,0);
  dfs2(1,0);
  rep(i,1,n)printf("%d ",!!ans[i]);
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}