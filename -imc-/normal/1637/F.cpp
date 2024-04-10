#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

struct Value {
  int maxh;
  li dp;
};

Value neutral() {
  return Value{0};
}

Value combine(Value a, Value b) {
  return Value{max(a.maxh, b.maxh), a.dp + b.dp};
}

struct Vertex {
  int h;
  vector<int> adj;

  // pref[l] unknown, suf[r] unknown
  int l, r;
  vector<Value> val;
  vector<Value> pref, suf;
};

vector<Vertex> tree;

Value dfs(int v, int p) {
  auto& tv = tree[v];

  if (tv.val.empty()) {
    int n = tv.adj.size();
    tv.val.resize(n);
    tv.pref.resize(n);
    tv.suf.resize(n);
    tv.l = 0;
    tv.r = n - 1;
  }

  int p_index = lower_bound(all(tv.adj), p) - tv.adj.begin();
  assert(tv.adj.at(p_index) == p);

  while (tv.l < p_index) {
    if (tv.l <= tv.r) {
      tv.val[tv.l] = dfs(tv.adj[tv.l], v);
    }

    tv.pref[tv.l] = combine(tv.val[tv.l], tv.l == 0 ? neutral() : tv.pref[tv.l - 1]);
    ++tv.l;
  }

  while (tv.r > p_index) {
    if (tv.l <= tv.r) {
      tv.val[tv.r] = dfs(tv.adj[tv.r], v);
    }

    tv.suf[tv.r] = combine(tv.val[tv.r], tv.r + 1 == tv.adj.size() ? neutral() : tv.suf[tv.r + 1]);
    --tv.r;
  }

  Value res = combine(p_index != 0 ? tv.pref[p_index - 1] : neutral(), p_index + 1 != tv.adj.size() ? tv.suf[p_index + 1] : neutral());

  res.dp = res.dp + max(tv.h - res.maxh, 0);
  res.maxh = max(res.maxh, tv.h);

  //cout << "dfs v: " << v + 1 << " parent: " << p + 1 << " dp: " << res.dp << " maxh: " << res.maxh << "\n";

  return res;
}

void solve(bool read = true) {
  int n;
  cin >> n;

  tree.clear();
  tree.resize(n);

  bool all_equal = true;
  int maxh = 0;

  for (int i = 0; i < n; ++i) {
    cin >> tree[i].h;
    if (tree[i].h != tree[0].h) {
      all_equal = false;
    }
    maxh = max(maxh, tree[i].h);
  }

  int cnt_max = 0;
  for (int i = 0; i < n; ++i) {
    if (tree[i].h == maxh) {
      ++cnt_max;
    }
  }

  li ans = 1e18;

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u; --v;

    tree[u].adj.push_back(v);
    tree[v].adj.push_back(u);
  }

  for (int i = 0; i < n; ++i) {
    sort(all(tree[i].adj));
  }

  for (int p = 0; p < n; ++p) {
    if (cnt_max == 1 && tree[p].h == maxh) {
      continue;
    }

    li s = 0;
    for (int v : tree[p].adj) {
      auto val = dfs(v, p);
      s += val.dp;
      //auto can = val.dp + maxh;
      //cout << "at v: " << v << " par: " << p;
    }

    auto can = s + maxh;
    //cout << "at v: " << p + 1 << " can: " << can << "\n";
    ans = min<li>(ans, can);
  }

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int nt = 1;
  //cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }

  return 0;
}