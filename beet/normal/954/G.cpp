#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed main(){
  Int n,r,k;
  scanf("%lld %lld %lld",&n,&r,&k);
  vector<Int> a(n);
  for(Int i=0;i<n;i++) scanf("%lld",&a[i]);

  auto check=[&](Int x){
    Int cnt=0;
    using P = pair<Int, Int>;
    queue<P> q;
    Int tmp=0;
    for(Int i=0;i<r;i++) tmp+=a[i];
    
    for(Int i=0;i<n;i++){
      while(!q.empty()&&q.front().first<i){
	tmp-=q.front().second;
	q.pop();
      }
      
      if(i+r<n) tmp+=a[i+r];
      if(i-r>0) tmp-=a[i-r-1];
      
      Int dif=x-tmp;
      if(dif<=0) continue;
      cnt+=dif;
      tmp+=dif;
      q.emplace(i+r*2,dif);
      //if(cnt>k) cout<<x<<":"<<cnt<<endl;
      if(cnt>k) return false;
    }
    //cout<<x<<":"<<cnt<<endl;
    return cnt<=k;
  };
  
  Int L=0,R=accumulate(a.begin(),a.end(),k)+1;
  while(L+1<R){
    Int M=(L+R)>>1;
    if(check(M)) L=M;
    else R=M;
  }
  printf("%lld\n",L);
  return 0;
}