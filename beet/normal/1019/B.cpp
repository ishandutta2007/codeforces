#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE

const Int DBG = 0;
vector<Int> v({1,2});
	      
Int n;
Int ask(Int k){
  assert(0<=k&&k<n);
  cout<<"? "<<k+1<<endl;
  if(DBG) return v[k];
  cin>>k;
  return k;
}

Int answer(Int k){
  if(DBG&&0<=k) assert(v[k]==v[k+n/2]);
  cout<<"! "<<k+1<<endl;
  exit(0);
}

Int diff(Int a){
  Int b=a+n/2;
  Int x=ask(a);
  Int y=ask(b);
  if(x==y) answer(a);
  return y-x;
}

signed main(){
  if(DBG) n=v.size();
  if(!DBG) cin>>n;
  
  if(n%4==2) answer(-2);
  
  Int l=0,r=n/2;
  Int p=diff(l);
  while(l+1<r){
    Int m=(l+r)>>1;
    Int d=diff(m);
    if(p*d>0){
      p=d;
      l=m;
    }else{
      r=m;
    }
  }
  diff(l);
  diff(r);
  return 0;
}