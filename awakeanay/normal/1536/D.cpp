#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define int long long

const int INF = 10000000000;
const int MAXN = 300005;

int bit[MAXN];

void add(int x) {
  x += 1;
  while(x < MAXN) {
    bit[x]++;
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

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    for(int i = 0; i < n+10; i++)
      bit[i] = 0;

    std::set<int> cur;

    bool poss = true;
    int a[n];
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      a[i] = x;
      cur.insert(x);
    }

    std::vector<int> help;
    for(int j : cur)
      help.push_back(j);

    int last = 1;
    for(int i = 0; i < n; i++) {
      int pos = std::lower_bound(help.begin(), help.end(), a[i])-help.begin();
      int x = pos, y = last;
      if(x > y)
        x ^= y ^= x ^= y;

      int val = sum(y-1)-sum(x);
      add(pos);
      if(val > 0) {
        poss = false;
      }
      last = pos;
    }

    std::cout << (poss ? "YES" : "NO") << std::endl;
  }

  return 0;
}