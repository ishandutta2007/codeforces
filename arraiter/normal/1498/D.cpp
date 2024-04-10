#pragma GCC optimize(3)
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
int n,m,dp[maxn],ans[maxn],tmp[maxn],val[maxn];

void solve(){
  cin>>n>>m;
  dp[0]=1;
  memset(ans,-1,sizeof ans);
  rep(_,1,n){
    int op=read();ll xx;int y;
    scanf("%lld%d",&xx,&y);
    if(op==1){
      int x=(xx+99999)/100000;
      rep(rem,0,x-1){
//        printf("#%d\n",rem);
        int len=0;
        for(int i=rem;i<=m;i+=x){
          len++,tmp[len]=tmp[len-1]+dp[i],val[len]=dp[i];
        }
//        rep(i,1,len)printf("%d ",val[i]);puts("");
        per(i,len,1)val[i]|=tmp[i]>tmp[max(0,i-y-1)];
        for(int i=rem,cur=0;i<=m;i+=x){
          dp[i]=val[++cur];
        }
      }
    }else{
      static int vec[maxn];int len=0;
      ll cur=0;
      rep(i,1,m){
        cur+=xx;
        ll tp=cur;
        tp=(tp+99999)/100000;
        tmp[i]=min((ll)m+1,tp);
        if(i!=tmp[i]&&dp[i])vec[++len]=i;
      }
      int tp=1;
      rep(T,1,y){
        tp=tmp[tp];
        if(tp>m)break;
        int tpl=len;len=0;
        rep(i,1,tpl){
          int x=vec[i],y=tmp[x];
          if(!dp[y]){
            dp[y]=1;if(y!=tmp[y])vec[++len]=y;
          }
        }
      }
    }
    rep(i,1,m)if(ans[i]==-1&&dp[i])ans[i]=_;
  }
  rep(i,1,m)printf("%d ",ans[i]);
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}