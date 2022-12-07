#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#define maxn 10005
using namespace std;
typedef long long ll;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = getchar();c < '0' || c > '9';c = getchar()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
  return res * sig;
}
int n;
struct Point{
  int x,y;
  Point(int x = 0,int y = 0): x(x), y(y) {}
  bool operator < (const Point &p){
    if(x == p.x) return y < p.y;
    return x < p.x;
  }
  bool operator == (const Point &p){
    return x == p.x && y == p.y;
  }
};
Point p[maxn];
vector <Point> ps;
void solve(int l,int r){
  if(l > r) return;
  if(l == r){
    ps.push_back(p[l]);
    return;
  }
  int mid = (l + r) >> 1;
  solve(l,mid - 1);
  solve(mid + 1,r);
  for(int i = l;i <= r;i++) ps.push_back(Point(p[mid].x,p[i].y));
}
int main(){
  n = getint();
  for(int i = 1;i <= n;i++) p[i].x = getint(), p[i].y = getint();
  sort(p + 1,p + n + 1);
  solve(1,n);
  sort(ps.begin(),ps.end());
  ps.erase(unique(ps.begin(),ps.end()),ps.end());
  int m = ps.size();
  printf("%d\n",m);
  for(int i = 0;i < m;i++) printf("%d %d\n",ps[i].x,ps[i].y);
  return 0;
}