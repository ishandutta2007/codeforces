#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template<typename T1,typename T2> void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> void chmax(T1 &a,T2 b){if(a<b) a=b;}


template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T>
vector<vector<T> > make_v(size_t a,size_t b){
  return vector<vector<T> >(a,make_v<T>(b));
}
template<typename T>
vector<vector<vector<T> > > make_v(size_t a,size_t b,size_t c){
  return vector<vector<vector<T> > > (a,make_v<T>(b,c));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
  for(auto &e:t) fill_v(e,v);
}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i],a[i]--;

  auto dp=make_v<Int>(3,2,n+1);
  fill_v(dp,-1);
  dp[0][0][0]=0;
  
  Int ans=0;
  for(Int i=0;i<n;i++){
    for(Int j=0;j<3;j++){
      for(Int k=0;k<2;k++){
	chmax(ans,dp[j][k][i]);
	if(dp[j][k][i]<0) continue;
	chmax(dp[j][k][i+1],dp[j][k][i]);
	
	Int nc=dp[j][k][i]+1;
	if(j==0){
	  if(k==0){
	    chmax(dp[j][a[i]][i+1],nc);
	    if(a[i]==1) chmax(dp[1][a[i]][i+1],nc);
	  }else{
	    if(a[i]==1) chmax(dp[j][a[i]][i+1],nc);
	  }
	}
	
	if(j==1){
	  if(k==0){
	    if(a[i]==0) chmax(dp[j][a[i]][i+1],nc);
	    if(a[i]==1) chmax(dp[2][a[i]][i+1],nc);
	  }else{
	    chmax(dp[j][a[i]][i+1],nc); 
	  }
	}
	
	if(j==2){
	  if(a[i]==1) chmax(dp[j][a[i]][i+1],nc); 
	}
	
      }
    }
  }
  
  for(Int j=0;j<3;j++)
    for(Int k=0;k<2;k++)
      chmax(ans,dp[j][k][n]);
  cout<<ans<<endl;
  return 0;
}