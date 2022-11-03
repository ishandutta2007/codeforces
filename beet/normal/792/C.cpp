#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
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
  string s;
  cin>>s;
  int n=s.size();
  auto dp=make_v<int>(3,n+1);
  const int INF = 1e7;
  fill_v(dp,-INF);
  for(int i=0;i<n;i++){
    int v=(s[i]-'0')%3;
    if(s[i]!='0') dp[v][i+1]=1;    
    for(int j=0;j<3;j++){      
      chmax(dp[j][i+1],dp[j][i]);
      chmax(dp[(j*10+v)%3][i+1],dp[j][i]+1);      
    }    
  }
  if(dp[0][n]<0){
    if(s.find("0")==string::npos) cout<<-1<<endl;
    else cout<<0<<endl;
    return 0;
  }
  
  int pos=0;
  string ans;
  for(int i=n;i>0;i--){    
    int v=(s[i-1]-'0')%3;
    int j=(pos+3-v)%3;
    if(s[i-1]!='0'&&j==0&&dp[pos][i]==1){
      ans.push_back(s[i-1]);
      break;
    }
    if(dp[j][i-1]+1==dp[pos][i]){
      ans.push_back(s[i-1]);
      pos=j;
    }
  }
  
  reverse(ans.begin(),ans.end());
  cout<<ans<<endl;
  return 0;
}