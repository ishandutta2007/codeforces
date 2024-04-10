#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

const int MAXM = 2000000;

const int LOG = 30;
std::set<int> store[MAXM];
int trie[MAXM][2];
int free_id;

int test(int id, int v) {
  if(store[id].empty())
    return -2;
  auto u = store[id].upper_bound(v);
  if(u == store[id].begin())
    return -2;
  u--;
  if(u == store[id].begin())
    return *u;
  return -1;
}

std::vector<std::pair<int, int> > temp;

void ensure(int x) {
  for(int u = 0; u < 2; u++) {
    if(trie[x][u] == 0) {
      store[free_id].clear();
      trie[free_id][0] = trie[free_id][1] = 0;
      trie[x][u] = free_id++;
    }
  }
}

void insert(int x, int v, int sv = 0) {
  int cur = 0;
  if(sv && !store[cur].count(x)) {
    temp.push_back({cur, x});
  }
  store[cur].insert(x);
  for(int i = LOG-1; i >= 0; i--) {
    int u = (v >> i)&1;
    if(trie[cur][u])
      cur = trie[cur][u];
    else {
      store[free_id].clear();
      trie[free_id][0] = trie[free_id][1] = 0;
      cur = trie[cur][u] = free_id++;
    }
    if(sv && !store[cur].count(x)) {
      temp.push_back({cur, x});
    }
    store[cur].insert(x);
  }
}

void remove(int x, int v) {
  int cur = 0;
  store[cur].erase(x);
  for(int i = LOG-1; i >= 0; i--) {
    int u = (v >> i)&1;
    cur = trie[cur][u];
    store[cur].erase(x);
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    int q;
    std::cin >> q;
    std::pair<std::pair<int, int>, int> qs[q];

    int ans[q];
    for(int i = 0; i < q; i++) {
      int l, r;
      std::cin >> l >> r;
      l--; r--;
      qs[i] = {{l, r}, i};
    }

    std::sort(qs, qs+q);
    std::reverse(qs, qs+q);
    int it = 0;

    free_id = 1;
    store[0].clear();
    trie[0][0] = trie[0][1] = 0;

    for(int i = n-1; i >= 0; i--) {
      insert(i, a[i]);

      while(it < q && qs[it].first.first == i) {
        int l = qs[it].first.first;
        int r = qs[it].first.second;
        int pos = qs[it].second;

        int cur = 0;
        int form = 0;
        for(int j = LOG-1; j >= 0; j--) {
          ensure(cur);
          int work = test(trie[cur][0], r);
          if(work == -1) {
            cur = trie[cur][0];
          }
          else {
            cur = trie[cur][1];
            form |= (1 << j);

            if(work != -2) {
              int ch = form | (a[work]&((1 << j)-1));
              insert(work, ch, 1);
            }
          }
        }

        ans[pos] = form;

        for(auto u : temp)
          store[u.first].erase(u.second);
        temp.clear();

        it++;
      }
    }

    for(int i = 0; i < q; i++)
      std::cout << ans[i] << "\n";
  }

  return 0;
}