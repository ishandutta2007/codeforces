#include <iostream>
#include <map>
#include <set>

using namespace std;

map<int, int> root;
map<int, int> height;
map<int, int> cost;
set<int> vertices;

void create (int u) {
  if (vertices.count(u) == 0) {
    root[u] = u;
    height[u] = 0;
    cost[u] = 0;
    vertices.insert(u);
  }
}

pair<int, int> find (int u) {
  if (root[u] == u) {
    return make_pair(u, 0);
  }
  pair<int, int> pr = find(root[u]);
  pr.second ^= cost[u];
  return pr;
}

int get_xor (int u, int v) {
  pair<int, int> uf = find(u);
  pair<int, int> vf = find(v);

  if (uf.first != vf.first) {
    return -1;
  }
  return uf.second ^ vf.second;
}

void merge (int u, int v, int c) {
  pair<int, int> uf = find(u);
  pair<int, int> vf = find(v);

  u = uf.first;
  v = vf.first;
  c ^= uf.second;
  c ^= vf.second;

  if (height[u] > height[v]) {
    root[v] = u;
    cost[v] = c;
  } else if (height[u] < height[v]) {
    root[u] = v;
    cost[u] = c;
  } else {
    root[u] = v;
    cost[u] = c;
    height[v]++;
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int queryc;
  cin >> queryc;

  int last = 0;
  for (int i = 0; i < queryc; i++) {
    int type;
    cin >> type;

    if (type == 1) {
      int l, r, x;
      cin >> l >> r >> x;

      l ^= last;
      r ^= last;
      x ^= last;
      
      if (l > r) {
        swap(l, r);
      }

      r++;

      create(l);
      create(r);
      if (get_xor(l, r) == -1) {
        merge(l, r, x);
      }
    } else if (type == 2) {
      int l, r;
      cin >> l >> r;

      l ^= last;
      r ^= last;

      if (l > r) {
        swap(l, r);
      }

      r++;
      create(l);
      create(r);

      int ans = get_xor(l, r);
      cout << ans << '\n';
      last = abs(ans);
    }
  }
}