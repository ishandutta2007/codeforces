#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#include <cassert>
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
P s[maxn];
int n,m,t[maxn],d[maxn];
ll sums,sumt;
struct node{
  int a,b,c;
  node(int a = 0,int b = 0,int c = 0): a(a),b(b),c(c) {}
}ans[maxn * 5]; int ak;
int main(){
  n = getint();
  for(int i = 1;i <= n;i++){
    s[i] = mp(getint(),i);
    sums += s[i].first;
  }
  for(int i = 1;i <= n;i++) t[i] = getint(), sumt += t[i];
  if(sums != sumt){
    puts("NO");
    return 0;
  }
  sort(s + 1,s + n + 1);
  sort(t + 1,t + n + 1);
  for(int i = 1;i <= n;i++) d[i] = t[i] - s[i].first;
  ll sd = 0;
  for(int i = 1;i <= n;i++){
    sd += d[i];
    if(sd < 0){
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  queue <ll> que;
  for(int i = 1;i <= n;i++){
    if(d[i] > 0) que.push(i);
    else if(d[i] < 0){
      while(true){
        int j = que.front();
        if(d[j] + d[i] >= 0){
          ans[++ak] = node(s[j].second,s[i].second,-d[i]);
          s[j].first -= d[i];
          s[i].first += d[i];
          d[j] += d[i];
          d[i] = 0;
          if(d[j] == 0) que.pop();
          break;
        }else{
          ans[++ak] = node(s[j].second,s[i].second,d[j]);
          s[j].first += d[j];
          s[i].first -= d[j];
          d[i] += d[j];
          d[j] = 0;
          que.pop();
        }
      }
    }
  }
  printf("%d\n",ak);
  for(int i = 1;i <= ak;i++){
    printf("%d %d %d\n",ans[i].a,ans[i].b,ans[i].c);
  }
  return 0;
}