#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

//inline char nc(){
//  static char buf[1000000],*p1=buf,*p2=buf;
//  return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
//}

//char out_buf[1<<23|5],*ouf=out_buf; // size
//inline void pc(const char&c){*ouf=c,++ouf;}

#define nc() getchar()
#define pc(x) putchar(x)

inline int read(){
  bool f=0;int x=0;char c=nc();
  while(c<48)f|=c=='-',c=nc();
  while(c>47)x=x*10+(c^48),c=nc();
  return f?-x:x;
}

void write$(int x){
  if(x>9)write$(x/10);
  pc(x%10|48);
}
void write(int x){
  if(x<0)x=-x,pc('-');
  write$(x);
}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
const int maxn=2e5+10;
int n,cnt,ans,deg[maxn],val[maxn],dp[maxn];vi E[maxn];bool chk[maxn],leaf[maxn];int fa[maxn];

void dfs(int u,int f){
  fa[u]=f;
  leaf[u]=u>1&&(int)E[u].size()==1;
  chk[u]=0;dp[u]=0;
  cnt+=leaf[u];
  if(leaf[u]){
    chk[u]=1,dp[u]=0;return;
  }
  bool flg=1;
  for(int v:E[u])if(v!=f){
    dfs(v,u);
    flg&=!chk[v];dp[u]+=dp[v];
  }
  if(!flg)chk[u]=0,dp[u]++;
  else chk[u]=1,dp[u]--;
}
void dfs2(int u,int f,int cur){
//  printf("!(%d) (%d %d %d)\n",u,dp[u],chk[u],leaf[u]);
  if(leaf[u]){
//    printf("%d : %d\n",u,cnt-cur);
    ans=min(ans,cnt-cur);
    return;
  }
  for(int v:E[u])if(v!=f){
    cur+=dp[v];
  }
  for(int v:E[u])if(v!=f){
    int tp=cur-dp[v];
    dfs2(v,u,tp);
  }
}

void solve(){
  cnt=0;
  n=read();
  rep(i,1,n)deg[i]=0,E[i].clear(),val[i]=0;
  rep(i,2,n){
    int u=read(),v=read();E[u].push_back(v),E[v].push_back(u),deg[u]++,deg[v]++;
  }
  if(n==2){
    puts("1");return;
  }
  dfs(1,0);
  ans=cnt;
  dfs2(1,0,0);
//  puts("##");
  cout<<ans<<endl;
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
//  fwrite(out_buf,1,ouf-out_buf,stdout);
  return 0;
}