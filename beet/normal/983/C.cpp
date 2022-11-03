#include<bits/stdc++.h>
using namespace std;
using Int = long long;

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;


template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> a(n),b(n);
  for(Int i=0;i<n;i++) cin>>a[i]>>b[i];
  
  const Int INF = 1e15;
  const Int MAX = 10000;
  vector<Int> dp(MAX,INF);
  vector<Int> nx(MAX,INF);
  dp[0]=0;

  auto conv=[&](Int x){
    vector<Int> v(4);
    for(Int k=0;k<4;k++) v[k]=x%10,x/=10;
    sort(v.begin(),v.end());
    return v;
  };
  auto calc=[&](auto &v){
    Int res=0;
    sort(v.begin(),v.end());
    for(Int k=0;k<4;k++) res=res*10+v[k];
    return res;
  };
  
  for(Int i=0;i<n;i++){
    fill(nx.begin(),nx.end(),INF);
    for(Int j=0;j<MAX;j++){
      if(dp[j]>=INF) continue;
      auto v=conv(j);      
      Int cur=i?a[i-1]:1;
      // cur -> k -> a[i]
      for(Int k=1;k<=9;k++){
	auto u=v;
	Int res=abs(cur-k)+abs(k-a[i]);
	Int lb=min({cur,k,a[i]});
	Int ub=max({cur,k,a[i]});
	for(Int l=0;l<4;l++){
	  if(!u[l]) continue;
	  if(lb<=u[l]&&u[l]<=ub) u[l]=0;
	}
	Int ok=0;
	for(Int l=0;l<4;l++){
	  if(u[l]) continue;
	  ok=1;
	  u[l]=b[i];
	  break;
	}
	if(!ok) continue;
	chmin(nx[calc(u)],dp[j]+res);
      }
    }
    swap(dp,nx);
  }
  
  Int ans=INF;
  for(Int j=0;j<MAX;j++){
    if(dp[j]>=INF) continue;
    //cout<<j<<":"<<dp[j]<<endl;
    auto v=conv(j);
    Int cur=a[n-1];
    for(Int k=1;k<=9;k++){
      for(Int w=1;w<=9;w++){
	auto u=v;
	Int res=abs(cur-k)+abs(k-w);
	Int lb=min({cur,k,w});
	Int ub=max({cur,k,w});
	for(Int l=0;l<4;l++){
	  if(!u[l]) continue;
	  if(lb<=u[l]&&u[l]<=ub) u[l]=0;
	}	
	if(*max_element(u.begin(),u.end())==0){
	  //cout<<j<<":"<<dp[j]<<" "<<res<<endl;
	  chmin(ans,dp[j]+res);
	}
      }
    }
  }
  //cout<<ans<<endl;
  ans+=n*2;
  cout<<ans<<endl;
  return 0;
}