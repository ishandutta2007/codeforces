#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
typedef long long ll;
const int LEN = 100000;

struct fastio{
  int it,len;
  char s[LEN + 5];
  fastio(){
    it = len = 0;
  }
  char get(){
    if(it < len) return s[it++];
    it = 0, len = fread(s,1,LEN,stdin);
    return len ? s[it++] : EOF;
  }
  bool notend(){
    char c;
    for(c = get();c == ' ' || c == '\n';c = get());
    if(it) it--;
    return c != EOF;
  }
  void put(char c){
    if(it == LEN) fwrite(s,1,LEN,stdout), it = 0;
    s[it++] = c;
  }
  void flush(){
    fwrite(s,1,it,stdout);
  }
}buff;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = buff.get();c < '0' || c > '9';c = buff.get()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline ll getll(){
  char c; ll res = 0, sig = 1;
  for(c = buff.get();c < '0' || c > '9';c = buff.get()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
#define maxn 1000005
struct Point{
  ll x, y;
  Point(ll x = 0, ll y = 0): x(x), y(y) {}
  Point operator - (Point p){
    return Point(x - p.x, y - p.y);
  }
};
ll det(Point a, Point b){
  return a.x * b.y - a.y * b.x;
}
int n, a[maxn];
ll s[maxn];
int con[maxn << 1], k;
Point gp(ll x){
  return Point(x,s[x]);
}
int main(){
  n = getint();
  for(int i = 1;i <= n;i++) s[i] = s[i - 1] + (a[i] = getint());
  for(int i = 0;i <= n;i++){
    while(k > 1 && det(gp(i) - gp(con[k]), gp(con[k - 1]) - gp(con[k])) < 0) k--;
    con[++k] = i;
  }
  for(int i = 1;i < k;i++){
    double val = 1.0 * (s[con[i + 1]] - s[con[i]]) / (con[i + 1] - con[i]);
    for(int j = con[i] + 1;j <= con[i + 1];j++){
      printf("%.12f\n",val);
    }
  }
  return 0;
}