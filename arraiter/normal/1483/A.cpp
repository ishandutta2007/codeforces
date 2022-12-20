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
int n,m,val[maxn];vector<int>vec[maxn],tmp[maxn];int ans[maxn];

void solve(){
  cin>>n>>m;
  rep(i,1,m){
    int k=read();
    while(k--){
      int x=read();val[i]++,vec[i].push_back(x),tmp[x].push_back(i);
    }
  }
  int all=0;
  rep(i,1,n){
    vi ano;
    for(int x:tmp[i])if(!ans[x])ano.push_back(x);
    ano.swap(tmp[i]);
    int ct=0;
    for(int x:tmp[i]){
      if(ans[x])continue;
      ct++;
//      ans[x]=i,all++;
//      if(++ct>=(m+1)/2)break;
    }
    if(ct<=(m+1)/2){
      for(int x:tmp[i]){
        if(ans[x])continue;
        ans[x]=i,all++;
      }
      continue;
    }
    ct=0;
    sort(tmp[i].begin(),tmp[i].end(),[](int x,int y){
      return val[x]<val[y];
    });
    for(int x:tmp[i]){
      if(ct==(m+1)/2){
        val[x]--;
      }else{
        ans[x]=i,all++,ct++;
      }
    }
  }
  if(all<m){
    puts("NO");
  }else{
    puts("YES");
    rep(i,1,m)printf("%d%c",ans[i],"\n "[i<m]);
  }
  rep(i,1,n)tmp[i].clear();
  rep(i,1,m)vec[i].clear(),ans[i]=val[i]=0;
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}