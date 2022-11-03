#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
signed main(){
  int n;
  scanf("%lld",&n);
  int a[n],b[n];
  for(int i=0;i<n;i++) scanf("%lld",a+i);
  for(int i=0;i<n;i++) scanf("%lld",b+i);
  
  map<int,int> ma,mb;
  for(int i=0;i<n;i++) ma[a[i]]=i;
  for(int i=0;i<n;i++) mb[b[i]]=i;
  int c[n];
  memset(c,-1,sizeof(c));
  set<P> s1,s2,s3,s4;
  for(int i=0;i<n;i++){
    if(i<=mb[a[i]]){
      s1.insert(P(mb[a[i]]-i,i));
    }
    if(i>=mb[a[i]]){
      s2.insert(P(i-mb[a[i]],mb[a[i]]));
      s4.insert(P(mb[a[i]],i-mb[a[i]]));
    }
  }
  int ans[n];
  for(int i=0;i<n;i++){
    ans[i]=1LL<<55LL;
    if(!s1.empty()) ans[i]=min(ans[i],s1.begin()->first-i);
    if(!s2.empty()) ans[i]=min(ans[i],s2.begin()->first+i);

    while(!s1.empty()&&s1.begin()->first==i){
      //cout<<s1.begin()->first<<"+"<<s1.begin()->second<<endl;
      //cout<<-i<<"*"<<i+s1.begin()->second<<endl;
      s2.insert(P(-i,i+s1.begin()->second));
      s4.insert(P(i+s1.begin()->second,-i));
      s1.erase(s1.begin());
    }
    
    while(!s4.empty()&&s4.begin()->first==i){
      //cout<<s4.begin()->first<<"-"<<s4.begin()->second<<endl;
      //cout<<i+n-ma[b[i]]<<"/"<<(1LL<<55LL)<<endl;
      s1.insert(P(i+n-ma[b[i]],1LL<<55LL));
      s2.erase(P(s4.begin()->second,s4.begin()->first));
      s4.erase(s4.begin());
    }
    
  }
  
  for(int i=0;i<n;i++) printf("%lld\n",ans[i]);
  return 0;
}