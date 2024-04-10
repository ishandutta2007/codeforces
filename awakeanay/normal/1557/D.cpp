#include <iostream>
#include <algorithm>
#include <vector>

#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

int M;

struct seg
{
  std::vector<std::pair<int, int> > lazy, arr;

  void push(int id, int l, int r) {
    if(lazy[id].first > -1) {
      arr[left] = std::max(arr[left], lazy[id]);
      arr[right] = std::max(arr[right], lazy[id]);
      lazy[left] = std::max(lazy[left], lazy[id]);
      lazy[right] = std::max(lazy[right], lazy[id]);
      lazy[id] = {-1, -1};
    }
  }

  void update(int x, int y, std::pair<int, int> v, int id = 0, int l = 0, int r = M-1) {
    if(y < l || r < x)
      return;

    if(x <= l && r <= y) {
      lazy[id] = std::max(lazy[id], v);
      arr[id] = std::max(arr[id], v);
      return;
    }

    push(id, l, r);
    update(x, y, v, left, l, mid);
    update(x, y, v, right, mid+1, r);

    arr[id] = std::max(arr[left], arr[right]);
  }

  std::pair<int, int> query(int x, int y, int id = 0, int l = 0, int r = M-1) {
    if(y < l || r < x)
      return {-1, -1};

    if(x <= l && r <= y)
      return arr[id];

    push(id, l, r);
    return std::max(query(x, y, left, l, mid), query(x, y, right, mid+1, r));
  }
};

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  std::vector<int> compress;
  std::vector<std::pair<int, int> > arr[n];

  for(int i = 0; i < m; i++) {
    int j, l, r;
    std::cin >> j >> l >> r;
    arr[j-1].push_back({l, r});
    compress.push_back(l-1);
    compress.push_back(l);
    compress.push_back(l+1);
    compress.push_back(r-1);
    compress.push_back(r);
    compress.push_back(r+1);
  }

  std::sort(compress.begin(), compress.end());

  M = compress.size();
  seg tree;
  tree.arr = tree.lazy = std::vector<std::pair<int, int> >(2*M-1, {0, -1});

  int last[n];
  std::pair<int, int> best = {-1, -1};
  for(int i = 0; i < n; i++) {
    std::pair<int, int> cur = {-1, -1};
    for(int j = 0; j < arr[i].size(); j++) {
      arr[i][j].first = std::lower_bound(compress.begin(), compress.end(), arr[i][j].first)-compress.begin();
      arr[i][j].second = std::lower_bound(compress.begin(), compress.end(), arr[i][j].second)-compress.begin();
      cur = std::max(cur, tree.query(arr[i][j].first, arr[i][j].second));
    }

    last[i] = cur.second;
    cur.first += 1;
    cur.second = i;
    best = std::max(best, cur);

    for(auto j : arr[i]) {
      tree.update(j.first, j.second, cur);
    }
  }

  std::vector<int> mark(n, 0);
  int cur = best.second;
  while(cur != -1) {
    mark[cur] = 1;
    cur = last[cur];
  }

  std::vector<int> ans;
  for(int i = 0; i < n; i++)
    if(!mark[i])
      ans.push_back(i+1);

  std::cout << ans.size() << std::endl;
  for(int j : ans)
    std::cout << j << " ";
  std::cout << std::endl;

  return 0;
}