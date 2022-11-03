#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
void NO(){
  printf("No\n");
  exit(0);
}
void YES(vector<Int> p,vector<Int> q){
  printf("Yes\n");
  printf("%lld %lld\n",(Int)p.size(),(Int)q.size());
  for(Int i=0;i<(Int)p.size();i++){
    if(i) printf(" ");
    printf("%lld",p[i]+1);
  }
  printf("\n");
  for(Int i=0;i<(Int)q.size();i++){
    if(i) printf(" ");
    printf("%lld",q[i]+1);
  }
  printf("\n");
  exit(0);
}


signed main(){
  Int n,x,y;
  scanf("%lld %lld %lld",&n,&x,&y);
  vector<Int> c(n);
  for(Int i=0;i<n;i++) scanf("%lld",&c[i]);

  vector<Int> ord(n);
  iota(ord.begin(),ord.end(),0);
  sort(ord.begin(),ord.end(),
       [&](Int i,Int j){return c[i]<c[j];});
  
  for(Int t=0;t<2;t++){
    vector<Int> p,q;
  
    Int k=1;
    while(k<=n){
      q.emplace_back(ord[n-k]);
      if((y+k-1)/k<=c[ord[n-k]]) break;
      if(k++==n) NO();
    }
    //cout<<k<<endl;
    
    Int j=0;
    for(Int i=n;i>=1;i--){
      Int z=(x+i-1)/i;
      while(j<n&&c[ord[j]]<z) j++;
      if(j==n) break;
      //cout<<i<<" "<<j<<":"<<j+i-1<<" "<<n-k<<endl;
      if(j+i-1<n-k){
	for(Int a=0;a<i;a++) p.emplace_back(ord[j+a]);
	break;
      }
    }
    if(!p.empty()){
      if(!t) YES(p,q);
      else   YES(q,p);
    }
    swap(x,y);
  }
  NO();
  return 0;
}