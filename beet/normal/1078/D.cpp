#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';


template<typename T=int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}


template<typename T, typename ...Ts>
vector<T> fusion(vector<T> bs,Ts... ts){
  auto append=[&](auto vs){for(auto v:vs) bs.emplace_back(v);};
  initializer_list<int>{(void(append(ts)),0)...};
  return bs;
}


using P = pair<int, int>;
const int INF = 1e9;
P ti(+INF,-INF);
auto f=[](P a,P b){return P(min(a.first,b.first),max(a.second,b.second));};

struct SegmentTree{
  // using F = function<T(T,T)>;
  int n;
  vector<P> dat;

  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
    dat.assign(n<<1,ti);
  }

  void build(const vector<P> &v){
    int n_=v.size();
    init(n_);
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }

  void set_val(int k,P x){
    dat[k+=n]=x;
    while(k>>=1)
      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);
  }

  P query(int a,int b){
    if(a>=b) return ti;
    P vl=ti,vr=ti;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,dat[l++]);
      if(r&1) vr=f(dat[--r],vr);
    }
    return f(vl,vr);
  }
};


template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}

//INSERT ABOVE HERE
const int LOG = 20;
const int MAX = 1e5+100;
int dL[LOG][MAX*3];
int dR[LOG][MAX*3];

SegmentTree seg[LOG];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  auto rs=read(n);

  if(n==1) drop(0);

  rs=fusion(rs,rs,rs);
  // dL[k][i] <= x <= dR[k][i] ga bakuhatsu
  for(int i=0;i<n*3;i++){
    dL[0][i]=max<int>(i-rs[i],0);
    dR[0][i]=min<int>(i+rs[i],n*3-1);
  }

  for(int k=0;k<LOG;k++){
    vector<P> vp(n*3);
    for(int i=0;i<n*3;i++)
      vp[i]=P(dL[k][i],dR[k][i]);
    seg[k].build(vp);

    if(k+1==LOG) break;

    for(int i=0;i<n*3;i++){
      auto [L,R]=seg[k].query(dL[k][i],dR[k][i]+1);
      dL[k+1][i]=L;
      dR[k+1][i]=R;
    }
  }

  for(int i=0;i<n;i++){
    int L=n+i,R=n+i;
    int res=0;
    for(int k=LOG-1;k>=0;k--){
      auto [nxtL,nxtR]=seg[k].query(L,R+1);
      if(nxtR-nxtL+1>=n) continue;
      L=nxtL;
      R=nxtR;
      res+=1<<k;
    }
    if(i) cout<<' ';
    cout<<res+1;
  }

  cout<<endl;
  return 0;
}