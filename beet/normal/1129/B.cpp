#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';

//INSERT ABOVE HERE
Int solve1(vector<Int> as){
  Int n=as.size();
  vector<Int> sm(n+1,0);
  for(Int i=0;i<n;i++) sm[i+1]=sm[i]+as[i];

  Int res=*max_element(as.begin(),as.end());
  for(Int l=0;l<n;l++)
    for(Int r=l;r<n;r++)
      chmax(res,(r-l+1)*(sm[r+1]-sm[l]));

  return res;
}

Int solve2(vector<Int> as){
  Int n=as.size();
  Int res=0,cur=0,k=-1;
  for(Int i=0;i<n;i++){
    cur+=as[i];
    if(cur<0){
      cur=0;
      k=i;
    }
    chmax(res,(i-k)*cur);
  }
  return res;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  Int k;
  cin>>k;

  const Int n = 1333;
  vector<Int> ans(n);
  ans[0]=-1;

  const Int val = 1e6;
  Int sum=(n-1)+k+1;
  for(Int i=1;i<n;i++){
    Int dif=min(val,sum);
    ans[i]=dif;
    sum-=dif;
  }
  assert(sum==0);

  // cerr<<solve1(ans)-solve2(ans)<<":"<<k<<endl;
  assert(solve1(ans)-solve2(ans)==k);
  cout<<n<<newl;
  for(Int i=0;i<n;i++){
    if(i) cout<<' ';
    cout<<ans[i];
  }
  cout<<newl;
  return 0;
}