#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

struct Store {
  int root;
  map<int, int> a;

  int size() {
    return a.size();
  }

  int& operator[](int x) {
    return a[x];
  }
};

map<int, Store*> to;

Store* get(int u) {
  if (to.find(u) != to.end()) return to[u];
  
  Store *cur = new Store;
  cur->root = u;
  cur->a.emplace(u, 0);

  return to[u] = cur;
}

Store* merge(Store* A, Store* B, int a, int b, int x) {
  if (A->size() < B->size()) {
    swap(A, B);
    swap(a, b);
  }

  int by = (*A)[a] ^ (*B)[b] ^ x;
  
  for (const auto e : B->a) {
    A->a.emplace(e.first, e.second ^ by);
    to[e.first] = A;
  }

  delete B;
  return A;
}

void add(int u, int v, int x) {
  Store* su = get(u);
  Store* sv = get(v);
  if (su == sv) return;

  merge(su, sv, u, v, x);
}

int query(int u, int v) {
  Store* su = get(u);
  Store* sv = get(v);
  if (su != sv) return -1;
  return (*su)[u] ^ (*sv)[v];
}


int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int last = 0;
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      l ^= last;
      r ^= last;
      x ^= last;
      if (l > r)
        swap(l, r);
      ++r;
      add(l, r, x);
    } else {
      int l, r;
      cin >> l >> r;
      l ^= last;
      r ^= last;
      if (l > r)
        swap(l, r);
      ++r;
      int ans = query(l, r);
      last = (ans == -1 ? 1 : ans);
      cout << ans << "\n";
    }
  }
}