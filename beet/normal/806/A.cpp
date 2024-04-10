#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';

//INSERT ABOVE HERE
signed solve(){
  Int x,y,p,q;
  cin>>x>>y>>p>>q;

  if(x*q==y*p){
    cout<<0<<newl;
    return 0;
  }
  if(p==0 or p==q){
    cout<<-1<<newl;
    return 0;
  }

  Int a=(p-x%p)%p;
  Int b=(q-y%q)%q;

  Int u=(x+a)/p;
  Int v=(y+b)/q;

  if(u<v) a+=(v-u)*p;
  u=(x+a)/p;v=(y+b)/q;
  if(u>v) b+=(u-v)*q;
  u=(x+a)/p;v=(y+b)/q;

  if(a<=b){
    cout<<b<<newl;
    return 0;
  }

  Int d=(a-b+(q-p-1))/(q-p);
  a+=d*p;b+=d*q;
  u=(x+a)/p;v=(y+b)/q;
  assert(a<=b);

  cout<<b<<newl;
  return 0;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  Int T;
  cin>>T;
  for(Int t=0;t<T;t++) solve();
  return 0;
}