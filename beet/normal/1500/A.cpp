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


template<typename V>
V compress(V vs){
  sort(vs.begin(),vs.end());
  vs.erase(unique(vs.begin(),vs.end()),vs.end());
  return vs;
}
template<typename T>
map<T, int> dict(const vector<T> &vs){
  map<T, int> res;
  for(int i=0;i<(int)vs.size();i++)
    res[vs[i]]=i;
  return res;
}
map<char, int> dict(const string &s){
  return dict(vector<char>(s.begin(),s.end()));
}

//INSERT ABOVE HERE

const int MAX = 5e6 + 10;
using P = pair<int, int>;
P ps[MAX]={};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  auto as=read(n);

  map<int, vector<int>> I;
  for(int i=0;i<n;i++)
    I[as[i]].emplace_back(i+1);

  auto YES=[&](int x,int y,int z,int w){
    // cout<<x<<' '<<y<<' '<<z<<' '<<w<<endl;

    set<int> ans;
    ans.emplace(x);
    ans.emplace(y);
    ans.emplace(z);
    ans.emplace(w);
    assert(1<=*ans.begin() and *ans.rbegin()<=n);
    assert(ans.size()==4);
    assert(as[x-1]+as[y-1]==as[z-1]+as[w-1]);
    cout<<"YES"<<newl;
    cout<<x<<' '<<y<<' '<<z<<' '<<w<<newl;
    exit(0);
  };

  set<int> ss;
  for(int a:as){
    if(I[a].size()==1) continue;
    if(I[a].size()>=4) YES(I[a][0],I[a][1],I[a][2],I[a][3]);
    ss.emplace(a);
  }

  if(ss.size()>=2){
    int p=*ss.begin();
    int q=*ss.rbegin();
    YES(I[p][0],I[q][0],I[p][1],I[q][1]);
  }

  auto cs=compress(as);
  for(int i=0;i<(int)cs.size();i++){
    for(int j=0;j<i;j++){
      if((cs[i]+cs[j])%2==0){
        int a=(cs[i]+cs[j])/2;
        // cout<<a<<' '<<ss.count(a)<<endl;
        if(ss.count(a)) YES(I[cs[i]][0],I[cs[j]][0],I[a][0],I[a][1]);
      }

      if(ps[cs[i]+cs[j]].first!=ps[cs[i]+cs[j]].second){
        auto[k,l]=ps[cs[i]+cs[j]];
        YES(I[cs[i]][0],I[cs[j]][0],I[cs[k]][0],I[cs[l]][0]);
      }
      ps[cs[i]+cs[j]]=P(i,j);
    }
  }

  drop("NO");
  return 0;
}