#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 8e5 + 5;

int cap;

int op (int p, int q) {
  if (p > q) swap(p, q);

  if (cap < p) { // cap < p < q
    return q;
  }
  if (cap < q) { // p <= cap < q
    return p;
  }
  return q; // p < q <= cap
}

class Segtree {
  vector<int> tree;
  vector<int> lfend;
  vector<int> rgend;
  int length;

  int query (int ql, int qr, int u = 1) {
    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    if (ql > qr) return cap + 1;
    if (ql == lfend[u] && qr == rgend[u]) return tree[u];
    return op(query(ql, qr, 2 * u),
              query(ql, qr, 2 * u + 1));
  }

  void update (int u) {
    if (u == 0) return;
    tree[u] = op(tree[2 * u], tree[2 * u + 1]);
    update(u / 2);
  }
public:
  Segtree (int _length = 0) {
    length = 1;
    while (length <= _length) {
      length *= 2;
    }

    tree = vector<int> (2 * length, cap + 1);
    lfend = vector<int> (2 * length);
    rgend = vector<int> (2 * length);
    for (int i = length; i < 2 * length; i++) {
      lfend[i] = i - length;
      rgend[i] = i - length;
    }
    for (int i = length - 1; i > 0; i--) {
      lfend[i] = lfend[2 * i];
      rgend[i] = rgend[2 * i + 1];
    }
  }

  void set (int u, int x) {
    tree[length + u] = x;
    update((length + u) / 2);
  }

  int get (int ql, int qr) {
    if (ql <= qr) return query(ql, qr, 1);
    return op(query(1, qr, 1), query(ql, length - 1, 1));
  }
};

vector<int> adj [MAX_N];
int cur;
int rangel [MAX_N];
int ranger [MAX_N];
int par [MAX_N];
int subsz [MAX_N];

void build (int u, int p) {
  par[u] = p;
  cur++;
  rangel[u] = cur;
  subsz[u] = 1;
  
  for (int nxt : adj[u]) {
    if (nxt != p) {
      build(nxt, u);
      subsz[u] += subsz[nxt];
    }
  }
  
  ranger[u] = cur;
}

int n;
Segtree tree;
int ans [MAX_N];

void calc_ans (int u, int p) {
  int bigc = -1;

  for (int nxt : adj[u]) {
    if (subsz[nxt] > cap) {
      bigc = nxt;
    }
  }
  
  if (bigc == -1) {
    ans[u] = 1;
  } else if (bigc == p) {
    int mx = tree.get(ranger[u] + 1, rangel[u] - 1);
    if (mx <= cap && subsz[bigc] - mx <= cap) {
      ans[u] = 1;
    }
  } else {
    int mx = tree.get(rangel[bigc], ranger[bigc]);
    if (mx <= cap && subsz[bigc] - mx <= cap) {
      ans[u] = 1;
    }
  }

  for (int nxt : adj[u]) {
    if (nxt != p) {
      subsz[u] = n - subsz[nxt];
      subsz[nxt] = n;

      tree.set(rangel[u], subsz[u]);
      tree.set(rangel[nxt], subsz[nxt]);
      
      calc_ans(nxt, u);
      
      subsz[nxt] = n - subsz[u];
      subsz[u] = n;

      tree.set(rangel[u], subsz[u]);
      tree.set(rangel[nxt], subsz[nxt]);      
    }
  }
}

int main () {
  ios::sync_with_stdio(false);

  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  build(1, 0);

  cap = n / 2;
  tree = Segtree(n + 5);
  for (int i = 1; i <= n; i++) {
    tree.set(rangel[i], subsz[i]);
  }

  calc_ans(1, 0);

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}