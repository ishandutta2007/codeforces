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
int n,A[maxn],par[maxn],par2[maxn];

int find(int x){
  return par[x]==x?x:par[x]=find(par[x]);
}
int find2(int x){
  return par2[x]==x?x:par2[x]=find2(par2[x]);
}

void solve(){
  cin>>n;
  rep(i,1,n){
    A[i]=read(),par[i]=i,par2[i]=i;
  }
  par[n+1]=par2[n+1]=n+1,par[n+2]=par2[n+2]=n+1,A[n+1]=A[n+2]=0;
  vi ans;
  while(1){
    int i=find(1),nxt,ct=0;
    while(1){
      if(i==n+1)break;
      i=find2(i);
      if(i==n+1)break;
      nxt=find(i+1);
      if(nxt==n+1){
        int tp=find(1);
        if(__gcd(A[tp],A[i])==1){
          ans.push_back(tp),par[1]=find(tp+1),ct++;
        }
        break;
      }
      if(__gcd(A[i],A[nxt])==1){
        ans.push_back(nxt),ct++;
        i=par[nxt]=find(nxt+1);
      }else{
        par2[i]=find2(nxt),i=par2[i];
      }
    }
    if(!ct)break;
  }
  cout<<ans.size();for(int x:ans)printf(" %d",x);puts("");
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}