#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n;
  double h;
  scanf("%lld %lf",&n,&h);
  for(int i=1;i<n;i++){
    double tmp=sqrt(h*h/(double)n*i);
    if(i-1) printf(" ");
    printf("%.12f",tmp);
  }
  puts("");
  return 0;
}