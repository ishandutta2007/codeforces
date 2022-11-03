#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n,x,y;
  cin>>n>>x>>y;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];

  const Int MAX = 2e6+100;
  vector<Int> cnt(MAX+1,0),sum(MAX+1,0);
  for(Int i=0;i<n;i++){
    cnt[a[i]]+=1;
    sum[a[i]]+=a[i];
  }
  
  for(Int i=0;i<MAX;i++){
    cnt[i+1]+=cnt[i];
    sum[i+1]+=sum[i];
  }
  
  Int ans=n*x;
  for(Int i=2;i<MAX/2;i++){
    Int res=0;
    Int f=min(i,x/y+1);
    // (j-i, j-f] + (j-f, j] 
    for(Int j=i;j-i<MAX/2;j+=i){
      Int p=cnt[j-f]-cnt[j-i];
      Int q=cnt[j]-cnt[j-f];
            
      Int s=sum[j-f]-sum[j-i];
      Int t=sum[j]-sum[j-f];
      
      res+=(q*j-t)*y+(p*x);
    }
    chmin(ans,res);
  }
  
  cout<<ans<<endl;
  return 0;
}