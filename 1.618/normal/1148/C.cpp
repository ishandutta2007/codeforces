#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#define maxn 300005
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = getchar();c < '0' || c > '9';c = getchar()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
  return res * sig;
}
int n,p[maxn],id[maxn],m;
vector <P> ans;
void swap_near(int a,int b){
  if(a > b) swap(a,b);
  if(b - a >= m) ans.push_back(mp(a,b));
  else{
    if(a > m){
      ans.push_back(mp(1,a));
      ans.push_back(mp(1,b));
      ans.push_back(mp(1,a));
    }else if(b <= m){
      ans.push_back(mp(n,b));
      ans.push_back(mp(n,a));
      ans.push_back(mp(n,b));
    }else{
      ans.push_back(mp(n,a));
      ans.push_back(mp(1,n));
      ans.push_back(mp(1,b));
      ans.push_back(mp(1,n));
      ans.push_back(mp(n,a));
    }
  }
}
int main(){
  n = getint(); m = n / 2;
  for(int i = 1;i <= n;i++) p[i] = getint(), id[p[i]] = i;
  for(int i = 1;i <= n;i++){
    if(id[i] != i){
      swap_near(id[i],i);
      id[p[i]] = id[i];
      swap(p[id[i]],p[i]);
      id[i] = i;
    }
  }
  printf("%d\n",(int)ans.size());
  for(int i = 0;i < (int)ans.size();i++){
    printf("%d %d\n",ans[i].first,ans[i].second);
  }
  return 0;
}