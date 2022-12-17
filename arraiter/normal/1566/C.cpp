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
const int maxn=1e5+10;
int n,A[maxn];char S[maxn],T[maxn];bool vis[maxn];

void solve(){
  n=read();
  scanf("%s%s",S+1,T+1);
  int ans=0;
  rep(i,1,n){
    vis[i]=0;
    if(S[i]==T[i]){
      A[i]=S[i]-'0';
    }else{
      A[i]=2,ans+=2;
    }
  }
  rep(i,1,n)if(A[i]!=2){
    int j=i;
    while(j<n&&A[j+1]!=2)j++;
    rep(k,i,j)if(!A[k])ans++;
    rep(k,i+1,j){
      if(A[k]!=A[k-1]){
        if(A[k-1]==1){
          if(!vis[k]&&!vis[k-1])vis[k]=1,ans++,vis[k-1]=1;
        }else{
          if(A[k]==1){
            if(!vis[k-1]&&!vis[k]){
              vis[k-1]=1,ans++,vis[k]=1;
            }
          }
        }
      }
    }
    i=j;
  }
  cout<<ans<<endl;
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
//  fwrite(out_buf,1,ouf-out_buf,stdout);
  return 0;
}