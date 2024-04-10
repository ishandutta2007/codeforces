#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;


template<typename T>
vector<T> compress(vector<T> v){
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  return v;
}

//INSERT ABOVE HERE
const Int MAX = 1010;
Int a[MAX][MAX];
Int b[MAX][MAX];
Int c[MAX][MAX];
Int d[MAX][MAX];

Int ans[MAX][MAX];
signed main(){
  Int n,m;
  cin>>n>>m;
  for(Int i=0;i<n;i++)
    for(Int j=0;j<m;j++)
      cin>>a[i][j];

  memset(d,0,sizeof(d));
  {
    vector<Int> v(m);
    for(Int i=0;i<n;i++){
      for(Int j=0;j<m;j++) v[j]=a[i][j];
      auto u=compress(v);
      for(Int j=0;j<m;j++){
        b[i][j]=lower_bound(u.begin(),u.end(),a[i][j])-u.begin();
        chmax(d[i][j],(Int)u.size()-b[i][j]);
      }
    }
  }  
  {
    vector<Int> v(n);
    for(Int j=0;j<m;j++){
      for(Int i=0;i<n;i++) v[i]=a[i][j];
      auto u=compress(v);
      for(Int i=0;i<n;i++){
        c[i][j]=lower_bound(u.begin(),u.end(),a[i][j])-u.begin();
        chmax(d[i][j],(Int)u.size()-c[i][j]);
      }
    }
  }

  memset(ans,0,sizeof(ans));
  for(Int i=0;i<n;i++)
    for(Int j=0;j<m;j++)
      ans[i][j]=max(b[i][j],c[i][j])+d[i][j];  
  
  for(Int i=0;i<n;i++){
    for(Int j=0;j<m;j++){
      if(j) cout<<" ";
      cout<<ans[i][j];
    }
    cout<<"\n";
  }
  cout<<flush;
  return 0;
}