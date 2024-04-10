#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// longest common prefix of s and s[i:n]
vector<int> zalgorithm(string s){
  int n=s.size();
  vector<int> as(n,0);
  as[0]=n;
  int i=1,j=0;
  while(i<n){
    while(i+j<n&&s[j]==s[i+j]) j++;
    as[i]=j;
    if(j==0){
      i++;
      continue;
    }
    int k=1;
    while(i+k<n&&k+as[k]<j) as[i+k]=as[k],k++;
    i+=k;
    j-=k;
  }
  return as;
}
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct BIT{
  int n;
  vector<T> bit;
  //1-indexed
  BIT(int n_):n(n_+1),bit(n,0){}

  T sum(int i){
    T s(0);
    for(int x=i;x>0;x-=(x&-x))
      s+=bit[x];
    return s;
  }

  void add(int i,T a){
    if(i==0) return;
    for(int x=i;x<=n;x+=(x&-x))
      bit[x]+=a;
  }

  int lower_bound(int w){
    if(w<=0) return 0;
    int x=0,r=1;
    while(r<n) r<<=1;
    for(int k=r;k>0;k>>=1){
      if(x+k<=n&&bit[x+k]<w){
        w-=bit[x+k];
        x+=k;
      }
    }
    return x+1;
  }

  // [l, r)
  T query(int l,int r){
    return sum(r-1)-sum(l-1);
  }

  T sum0(int i){
    return sum(i+1);
  }

  void add0(int i,T a){
    add(i+1,a);
  }

  T query0(int l,int r){
    return sum(r)-sum(l);
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../tools/fastio.cpp"
#undef call_from_test

// lower_bound
signed ARC033_C(){
  int q;
  cin>>q;
  BIT<int> bit(2e5);
  while(q--){
    int t,x;
    cin>>t>>x;
    if(t==1) bit.add(x,1);
    if(t==2){
      int k=bit.lower_bound(x);
      bit.add(k,-1);
      cout<<k<<endl;
    }
  }
  return 0;
}
/*
  verified on 2019/11/11
  https://atcoder.jp/contests/arc033/tasks/arc033_3
*/

signed main(){
  ARC033_C();
  return 0;
}
#endif

#undef call_from_test

//INSERT ABOVE HERE
signed CFR432_D(){
  string s;
  cin>>s;
  vector<int> as=zalgorithm(s);
  int n=s.size();
  set<int> ss;
  BIT<int> bit(n+100);
  for(int i=0;i<n;i++){
    bit.add0(as[i],1);
    if(i+as[i]!=n) continue;
    ss.emplace(as[i]);
  }
  cout<<ss.size()<<"\n";
  for(auto x:ss) cout<<x<<" "<<bit.query0(x,n+100)<<"\n";
  return 0;
}
/*
  verified on 2019/10/28
  http://codeforces.com/problemset/problem/432/D
*/

signed main(){
  CFR432_D();
  return 0;
}
#endif