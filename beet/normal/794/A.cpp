#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int a,b,c;
  scanf("%lld %lld %lld",&a,&b,&c);
  int n;
  scanf("%lld",&n);
  int x[n];
  for(int i=0;i<n;i++) scanf("%lld",x+i);
  int ans=0;
  for(int i=0;i<n;i++){
    if(b<x[i]&&x[i]<c) ans++;
  }
  printf("%lld\n",ans);
  return 0;
}