#include <bits/stdc++.h>
using namespace std;

struct Node {
  int sum, lazy;
  Node(int sum, int lazy) : sum(sum), lazy(lazy) {}
  Node() : sum(0), lazy(-1) {}
};

class Tournament {
  int offset;
  vector <Node> t;
public:
  Tournament(int n) {
    for (offset = 1; offset < n; offset *= 2);
    t.resize(2 * offset);
  }
  Node merge(Node left, Node right) {
    return Node(left.sum + right.sum, -1);
  }
  void prop(int x, int len) {
    if (t[x].lazy == -1)
      return;
    t[x].sum = len * t[x].lazy;
    if (x < offset) 
      t[2 * x].lazy = t[2 * x + 1].lazy = t[x].lazy;
    t[x].lazy = -1;
  }
  void update(int x, int lo, int hi, int from, int to, int val) {
    prop(x, hi - lo);
    if (lo >= to || hi <= from)
      return;
    if (lo >= from && hi <= to) {
      t[x].sum = (hi - lo) * val;
      if (x < offset)
        t[2 * x].lazy = t[2 * x + 1].lazy = val;
      return;
    }
    int mid = (lo + hi) / 2;
    update(2 * x, lo, mid, from, to, val);
    update(2 * x + 1, mid, hi, from, to, val);
    t[x] = merge(t[2 * x], t[2 * x + 1]);
  }
  Node query(int x, int lo, int hi, int from, int to) {
    prop(x, hi - lo);
    if (lo >= to || hi <= from) 
      return Node();
    if (lo >= from && hi <= to)
      return t[x];
    int mid = (lo + hi) / 2;
    return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
  }
  void update(int from, int to, int val) {
    update(1, 0, offset, from, to, val);
  }
  int query(int from, int to) {
    return query(1, 0, offset, from, to).sum;
  }
};

int N, Q;
string s, f;
vector <pair <int, int>> queries;

void load() {
  cin >> N >> Q >> s >> f;
  queries.resize(Q);
  for (auto &it : queries)
    cin >> it.first >> it.second;
}

bool solve() {
  Tournament tree(N);
  for (int i = 0; i < N; i++) 
    tree.update(i, i + 1, f[i] - '0');
  reverse(queries.begin(), queries.end());
  for (auto it : queries) {
    int ones = tree.query(it.first - 1, it.second);
    int zeroes = it.second - it.first + 1 - ones;
    if (ones == zeroes)
      return false;
    tree.update(it.first - 1, it.second, ones > zeroes);
  }
  for (int i = 0; i < N; i++)
    if (tree.query(i, i + 1) != s[i] - '0')
      return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    load();
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}