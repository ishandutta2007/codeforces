#include<bits/stdc++.h>
using namespace std;
using Int = long long;

const Int MOD=1e9+7; //<- alert!!!
typedef vector<Int> arr;
typedef vector<arr> mat;
inline arr mul(const mat &a,arr &b,Int mod){
  arr res(b.size(),0);
  for(Int i=0;i<(Int)b.size();i++)
    for(Int j=0;j<(Int)a[i].size();j++)
      (res[i]+=a[i][j]*b[j])%=mod;
  return res;
}
inline mat mul(const mat &a,const mat &b,Int mod){
  mat res(a.size(),arr(b[0].size(),0));
  for(Int i=0;i<(Int)a.size();i++)
    for(Int j=0;j<(Int)b[0].size();j++)
      for(Int k=0;k<(Int)b.size();k++)
	(res[i][j]+=a[i][k]*b[k][j])%=mod;
  return res;
}
inline mat mat_pow(mat a,Int n,Int mod){
  mat res(a);
  for(Int i=0;i<(Int)a.size();i++)
    for(Int j=0;j<(Int)a[i].size();j++)
      res[i][j]=(i==j);
  while(n){
    if(n&1) res=mul(a,res,mod);
    a=mul(a,a,mod);
    n>>=1;
  }
  return res;
}


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
  Int n,m;
  cin>>n>>m;
  vector<Int> a(n),l(n),r(n);
  for(Int i=0;i<n;i++) cin>>a[i]>>l[i]>>r[i];

  vector<Int> v({1,m});
  for(Int i=0;i<n;i++) v.emplace_back(l[i]);
  for(Int i=0;i<n;i++) v.emplace_back(r[i]+1);
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  map<Int, Int> mi;
  for(Int i=0;i<(Int)v.size();i++) mi[v[i]]=i;

  auto dp=make_v<Int>(3,v.size()+1);
  for(Int i=0;i<n;i++){
    dp[a[i]-1][mi[l[i]]]++;
    dp[a[i]-1][mi[r[i]+1]]--;
  }

  for(Int k=0;k<3;k++)
    for(Int i=0;i<(Int)v.size();i++) dp[k][i+1]+=dp[k][i];
  
  arr x({0,1,0});
  for(Int i=0;i<(Int)v.size()-1;i++){
    //cout<<v[i]<<":"<<dp[0][i]<<" "<<dp[1][i]<<" "<<dp[2][i]<<endl;
    if(v[i+1]-v[i]-1>0){
      mat c(3,arr(3,0));
      for(Int j=0;j<3;j++){
	if(dp[j][i]) continue;
	for(Int k=0;k<3;k++)
	  if(abs(j-k)<=1&&!dp[k][i]) c[j][k]=1;
      }
      c=mat_pow(c,v[i+1]-v[i]-1,MOD);
      x=mul(c,x,MOD);
    }
    {
      arr y(3,0);
      for(Int j=0;j<3;j++){
	if(!x[j]) continue;
	for(Int k=0;k<3;k++)
	  if(abs(j-k)<=1&&!dp[k][i+1]) (y[k]+=x[j])%=MOD;
      }
      swap(x,y);
    }
    //cout<<v[i]<<":"<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
  }
  cout<<x[1]<<endl;
  return 0;
}