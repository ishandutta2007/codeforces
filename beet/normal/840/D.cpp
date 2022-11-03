#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';


uint32_t xor128(){
  static uint32_t x = 123456789;
  static uint32_t y = 362436069;
  static uint32_t z = 521288629;
  static uint32_t w = 88675123;
  uint32_t t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

//INSERT ABOVE HERE

const int MAX = 3e5+100;
int as[MAX],cnt[MAX]={};
vector<int> G[MAX];

int used[MAX]={};

int num[MAX]={};
vector<int> H[MAX];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  for(int i=0;i<n;i++) cin>>as[i];
  for(int i=0;i<n;i++) G[as[i]].emplace_back(i);

  for(int i=0;i<n;i++) num[as[i]]++;

  const int BS = 500;
  for(int v=1;v<=n;v++){
    if(num[v]<=BS) continue;
    H[v].assign(n+1,0);
    for(int i=0;i<n;i++)
      H[v][i+1]=H[v][i]+(as[i]==v);
  }

  auto calc=[&](int l,int r,int v)->int{
    if(num[v]>BS) return H[v][r]-H[v][l];
    auto &vs=G[v];
    return
      lower_bound(vs.begin(),vs.end(),r)-lower_bound(vs.begin(),vs.end(),l);
  };


  for(int i=0;i<q;i++){
    int l,r,k;
    cin>>l>>r>>k;
    l--;
    // [l, r)

    int need=(r-l)/k;
    int ans=n+1;

    const int B = 80, C = 75;
    if(r-l<B){
      for(int j=l;j<r;j++) cnt[as[j]]++;
      for(int j=l;j<r;j++)
        if(cnt[as[j]]>need)
          chmin(ans,as[j]);
      for(int j=l;j<r;j++) cnt[as[j]]=0;
    }else{
      vector<int> vs;
      for(int t=0;t<C;t++){
        int v=as[l+xor128()%(r-l)];
        if(used[v]) continue;
        used[v]=1;
        vs.emplace_back(v);
        if(calc(l,r,v)>need) chmin(ans,v);
      }
      for(int v:vs) used[v]=0;
    }

    if(ans>n) ans=-1;
    cout<<ans<<newl;
  }
  return 0;
}