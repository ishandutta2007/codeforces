#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

#define int long long

const int MAXN = 500005;

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

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    for(int i = 0; i <= n; i++)
      bit[i] = 0;

    std::pair<int, int> help[n];
    for(int i = 0; i < n; i++) {
      std::cin >> help[i].first;
      help[i].second = i;
    }

    if(n < 3) {
      bool sorted = true;
      for(int i = 0; i+1 < n; i++) {
        if(help[i] > help[i+1])
          sorted = false;
      }

      std::cout << (sorted ? "YES" : "NO") << std::endl;
      continue;
    }

    /*
    if(n < 7) {
      std::map<std::vector<int>, int> mp;

      std::vector<int> id;
      std::queue<std::vector<int> > bfs;
      for(int i = 0; i < n; i++) {
        id.push_back(i);
      }

      bfs.push(id);
      mp[id] = 1;
      bool poss = 0;

      int ct = 0;
      while(!bfs.empty()) {
        ct++;
        std::vector<int> cur = bfs.front();
        bfs.pop();

        for(int i = 0; i < n; i++) {
          std::cout << cur[i] << " ";
        }
        std::cout << std::endl;
        bool sorted = true;
        for(int i = 0; i+1 < n; i++) 
          if(help[cur[i]].first > help[cur[i+1]].first)
            sorted = false;

        poss |= sorted;

        for(int i = 0; i < n; i++) {
          for(int j = 0; j < n; j++) {
            if(j == i)
              continue;
            for(int k = 0; k < n; k++) {
              if(j == k || i == k)
                continue;
              std::vector<int> next = cur;
              next[i] ^= next[j] ^= next[i] ^= next[j];
              next[j] ^= next[k] ^= next[j] ^= next[k];

              if(mp[next])
                continue;

              //std::cout << i << " " << j << " " << k << std::endl;

              mp[next] = 1;
              bfs.push(next);
            }
          }
        }
      }

      std::cout << ct << " HERE" << std::endl;

      std::cout << (poss ? "YES" : "NO") << std::endl;
      continue;
    }
    */

    std::set<int> set;
    int done = 0;
    for(int i = 0; i < n; i++) {
      if(set.count(help[i].first))
        done = 1;
      set.insert(help[i].first);
    }

    if(done) {
      std::cout << "YES" << std::endl;
      continue;
    }

    std::sort(help, help+n);

    int cur = 0;
    for(int i = n-1; i >= 0; i--) {
      cur += sum(help[i].second);
      add(help[i].second, 1);
    }

    std::cout << (cur%2 == 0 ? "YES" : "NO") << std::endl;
  }

  return 0;
}