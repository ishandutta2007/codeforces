#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Seg {
  int sum = 0, act = 0;

  Seg () {}

  Seg (int _sum, int _act) : sum(_sum), act(_act) {}
};

Seg merge (Seg p, Seg q) {
  Seg ans;
  ans.sum = p.sum + q.sum;
  ans.act = p.act + q.act;
  return ans;
}

struct Segtree {
  int n;
  vector<Seg> tree;
  vector<int> lfend;
  vector<int> rgend;

  Segtree (int _n) {
    n = 1;
    while (n < _n) {
      n *= 2;
    }

    tree = vector<Seg> (2 * n, Seg());
    lfend = vector<int> (2 * n);
    rgend = vector<int> (2 * n);

    for (int i = n; i < 2 * n; i++) {
      lfend[i] = i - n;
      rgend[i] = i - n;
    }

    for (int i = n - 1; i > 0; i--) {
      lfend[i] = lfend[2 * i];
      rgend[i] = rgend[2 * i + 1];
    }
  }

  Seg query (int ql, int qr, int u = 1) const {
    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    if (ql > qr) return Seg();
    if (ql == lfend[u] && qr == rgend[u]) return tree[u];
    return merge(query(ql, qr, 2 * u), query(ql, qr, 2 * u + 1));
  }

  void set (int pos, Seg val) {
    tree[n + pos] = val;
    for (int u = (n + pos) / 2; u != 0; u /= 2) {
      tree[u] = merge(tree[2 * u], tree[2 * u + 1]);
    }
  }
};

Seg search (const Segtree &tree, int w) {
  int ans = 0; // len

  for (int k = 1 << 16; k != 0; k /= 2) {
    if (ans + k >= tree.n)
      continue;

    if (tree.query(0, ans + k - 1).sum <= w) {
      ans += k;
    }
  }

  if (ans == 0) return Seg(0, 0);
  return tree.query(0, ans - 1);
}

void solve () {
  int n, K;
  cin >> n >> K;

  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    cnt[x]++;
  }

  int suffsz = cnt.size();
  
  vector<pair<int, int>> ord;
  for (auto kv : cnt) {
    ord.push_back({kv.second, kv.first});
  }
  sort(ord.begin(), ord.end());
  
  map<int, int> seg_idx;
  for (int i = 0; i < (int) ord.size(); i++) {
    seg_idx[ord[i].second] = i;
  }
  
  Segtree tree (suffsz + 5);
  for (auto kv : cnt) {
    tree.set(seg_idx[kv.first], Seg(kv.second, 1));
  }
  
  int holes = 0, ans = suffsz;
  for (int m = 0; m <= n; m++) {
    if (m != 0) {
      if (cnt[m - 1] == 0) {
        holes++;
      }
    }

    if (cnt[m] != 0) {
      tree.set(seg_idx[m], Seg());
      suffsz--;
    }

    if (cnt[m] > K || holes > K) {
      continue;
    }

    int df = max(1, m + suffsz - search(tree, K - cnt[m]).act);
    ans = min(ans, df - m);
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}