#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,w,h;
  cin>>n>>w>>h;
  vector<int> xs(n),ys(n),ts(n);
  vector<int> xt(n),yt(n);
  for(int i=0;i<n;i++){
    int g,p,t;
    cin>>g>>p>>t;
    if(g==1){
      xs[i]=p;
      ys[i]=0;
      ts[i]=t;

      xt[i]=p;
      yt[i]=h;
    }
    if(g==2){
      xs[i]=0;
      ys[i]=p;
      ts[i]=t;

      xt[i]=w;
      yt[i]=p;
    }
  }

  map<int, vector<int>> R;
  for(int i=0;i<n;i++)
    R[xs[i]+ys[i]-ts[i]].emplace_back(i);

  vector<int> ans(n);
  for(auto p:R){
    auto vs=p.second;
    auto cmp1=[&](int i,int j){
      if(xs[i]!=xs[j]) return xs[i]<xs[j];
      return ys[i]>ys[j];
    };
    sort(vs.begin(),vs.end(),cmp1);

    auto vt=p.second;
    auto cmp2=[&](int i,int j){
      if(xt[i]!=xt[j]) return xt[i]<xt[j];
      return yt[i]>yt[j];
    };
    sort(vt.begin(),vt.end(),cmp2);

    for(int i=0;i<(int)vs.size();i++) ans[vs[i]]=vt[i];
  }

  for(int i=0;i<n;i++)
    cout<<xt[ans[i]]<<' '<<yt[ans[i]]<<newl;
  return 0;
}