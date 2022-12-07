#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>

using namespace std;
typedef long long ll;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = getchar();c < '0' || c > '9';c = getchar()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
  return res * sig;
}
int n;
vector <int> a,b;//a: >= 0, b: < 0.
int main(){
  n = getint();
  for(int i = 1;i <= n;i++){
    int x = getint();
    if(x >= 0) a.push_back(x);
    else b.push_back(x);
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  int na = a.size(), nb = b.size();
  ll ans = 0;
  for(int i = 0;i < na;i++){
    ans += upper_bound(a.begin(),a.end(),2 * a[i]) - a.begin() - i - 1;
  }
  for(int i = nb - 1;i >= 0;i--){
    ans += i - (lower_bound(b.begin(),b.end(),2 * b[i]) - b.begin());
  }
  for(int i = 0;i <= nb - 1;i++){
    ans += upper_bound(a.begin(),a.end(),2 * -b[i]) - lower_bound(a.begin(),a.end(),-b[i]);
  }
  for(int i = 0;i <= na - 1;i++){
    ans += lower_bound(b.begin(),b.end(),-a[i]) - lower_bound(b.begin(),b.end(),2 * -a[i]);
  }
  printf("%I64d\n",ans);
  return 0;
}