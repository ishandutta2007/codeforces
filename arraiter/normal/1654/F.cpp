#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define mem(x) memset((x),0,sizeof(x))

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

typedef unsigned u32;
typedef unsigned uint;
typedef unsigned long long u64;

namespace orzjk{
  const int SZ=1e6;
  char buf[SZ],*p1=buf,*p2=buf;
  char nc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,SZ,stdin),p1==p2)?EOF:*p1++;
  }
  char fub[SZ],*p3=fub,*p4=fub+SZ;
  void pc(char c){
    p3==p4&&(fwrite(fub,1,SZ,stdout),p3=fub);
    *p3++=c;
  }
  void flush(){
    fwrite(fub,1,p3-fub,stdout),p3=fub;
  }
}
using orzjk::nc;
using orzjk::pc;

//#define nc getchar
//#define pc putchar

int read(){
  int x=0,f=1;char c=nc();
  while(c<48)c=='-'&&(f=-1),c=nc();
  while(c>47)x=x*10+(c^48),c=nc();
  return x*f;
}
void write(int x){
  static char st[21];
  if(!x)return pc(48),void();
  char*p=st;
  if(x<0)x=-x,pc('-');
  for(;x;x/=10)*p++=x%10|48;
  do{
    pc(*--p);
  }while(p!=st);
}

//const int P=1e9+7;
const int P=998244353;
int qp(int a,int k){
  int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;
}

const int maxn=6e5+10;
char S[maxn];
int n;

const int P1 = 1e9 + 7, P2 = 1e9 + 9;
int base, pow1[maxn], pow2[maxn];

void init() {
  base = Rnd();
  if (base < 0) base = -base;
  base %= 19260817, base += 257;
  pow1[0] = pow2[0] = 1;
  rep(i, 1, maxn - 1) {
    pow1[i] = 1ll * base * pow1[i - 1] % P1;
    pow2[i] = 1ll * base * pow2[i - 1] % P2;
  }
}

struct Hash {
  int v1, v2;

  Hash() {}
  Hash(int x, int y) : v1(x), v2(y) {}

  void print() {
    printf("#(%d %d)\n", v1, v2);
  }

  void get(Hash &o, char ch) {
    v1 = (1ll * o.v1 * base + ch) % P1;
    v2 = (1ll * o.v2 * base + ch) % P2;
  }

  bool operator == (const Hash &o) const {
    return v1 == o.v1 && v2 == o.v2;
  }

  bool operator != (const Hash &o) const {
    return v1 != o.v1 || v2 != o.v2;
  }
  
  Hash pb(Hash o,int len)const{
    return Hash(
      (1ll*pow1[len]*v1+o.v1)%P1,
      (1ll*pow2[len]*v2+o.v2)%P2
    );
  }
};

Hash val[19][1<<18];

bool cmp(int dep,int rt_x,int x,int rt_y,int y){
  if(dep==n){
    return S[rt_x]<S[rt_y];
  }
  Hash X,Y;
  int hi_x=x>>(n-dep-1)&1;
  int hi_y=y>>(n-dep-1)&1;
  if(hi_x)x-=1<<(n-dep-1);
  if(hi_y)y-=1<<(n-dep-1);
  X=val[dep+1][(rt_x+(hi_x)*(1<<(n-dep-1)))+x];
  Y=val[dep+1][(rt_y+(hi_y)*(1<<(n-dep-1)))+y];
  if(X==Y){
    return cmp(dep+1,rt_x+(1^hi_x)*(1<<(n-dep-1)),x,rt_y+(1^hi_y)*(1<<(n-dep-1)),y);
  }else{
    return cmp(dep+1,rt_x+(hi_x)*(1<<(n-dep-1)),x,rt_y+(hi_y)*(1<<(n-dep-1)),y);
  }
}

Hash all;

void solve(){
  init();
  scanf("%d%s",&n,S);
  rep(i,0,(1<<n)-1)val[n][i]={S[i],S[i]};
//  per(i,1,0)all=all.pb({S[i],S[i]},1);
//  printf("#%d\n",all.v1);
  per(i,n-1,0){
    int len=(1<<(n-i-1));
    for(int j=0;j<(1<<n);j+=len*2){
      rep(k,0,len-1){
        val[i][j+k]=val[i+1][j+k].pb(val[i+1][j+k+len],len);
        val[i][j+k+len]=val[i+1][j+k+len].pb(val[i+1][j+k],len);
      }
    }
  }
//  rep(i,0,n)rep(j,0,(1<<n)-1)printf("(%d %d) %d\n",i,j,val[i][j].v1);
  int ans=0;
  rep(pos,1,(1<<n)-1){
    if(cmp(0,0,pos,0,ans))ans=pos;
  }
  rep(i,0,(1<<n)-1)putchar(S[i^ans]);
}

signed main(){
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
//  int T;cin>>T;while(T--)solve();
  solve();
  orzjk::flush();
  return 0;
}