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
const int maxn=2e5+10;
int n,k,A[maxn],val[1<<20],ct[20];


void solve(){
  cin>>n>>k;
  memset(ct,0,sizeof ct);
  rep(i,1,n)A[i]=val[read()],ct[A[i]]++;
  int ans=0,su=k;
  while(1){
    bool flg=1;
    rep(i,0,19)flg&=!ct[i];
    if(flg)break;
    ans++,su=k;
    per(i,19,0)while(ct[i]&&(1<<i)<=su){
      su-=1<<i,ct[i]--;
    }
  }
  cout<<ans<<endl;
}

signed main(){
  rep(i,0,19)val[1<<i]=i;
  rep(i,1,(1<<20)-1)if(!val[i])val[i]=val[i-1];
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}