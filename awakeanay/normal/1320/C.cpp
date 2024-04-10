/*
Author: AwakeAnay
Date: 01/03/2020
Time: 19:37:33
*/

#include <iostream>
#include <algorithm>
#include <vector>

#define int long long 
#define INF 1000000000000000000
#define MAX 1200005

std::vector<int> seg(4*MAX+5, -INF);
int lazy[4*MAX+5];
std::vector<int> minA(MAX, INF);
std::vector<int> minD(MAX, INF);

int n, m, p;

void build(int x = 0, int y = MAX-1, int id = 1) {
  if(x == y) {
    seg[id] = -minD[x];
    return;
  }

  int m = (x+y)/2;
  build(x, m, 2*id);
  build(m+1, y, 2*id+1);
  
  seg[id] = std::max(seg[2*id], seg[2*id+1]);
}

void push(int id) {
  lazy[2*id] += lazy[id];
  lazy[2*id+1] += lazy[id];
  seg[2*id] += lazy[id];
  seg[2*id+1] += lazy[id];
  lazy[id] = 0;
}

void upd(int x, int y, int val, int l = 0, int r = MAX-1, int id = 1) {
  if(x <= l && r <= y) {
    seg[id] += val;
    lazy[id] += val;
    return;
  }

  if(y < l || x > r)
    return;

  push(id);
  int m = (l+r)/2;
  upd(x, y, val, l, m, 2*id);
  upd(x, y, val, m+1, r, 2*id+1);

  seg[id] = std::max(seg[2*id], seg[2*id+1]);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> n >> m >> p;

  for(int i = 0; i < n; i++) {
    int a, ca;
    std::cin >> a >> ca;
    minA[a] = std::min(minA[a], ca);
  }

  for(int i = 0; i < m; i++) {
    int d, cd;
    std::cin >> d >> cd;
    minD[d] = std::min(minD[d], cd);
  }

  for(int i = MAX-2; i >= 0; i--) {
    minD[i] = std::min(minD[i+1], minD[i]);
    minA[i] = std::min(minA[i], minA[i+1]);
  }

  int ans = 0 - minA[0] - minD[0];

  build();

  std::pair<std::pair<int, int>, int> mon[p];
  for(int i = 0; i < p; i++)
    std::cin >> mon[i].first.first >> mon[i].first.second >> mon[i].second;

  std::sort(mon, mon+p);

  for(int i = 0; i < p; i++) {
    upd(mon[i].first.second+1, MAX-5, mon[i].second);
    ans = std::max(ans, seg[1] - minA[mon[i].first.first+1]);
  }

  std::cout << ans << std::endl;

  return 0;
}