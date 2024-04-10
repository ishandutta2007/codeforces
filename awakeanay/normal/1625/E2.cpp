#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>

#define int long long

const int MAXN = 300005;

int id[MAXN];
int par[MAXN];
int val[MAXN];
std::vector<int> bit(MAXN, 0);
std::vector<int> pos[2*MAXN];
std::vector<int> posb[2*MAXN];

void add(int x, int v, std::vector<int> &bit) {
  x += 1;
  while(x < bit.size()) {
    bit[x] += v;
    x += x&(-x);
  }
}

int sum(int x, std::vector<int> &bit) {
  int ret = 0;
  x += 1;
  while(x > 0) {
    ret += bit[x];
    x -= x&(-x);
  }
  return ret;
}

int root(int u) {
  if(par[u] < 0)
    return u;
  return par[u] = root(par[u]);
}

int calc(int x) {
  return (x*(x+1))/2;
}

void merge(int u, int v) {
  u = root(u);
  v = root(v);

  if(u == v)
    return;

  if(par[u] > par[v])
    u ^= v ^= u ^= v;

  add(v, -calc(-par[v]), bit);
  add(u, -calc(-par[u]), bit);

  par[u] += par[v];
  par[v] = u;
  add(u, calc(-par[u]), bit);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  for(int i = 0; i < 2*MAXN; i++)
    posb[i].push_back(0);

  int n, q;
  std::cin >> n >> q;

  std::stack<int> st;
  int last = 0;
  int cur = 0;

  for(int i = 0; i < n; i++) {
    char c;
    std::cin >> c;

    if(c == '(') {
      cur++;
      st.push(i);
      id[i] = i;
      par[i] = -1;
      val[i] = cur;
      pos[n+cur].push_back(i);
      posb[n+cur].push_back(0);
      add(i, 1, bit);

      if(last)
        merge(i, id[i-1]);

      last = 0;
    }
    else {
      cur--;
      if(st.empty()) {
        last = 0;
        continue;
      }
      id[i] = st.top();
      st.pop();
      last = 1;
    }
  }

  while(q--) {
    int t, l, r;
    std::cin >> t >> l >> r;
    t--; l--; r--;
    int u = root(l);

    if(t) {
      int c1 = sum(r, bit)-sum(l-1, bit);
      if(l <= u && u <= r)
        c1 -= calc(-par[u]);

      int v = n+val[l];
      int lt = std::lower_bound(pos[v].begin(), pos[v].end(), l)-pos[v].begin();
      int rt = std::lower_bound(pos[v].begin(), pos[v].end(), r)-pos[v].begin();
      int ct = rt-lt;
      ct -= sum(rt-1, posb[v])-sum(lt-1, posb[v]);
      c1 += (ct*(ct+1))/2;

      std::cout << c1 << std::endl;
    }
    else {
      int v = n+val[l];
      int p = std::lower_bound(pos[v].begin(), pos[v].end(), l)-pos[v].begin();
      add(p, 1, posb[v]);

      add(u, -calc(-par[u]), bit);
      par[u]++;
      add(u, calc(-par[u]), bit);
    }
  }

  return 0;
}