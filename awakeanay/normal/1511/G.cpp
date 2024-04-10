#include <iostream>
#include <algorithm>
#include <vector>

const int LOG = 20;

std::vector<int> bit;

void add(int x, int id) {
  x += 1;
  while(x < bit.size()) {
    bit[x] ^= (1 << id);
    x += x&(-x);
  }
}

int sum(int x, int id) {
  x += 1;
  int ret = 0;
  while(x > 0) {
    ret ^= (bit[x] >> id)&1;
    x -= x&(-x);
  }
  return ret;
}

struct task
{
  int save, x;
};

void push(int x) {
  for(int i = 0; i < LOG; i++) {
    add(x%(1 << (i+1)), i);
  }
}

const int MAXM = 200005;

std::vector<task> list[MAXM];

signed main() {
  int n, m;
  std::cin >> n >> m;

  bit = std::vector<int>((1 << LOG)+1, 0);

  std::vector<int> a(m, 0);
  for(int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    x--;
    a[x] ^= 1;
  }

  int q;
  std::cin >> q;
  
  std::vector<int> query(q, 0);

  for(int i = 0; i < q; i++) {
    int l, r;
    std::cin >> l >> r;
    l--; r--;

    for(int j = 0; j < LOG; j++) {
      int cur = LOG*i + j;
      int lim = (1 << (j+1));
      int usual = lim-1;
      usual = (usual + lim + (l%lim))%lim;
      int back = (usual+lim/2)%lim;

      list[r].push_back({cur, usual});
      list[r].push_back({cur, back});
      if(usual < back)
        list[r].push_back({cur, lim-1});
      if(l) {
        list[l-1].push_back({cur, usual});
        list[l-1].push_back({cur, back});
        if(usual < back)
          list[l-1].push_back({cur, lim-1});
      }
    }
  }

  for(int i = 0; i < m; i++) {
    if(a[i])
      push(i);

    for(task j : list[i])
      query[j.save/LOG] ^= sum(j.x, j.save%LOG) << j.save%LOG;
  }

  for(int i = 0; i < q; i++) {
    if(query[i])
      std::cout << 'A';
    else
      std::cout << 'B';
  }

  std::cout << std::endl;
  
  return 0;
}