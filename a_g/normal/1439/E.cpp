#include <bits/stdc++.h>
using namespace std;

struct pt {
  int x, y;
};

bool operator < (const pt& a, const pt& b) {
  // compare a to b according to DFS inorder
  int x1 = a.x;
  int y1 = a.y;
  int x2 = b.x;
  int y2 = b.y;
  while (1) {
    if (x1 > y1) {
      if (x2 <= y2) return 1;
      if (__lg(x1) != __lg(x2)) {
        return __lg(x1) > __lg(x2);
      }
      int d = 1<<__lg(x1);
      x1 ^= d;
      x2 ^= d;
    }
    else if (x1 == y1) {
      return (x2 < y2);
    }
    else {
      if (x2 >= y2) return 0;
      if (__lg(y1) != __lg(y2)) {
        return __lg(y1) < __lg(y2);
      }
      int d = 1<<__lg(y1);
      y1 ^= d;
      y2 ^= d;
    }
  }
}

bool operator == (const pt& a, const pt& b) {
  return a.x == b.x && a.y == b.y;
}

bool operator != (const pt& a, const pt& b) {
  return a.x != b.x || a.y != b.y;
}


pt lca(pt& a, pt& b) {
  int x1 = a.x;
  int y1 = a.y;
  int x2 = b.x;
  int y2 = b.y;
  int lca_x = 0;
  int lca_y = 0;
  while (1) {
    if (x1 > y1) {
      if (x2 <= y2) break;
      if (__lg(x1) != __lg(x2)) {
        if (__lg(x1) > __lg(x2)) {
          swap(x1, x2);
          swap(y1, y2);
        }
        while (x1 > y1) {
          lca_x ^= 1<<__lg(x1);
          x1 ^= 1<<__lg(x1);
        }
        break;
      }
      int d = 1<<(__lg(x1));
      lca_x ^= d;
      x1 ^= d;
      x2 ^= d;
    }
    else if (x1 == y1) {
      break;
    }
    else {
      if (x2 >= y2) break;
      if (__lg(y1) != __lg(y2)) {
        if (__lg(y1) > __lg(y2)) {
          swap(x1, x2);
          swap(y1, y2);
        }
        while (y1 > x1) {
          lca_y ^= 1<<__lg(y1);
          y1 ^= 1<<__lg(y1);
        }
        break;
      }
      int d = 1<<(__lg(y1));
      lca_y ^= d;
      y1 ^= d;
      y2 ^= d;
    }
  }
  return pt{lca_x, lca_y};
}

int depth(pt& a) {
  return a.x + a.y;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);

  int m;
  cin >> m;
  vector<pt> vtxs;
  vector<pair<pt, pt>> paths;
  for (int i = 0; i < m; i++) {
    pt u, v;
    cin >> u.x >> u.y >> v.x >> v.y;
    vtxs.push_back(u);
    vtxs.push_back(v);
    paths.emplace_back(u, v);
  }
  sort(vtxs.begin(), vtxs.end());
  vtxs.resize(unique(vtxs.begin(), vtxs.end())-vtxs.begin());
  stack<pt> stk;
  vector<pt> full_vtxs;
  vector<pt> par;
  for (pt& p: vtxs) {
    if (!stk.size()) {
      stk.push(p);
      continue;
    }

    pt q = lca(p, stk.top());
    while (stk.size() && stk.top() != q && lca(p, stk.top()) == q) {
      full_vtxs.push_back(stk.top());
      stk.pop();
      par.push_back((stk.size() && depth(stk.top()) > depth(q) ? stk.top() : q));
    }
    if (stk.empty() || q != stk.top()) {
      stk.push(q);
    }
    if (p != stk.top()) {
      stk.push(p);
    }
  }

  while (stk.size()) {
    full_vtxs.push_back(stk.top());
    stk.pop();
    if (stk.size()) par.push_back(stk.top());
  }

  int n = full_vtxs.size();
  map<pt, int> indices;
  for (int i = 0; i < n; i++) {
    indices[full_vtxs[i]] = i;
  }
  vector<vector<int>> G(n);
  for (int i = 0; i < n-1; i++) {
    G[indices[par[i]]].push_back(i);
  }

  set<int> vals;
  auto flip = [&] (int x) {
    if (x < 0) return;
    if (vals.count(x)) vals.erase(x);
    else vals.insert(x);
  };

  vector<int> cnt(n);
  vector<bool> flag(n);
  for (pair<pt, pt>& path: paths) {
    cnt[indices[path.first]]++;
    cnt[indices[path.second]]++;
    cnt[indices[lca(path.first, path.second)]] -= 2;
    // if the two endpoints are the same, we need to remember to mark it
    // as there might not be a path below it to indicate so
    if (path.first == path.second) flag[indices[path.first]] = 1;
  }

  function<void(int)> dfs = [&] (int v) {
    for (int u: G[v]) {
      dfs(u);
      if (cnt[u]) {
        flag[v] = 1;
        flip(depth(full_vtxs[u]));
        flip(depth(full_vtxs[v]));
      }
      cnt[v] += cnt[u];
    }
    if (flag[v] && cnt[v] == 0) {
      // flip just vertex v
      flip(depth(full_vtxs[v]));
      flip(depth(full_vtxs[v])-1);
    }
  };
  dfs(n-1);

  cout << vals.size() << '\n';
}