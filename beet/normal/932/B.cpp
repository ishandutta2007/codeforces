#include<bits/stdc++.h>
using namespace std;
using Int = long long;

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


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed main(){
  
  Int MAX=1e6+100;
  vector<signed> dp(MAX,-1);
  function<Int(signed)> dfs=[&](Int x){
    signed &res=dp[x];
    if(~res) return res;
    if(x<10) return res=x;
    //cout<<x<<endl;
    string s=to_string(x);
    Int tmp=1;
    for(char c:s) if(c!='0') tmp*=(c-'0');
    return res=dfs(tmp);
  };
  
  auto s=make_v<signed>(10,MAX);
  fill_v(s,0);
  for(Int i=1;i<MAX;i++)
    for(Int j=0;j<10;j++)
      s[j][i]=s[j][i-1]+(j==dfs(i));

  Int q;
  cin>>q;
  for(Int i=0;i<q;i++){
    Int l,r,k;
    cin>>l>>r>>k;
    l--;
    cout<<s[k][r]-s[k][l]<<endl;
  }
  
  return 0;
}