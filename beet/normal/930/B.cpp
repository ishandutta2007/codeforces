#include<bits/stdc++.h>
using namespace std;
using Int = long long;

struct Precision{
  Precision(){
    cout<<fixed<<setprecision(12);
  }
}precision_beet;


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


template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  string s;
  cin>>s;
  Int n=s.size();
  s=s+s;
  vector<Int> cnt(26,0);
  for(Int i=0;i<n;i++) cnt[s[i]-'a']++;

  auto dp=make_v<signed>(26,26,n);
  fill_v(dp,0);
  
  for(Int i=0;i<n;i++)
    for(Int j=0;j<n;j++)
      dp[s[i]-'a'][s[i+j]-'a'][j]++;

  double ans=0;
  for(Int i=0;i<26;i++){
    double res=0;
    for(Int j=0;j<n;j++){
      double tmp=0;
      for(Int k=0;k<26;k++)
	tmp+=(dp[i][k][j]==1);
      chmax(res,tmp);
    }
    ans+=res;
  }
  ans/=n;
  cout<<ans<<endl;
  return 0;
}