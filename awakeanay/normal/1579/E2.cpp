#include <iostream>
#include <set>
#include <vector>

#define int long long

const int MAXN = 200005;

int bit[MAXN];

void add(int x, int v) {
  x += 1;
  while(x < MAXN) {
    bit[x] += v;
    x += x&(-x);
  }
}

int sum(int x) {
  x += 1;
  int ret = 0;
  while(x > 0) {
    ret += bit[x];
    x -= x&(-x);
  }
  return ret;
}

std::vector<int> comp;
std::set<int> help;
int a[MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    comp = std::vector<int>(0);

    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      help.insert(a[i]);
    }

    while(!help.empty()) {
      int u = *help.begin();
      comp.push_back(u);
      help.erase(help.begin());
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
      int j = std::lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
      a[i] = j;
      int c1 = sum(j-1);
      int c2 = sum(j);
      ans += std::min(c1, i-c2);
      add(j, 1);
    }

    for(int i = 0; i < n; i++)
      add(a[i], -1);

    std::cout << ans << std::endl;
  }

  return 0;
}