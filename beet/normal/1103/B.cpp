#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';


template<typename T>
map<T, int> factorize(T x){
  map<T, int> res;
  for(int i=2;i*i<=x;i++){
    while(x%i==0){
      x/=i;
      res[i]++;
    }
  }
  if(x!=1) res[x]++;
  return res;
}

//INSERT ABOVE HERE
const int LOCAL = 0;
const int ANS = 1000000000;

char ask(int x,int y){
  cout<<"? "<<x<<" "<<y<<endl;
  if(LOCAL) return (x%ANS)>=(y%ANS)?'x':'y';
  char c;
  cin>>c;
  return c;
}

void answer(int a){
  cout<<"! "<<a<<endl;
  if(LOCAL) assert(a==ANS);
}

signed main(){
  string cmd;
  while(cin>>cmd,cmd!="end"){
    assert(cmd=="start");
    mt19937 mt;
    uniform_int_distribution<int> ud(1,2e9);

    if(ask(2,1)=='y'){
      answer(2);
      continue;
    }

    if(ask(1,2)=='x'){
      answer(1);
      continue;
    }

    using ll = long long;
    ll l=-1,r=-1;
    for(int k=0;k<20;k++){
      ll x=ud(mt);
      ll y=ud(mt);
      while(x==y) x=ud(mt),y=ud(mt);
      if(x>y) swap(x,y);
      if(ask(x,y)=='x'){
        l=x;
        r=y;
        break;
      }
    }
    assert(~l);

    // l <= a
    // r >  a
    while(l+1<r){
      ll m=(l+r)>>1;
      char c=ask(l,m);
      if(c=='x') r=m;
      else l=m;
    }
    // cout<<l<<' '<<r<<endl;

    auto pow=[&](ll n,ll k){
      ll x=1;
      for(ll i=0;i<k;i++) x*=n;
      return x;
    };
    auto mp=factorize(r);
    ll ans=r;

    for(auto p:mp){
      ll t=p.first;
      ll L=0,R=p.second+1;

      // cout<<t<<' '<<p.second<<':'<<r<<':'<<r/pow(t,p.second)<<endl;
      // assert(ask(ans/pow(t,L),1)=='y');

      // ask(ans/pow(t,L),1)=='y'
      // ask(ans/pow(t,R),1)!='y'
      while(L+1<R){
        ll M=(L+R)>>1;
        if(ask(ans/pow(t,M),1)=='y') L=M;
        else R=M;
      }
      ans/=pow(t,L);
    }

    answer(ans);
  }
  return 0;
}