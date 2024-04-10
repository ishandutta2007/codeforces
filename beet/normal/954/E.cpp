#include<bits/stdc++.h>
using namespace std;
using Int = long long;

//INSERT ABOVE HERE
signed main(){
  Int n;
  double d;
  scanf("%lld %lf",&n,&d);
  vector<double> a(n),t(n);
  for(Int i=0;i<n;i++) scanf("%lf",&a[i]);
  for(Int i=0;i<n;i++) scanf("%lf",&t[i]);
  
  {
    using P = pair<double, double>;
    vector<P> v(n);
    for(Int i=0;i<n;i++) v[i]=P(t[i],a[i]);
    sort(v.begin(),v.end());
    for(Int i=0;i<n;i++) tie(t[i],a[i])=v[i];
  }

  auto check=[&](double x){
    double mi=0,ma=0;
    double l=x;
    for(Int i=0;i<n;i++){
      double k=min(a[i],l);
      mi+=k*t[i];
      l-=k;
    }
    l=x;
    for(Int i=n-1;i>=0;i--){
      double k=min(a[i],l);
      ma+=k*t[i];
      l-=k;
    }
    return mi<=d*x&&d*x<=ma;
  };
  
  double L=0,R=accumulate(a.begin(),a.end(),0.0d);
  for(Int i=0;i<200;i++){
    double M=(L+R)/2;
    if(check(M)) L=M;
    else R=M;
  }
  printf("%.12f\n",L);
  return 0;
}