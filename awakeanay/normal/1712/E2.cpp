#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

const int MAXN = 400005;
const int MAXB = 200005;

int bit[MAXB];

std::vector<int> divi[MAXN];

void add(int x, int v) {
  x += 1;
  while(x < MAXB) {
    bit[x] += v;
    x += x&-x;
  }
}

int sum(int x) {
  x += 1;
  int ret = 0;
  while(x > 0) {
    ret += bit[x];
    x -= x&-x;
  }
  return ret;
}

std::vector<std::pair<int, int> > changes[MAXB];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  for(int i = 1; i <= MAXB; i++) {
    for(int j = 2*i; j <= MAXN; j += i)
      divi[j].push_back(i);
  }

  int t;
  std::cin >> t;
  //int trip = 0;

  for(int i = MAXB-1; i >= 1; i--) {
    int u = 2*i;
    int pos = divi[u].size();
    for(int j = 0; j < divi[u].size() && divi[u][j] < i; j++) {
      int ct = 0;
      while(pos > 0 && divi[u][pos-1] + divi[u][j] > i)
        pos--;
      //std::cout << j << " " << pos << std::endl;
      ct = divi[u].size()-1-std::max(pos, j+1);
      changes[divi[u][j]].push_back({i, ct});
    }
    //std::cout << trip << std::endl;
  }

  //std::cout << trip << std::endl;
  for(int i = MAXB-1; i >= 1; i--) {
    int u = i;
    int pos = divi[u].size()-1;
    for(int j = 0; j < divi[u].size() && divi[u][j] < i; j++) {
      while(pos > 0 && divi[u][pos-1] + divi[u][j] > i)
        pos--;
      //std::cout << j << " " << pos << std::endl;
      int ct = std::max(0ll, pos-j);
      changes[divi[u][j]].push_back({i, ct});
    }
  }
  std::pair<std::pair<int, int>, int> qs[t];

  for(int i = 0; i < t; i++) {
    std::cin >> qs[i].first.first >> qs[i].first.second;
    qs[i].second = i;
  }

  std::sort(qs, qs+t);
  std::reverse(qs, qs+t);

  int pt = MAXB-1;
  int ans[t];
  for(int i = 0; i < t; i++) {
    int l = qs[i].first.first;
    int r = qs[i].first.second;
    int ct = r-l+1;
    int trip = (ct*(ct-1)*(ct-2))/6;

    while(pt >= l) {
      for(std::pair<int, int> j : changes[pt]) {
        add(j.first, j.second);
      }
      pt--;
    }

    trip -= sum(r);
    ans[qs[i].second] = trip;
  }

  for(int i = 0; i < t; i++)
    std::cout << ans[i] << "\n";

  return 0;
}