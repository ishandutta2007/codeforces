#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 30000;
int const statemax = 125;
ll const inf = 1000000000000000000;

std::map<int, std::pair<int,int>> rev;
std::map<std::pair<int,int>, int> mp;

int combine(int id1, int id2) {
  int sz = rev[id1].first + rev[id2].first - 4;
  int mask = rev[id1].second ^ (rev[id2].second<<(rev[id1].first - 4));
  int realmask = 0;

  if(__builtin_popcount(mask) != rev[id1].first + rev[id2].first - 8)
    return 0;

  for(int i = sz - 1; 0 <= i; i--)
    if(i <= 3 || sz - 4 <= i)
      realmask = realmask * 2 + (0 < (mask & (1 << i)));
  sz = std::min(sz, 8);

  return mp[{sz, realmask}];
}

struct Event{
  int x;
  int y;
  int result;
};

std::vector<Event> _all;

std::map<std::pair<int,int>, int> quickcombine;

void generate(int &ptr) {
  for(int total = 5; total <= 8; total++)
    for(int mask = 0; mask < (1 << total); mask++)
      if(__builtin_popcount(mask) == total - 4) {
        rev[++ptr] = {total, mask};
        mp[{total, mask}] = ptr;
      }
  
  for(int i = 1;i <= ptr; i++)
    for(int j = 1;j <= ptr; j++) {
      int res = combine(i, j);
      if(1 <= res) {
        quickcombine[{i, j}] = res;

        _all.push_back({i, j, res});
      }
    }
}
int n;

std::pair<int,int> warrior[1 + nmax], horse[1 + nmax];
int where[1 + nmax], where2[1 + nmax];
ll dp[1 + 4 * nmax][1 + statemax];

void computenode(int node, int from, int to) {
  if(from < to) {
    for(int i = 1;i <= statemax; i++)
      dp[node][i] = -inf;
    for(int i = 0; i < _all.size(); i++)
      dp[node][_all[i].result] = std::max(dp[node][_all[i].result], dp[node * 2][_all[i].x] + dp[node * 2 + 1][_all[i].y]);
  }
}


void setnode(int node, int from) {
  for(int i = 1; i <= statemax; i++)
    dp[node][i] = -inf;
  int start = std::max(from - 2, 1), stop = std::min(from + 2, n);
  for(int i = start; i <= stop; i++)
    if(warrior[from].second != horse[i].second)
      dp[node][i - (from - 2) + 1] = 1LL * warrior[from].first * horse[i].first;
}


void build(int node, int from, int to) {
  if(from < to) {
    int mid = (from + to ) / 2;
    build(node * 2, from, mid);
    build(node * 2 + 1, mid + 1, to);
    computenode(node, from, to);
  } else
    setnode(node, from);
}

void update(int node, int from, int to, int x) {
  if(from < to) {
    int mid = (from + to) / 2;
    if(x <= mid)
      update(node * 2, from, mid, x);
    else
      update(node * 2 + 1, mid + 1, to, x);
    computenode(node, from, to);
  } else
    setnode(node, from);
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int ptr = 0;
  generate(ptr);

  int q;
  std::cin >> n >> q;
  for(int i = 1;i <= n; i++)  {
    std::cin >> warrior[i].first;
    warrior[i].second = i;
  }
  std::sort(warrior + 1, warrior + n + 1);
  for(int i = 1; i <= n; i++) 
    where[warrior[i].second] = i;

  for(int i = 1;i <= n; i++) {
    std::cin >> horse[i].first;
    horse[i].second = i;
  }
  std::sort(horse + 1, horse + n + 1);
  for(int i = 1; i <= n; i++) 
    where2[horse[i].second] = i;
  
  build(1, 1, n);
  
  int target = 3;
  for(int i = 2;i <= n; i++)
    target = quickcombine[{target, 3}];

  for(int i = 1;i <= q; i++) {
    int x, y;
    std::cin >> x >> y;
    int posx = where2[x], posy = where2[y];
    std::swap(horse[posx].second, horse[posy].second);
    std::swap(where2[x], where2[y]);
    update(1, 1, n, where[x]);
    update(1, 1, n, where[y]);
    std::cout << dp[1][target] << '\n';
  }
  return 0;
}