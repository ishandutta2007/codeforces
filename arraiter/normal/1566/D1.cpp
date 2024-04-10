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
int n,m,A[99999],mp[305][305];

map<int,vector<int>>S;

void solve(){
  S.clear();
  cin>>n>>m;
  rep(i,1,n*m)A[i]=read(),S[A[i]].push_back(i);
  int x=1,y=1;
  rep(T,1,n*m){
//    printf("(%d %d)\n",x,y);
    auto it=S.begin();
    vi&vec=it->second;
    int sz=vec.size();
    if(sz<=m-y+1){
      reverse(vec.begin(),vec.end());
      for(int t:vec){
        T++;
        mp[x][y]=t;
        y++;
      }
      if(y>m)x++,y=1;
      S.erase(S.begin());
      T--;
      continue;
    }
    vi ano;
    rep(i,0,m-y){
      mp[x][y+i]=vec[m-y-i];
      T++;
    }
    rep(i,m-y+1,vec.size()-1)ano.push_back(vec[i]);
    T--;
    x++,y=1;
    vec=ano;
  }
  int ans=0;
  rep(i,1,n){
    rep(j,1,m){
//      printf("%d%c",mp[i][j],"\n "[j<m]);
      rep(k,1,j-1)ans+=mp[i][k]<mp[i][j];
    }
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