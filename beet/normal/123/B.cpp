#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  Int a,b,x1,y1,x2,y2;
  cin>>a>>b>>x1>>y1>>x2>>y2;
  using P = pair<Int, Int>;
  auto calc=[&](Int x,Int y){
    P p;
    {  
      Int k=(y-x)/(2*b);
      while(x+2*b*(k-1)>y) k--;
      while(x+2*b*k<y) k++;
      //cout<<k<<":"<<x<<" "<<y<<":"<<x+2*b*k<<endl;
      assert(y<x+2*b*k&&x+2*b*k<y+2*b);
      p.first=k;
    }
    {  
      Int k=(y+x)/(2*a);
      while(-x+2*a*(k-1)>y) k--;
      while(-x+2*a*k<y) k++;
      //cout<<k<<":"<<x<<" "<<y<<":"<<-x+2*a*k<<endl;
      assert(y<-x+2*a*k&&-x+2*a*k<y+2*a);
      p.second=k;
    }
    return p;
  };
  auto p1=calc(x1,y1);
  auto p2=calc(x2,y2);
  cout<<max(abs(p1.first-p2.first),abs(p1.second-p2.second))<<endl;
  return 0;
}