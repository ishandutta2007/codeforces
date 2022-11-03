#include <bits/stdc++.h>
using namespace std;

using Int = long long;
const char newl = '\n';

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
template<typename T=Int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  Int a[2][2];

  cin>>a[0][0];
  cin>>a[0][1];
  cin>>a[1][0];
  cin>>a[1][1];

  Int sum=0;
  for(Int i=0;i<2;i++)
    for(Int j=0;j<2;j++)
      sum+=a[i][j];

  if(sum==0) drop("1");

  Int n=1;
  while(n*(n-1)/2<sum) n++;
  if(n*(n-1)/2!=sum) drop("Impossible");

  for(Int k=0;k<2;k++)
    if(sum==a[k][k]) drop(string(n,'0'+k));

  Int l[2]={1,1};
  for(Int k=0;k<2;k++){
    while(l[k]*(l[k]-1)/2<a[k][k]) l[k]++;
    if(l[k]*(l[k]-1)/2!=a[k][k]) drop("Impossible");
  }
  // cout<<l[0]<<' '<<l[1]<<' '<<n<<endl;
  if(l[0]+l[1]!=n) drop("Impossible");

  vector<Int> cnt(l[0]+1,0);
  Int need=a[1][0];
  for(Int i=0;i<l[1];i++){
    Int tmp=min(need,l[0]);
    cnt[l[0]-tmp]++;
    need-=tmp;
  }

  string ans;
  for(Int i=0;i<l[0];i++){
    ans+=string(cnt[i],'1');
    ans+='0';
  }
  ans+=string(cnt[l[0]],'1');

  const Int DEBUG = 1;
  if(DEBUG){
    Int cs[2]={};
    Int way[2][2]={};
    for(Int i=0;i<n;i++){
      Int t=ans[i]-'0';
      way[0][t]+=cs[0];
      way[1][t]+=cs[1];
      cs[t]++;
    }
    for(Int i=0;i<2;i++)
      for(Int j=0;j<2;j++)
        assert(a[i][j]==way[i][j]);
  }
  cout<<ans<<newl;
  return 0;
}