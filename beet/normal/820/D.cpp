#include<bits/stdc++.h>
using namespace std;
#define int long long
struct BIT{
  vector<int> bit;
  int n;
  //1-indexed
  BIT(){init();}
  BIT(int n):n(n){init();}
  void init(){
    bit.clear();
    bit.resize(n+1,0);
  }
  int sum(int i){
    int s=0;
    while(i>0){
      s+=bit[i];
      i-=i&-i;
    }
    return s;
  }
  void add(int i,int x){
    while(i<=n){
      bit[i]+=x;
      i+=i&-i;
    }
  }
  int sum0(int i){
    return sum(i+1);
  }
  void add0(int i,int x){
    add(i+1,x);
  }
  int sumn(int i,int o){
    return sum(i+o);
  }
  void addn(int i,int x,int o){
    add(i+o,x);
  }
};

signed main(){
  int n;
  scanf("%lld",&n);
  vector<int> p(n);
  for(int i=0;i<n;i++) scanf("%lld",&p[i]);
  int tmp=0;
  BIT bit(n*2);
  for(int i=0;i<n;i++){
    tmp+=abs(p[i]-(i+1));
    bit.addn(p[i]-(i+1),1,n);
  }
  //cout<<0<<":"<<tmp<<endl;
  int ans=tmp,idx=0;
  for(int i=1;i<n;i++){
    // erase the last element
    tmp-=abs(p[n-i]-n);
    bit.addn(p[n-i]-(n-i+1),-1,n);

    // move forward (count under i)
    int k=bit.sumn(i-1,n);
    tmp+=k;
    tmp-=((n-1)-k);

    // insert to the front
    tmp+=abs(p[n-i]-1);
    bit.addn(p[n-i]-1+i,1,n);

    if(tmp<ans){
      ans=tmp;
      idx=i;
    }

    //cout<<i<<":"<<tmp<<" "<<k<<endl;
  }
  printf("%lld %lld\n",ans,idx);
  return 0;
}