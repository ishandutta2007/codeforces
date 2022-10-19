#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#define get sdlkjfdsalf
#define merge lksajfdlaskf

const int M = 200200;
const int MEM = 4 * M - 60000;
const int N = 9;
const int inf = 1e9;

void uin(int &x, int y) {
  x = min(x, y);
}

struct Node {
  int cost[N][N];

  Node *l, *r;
  
  Node() {
    l = r = nullptr;
    for (int i = 0; i < N; ++i)
      fill(cost[i], cost[i] + N, inf);
  }

  int* operator[](int x) {
    return cost[x];
  }
} pool[MEM], I, D[10];
Node* last_node = pool;


vector<pair<int, int>> mo(int type, int d, int cost) {
  static int need[] = {2, 0, 1, 6, 6};
  static int add[] = {2, 0, 1, 7};

  vector<pair<int, int>> ans;

  if (type % 2 == 0) {
    int ncost = cost;
    if (d == need[type / 2]) {
      ncost++;
    }

    ans.emplace_back(type, ncost);
    if (type < N)
      ans.emplace_back(type + 1, ncost);
  } else {
    if (d == add[type / 2])
      ans.emplace_back(type + 1, cost);
  }

  return ans;
}

Node add(Node A, int d) {
  Node ans;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      for (auto p : mo(j, d, A[i][j])) {
        uin(ans[i][p.first], p.second);
      }
  return ans;
}

void ini() {
  for (int i = 0; i < N; ++i)
    I[i][i] = 0;

  for (int i : {0, 2, 4, 6}) {
    I[i][i + 1] = 0;
  }

  for (int d = 0; d < 10; ++d)
    D[d] = add(I, d);
}

Node* getNode() {
  return last_node++;
}

Node merge(Node L, Node R) {
  Node ans;
  for (int i = 0; i < N; ++i)
    for (int j = i; j < N; ++j)
      for (int k = j; k < N; ++k)
        uin(ans[i][k], L[i][j] + R[j][k]);
  return ans;
}

int n, a[M], m;
Node *root;

Node* build(int l, int r) {
  Node *cur = getNode();
  if (l + 1 == r)
    *cur = D[a[l]];
  else {
    int m = (l + r) / 2;
    Node *L = build(l, m);
    Node *R = build(m, r);
    *cur = merge(*L, *R);
    cur->l = L;
    cur->r = R;
  }

  return cur;
}

Node get(Node *v, int l, int r, int le, int re) {
  if (l == le && r == re) {
    return *v;
  }

  int m = (le + re) / 2;

  if (r <= m)
    return get(v->l, l, r, le, m);

  if (m <= l)
    return get(v->r, l, r, m, re);

  return merge(get(v->l, l, m, le, m),
               get(v->r, m, r, m, re));
}

void read() {
  cin >> n >> m;
  string s;
  cin >> s;
  for (int i = 0; i < n; ++i)
    a[i] = s[i] - '0';

  root = build(0, n);
}

void kill() {
  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    --l;
    Node ans = get(root, l, r, 0, n);
    int res = ans[0][N - 1];
    if (res >= inf)
      cout << "-1\n";
    else
      cout << res << "\n";
  }
  cerr << "nice\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  ini();
  read();
  kill();

  return 0;
}