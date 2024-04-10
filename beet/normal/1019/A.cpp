#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n,m;
  cin>>n>>m;
  vector<Int> p(n),c(n);
  for(Int i=0;i<n;i++){
    cin>>p[i]>>c[i];
    p[i]--;
  }

  Int ans=0;
  for(Int i=0;i<n;i++) ans+=c[i];

  Int cnt=0;
  using P = pair<Int, Int>;
  vector<vector<P> > cs(m);
  vector<P> as;
  for(Int i=0;i<n;i++){
    if(p[i]==0) cnt++;
    else{
      cs[p[i]].emplace_back(c[i],i);
      as.emplace_back(c[i],i);
    }
  }
  
  for(Int i=0;i<m;i++){
    sort(cs[i].begin(),cs[i].end());
  }
  
  sort(as.begin(),as.end());
  
  for(Int t=0;t<=n;t++){
    vector<Int> used(n,0);
    
    Int res=0,add=0,all=0;
    for(Int i=1;i<m;i++){
      Int k=cs[i].size()-(cnt+t-1);
      chmax(k,0);
      chmin(k,(Int)cs[i].size());
      for(Int j=0;j<k;j++){
	res+=cs[i][j].first;
	used[cs[i][j].second]=1;
      }
      add+=k;
      all+=cs[i].size();
    }
    //cout<<t<<" "<<add<<" "<<all<<":"<<res<<endl;
    if(all<t) continue;
    
    for(Int i=0;i<(Int)as.size();i++){
      if(add>=t) break;
      if(used[as[i].second]) continue;
      res+=as[i].first;
      add++;
      if(add>=t) break;
    }
    
    chmin(ans,res);
  }
  
  cout<<ans<<endl;
  return 0;
}