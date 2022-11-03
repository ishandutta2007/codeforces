#include <bits/stdc++.h>
using namespace std;

using Int = long long;
const char newl = '\n';

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
template<typename T=int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}
//INSERT ABOVE HERE
const int MAX = 5050;
int prs[MAX][MAX]={};
int cnt[MAX]={};
int ptr[MAX]={};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  for(int v=2;v<MAX;v++){
    int t=v;
    for(int p=2;p<MAX;p++){
      prs[v][p]=prs[v-1][p];
      while(t%p==0){
        t/=p;
        prs[v][p]++;
      }
    }
  }

  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    chmax(k,1);
    cnt[k]++;
  }

  using ll = long long;
  ll res=0;
  for(int v=1;v<MAX;v++)
    for(int p=2;p<MAX;p++)
      res+=(ll)cnt[v]*prs[v][p];

  vector<int> vs;
  for(int v=1;v<MAX;v++)
    if(cnt[v]) vs.emplace_back(v),ptr[v]=MAX-1;

  while(1){
    vector<int> nx;
    vector<int> sub(MAX,0);
    for(int v:vs){
      while(ptr[v] and !prs[v][ptr[v]]) ptr[v]--;
      if(ptr[v]==0) continue;
      sub[ptr[v]]+=cnt[v];
      nx.emplace_back(v);
    }
    if(nx.empty()) break;

    int p=max_element(sub.begin(),sub.end())-sub.begin();
    if(sub[p]<=n-sub[p]) break;

    int stp=1e9;
    for(int v:vs){
      if(ptr[v]!=p) continue;
      chmin(stp,prs[v][p]);
    }
    res-=(ll)stp*(sub[p]-(n-sub[p]));

    nx.clear();
    for(int v:vs){
      if(ptr[v]!=p) continue;
      prs[v][p]-=stp;
      nx.emplace_back(v);
    }
    swap(vs,nx);
  }

  cout<<res<<newl;
  return 0;
}