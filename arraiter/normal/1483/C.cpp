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
const int maxn=3e5+10;
int n,A[maxn],B[maxn],st[maxn];ll dp[maxn],pre[maxn];

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

ll val[maxn<<2];
void ins(int k,int l,int r,int x){
  if(l==r)return val[k]=dp[x],void();
  x<=mid?ins(lson,x):ins(rson,x),val[k]=max(val[k<<1],val[k<<1|1]);
}
ll query(int k,int l,int r,int ql,int qr){
  if(ql<=l&&r<=qr)return val[k];
  ll res=-1e18;
  if(ql<=mid)res=query(lson,ql,qr);
  if(qr>mid)chkmax(res,query(rson,ql,qr));
  return res;
}

#undef mid
#undef lson
#undef rson

void solve(){
  cin>>n;
  rep(i,1,n)A[i]=read();rep(i,1,n)B[i]=read();
  memset(val,-0x3f,sizeof val);
  ins(1,0,n,0);
  memset(dp,-0x3f,sizeof dp);
  memset(pre,-0x3f,sizeof pre);
  int top=0;
  rep(i,1,n){
    while(top&&A[st[top]]>A[i])top--;
//    if(top)dp[i]=pre[top];
    st[++top]=i;
    pre[top]=max(pre[top-1],query(1,0,n,st[top-1],i-1)+B[i]);
    dp[i]=pre[top];
    ins(1,0,n,i);
//    printf("#%d %lld\n",top,dp[i]);
  }
  cout<<dp[n]<<endl;
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}