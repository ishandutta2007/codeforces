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
int n,tot,A[505];pii dat[250010];

int calc(pii p){
  return abs(A[p.first]-A[p.second]);
}

void solve(){
  cin>>n;
  rep(i,1,n)A[i]=read();
  rep(i,1,n)rep(j,i+1,n)dat[++tot]={i,j};
  sort(dat+1,dat+tot+1,[](pii P,pii Q){
    return calc(P)>calc(Q);
  });
  rep(_,1,tot){
    pii p=dat[_];
    int x=p.first,y=p.second;
    if(A[x]<A[y])swap(x,y);
    printf("? %d %d\n",x,y);
    fflush(stdout);
    char str[10];
    scanf("%s",str);
    if(*str=='Y'){
      printf("! %d %d\n",x,y);
      return;
    }
  }
  puts("! 0 0");
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}