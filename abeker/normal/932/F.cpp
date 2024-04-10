#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int offset = 1 << 17;
const ll INF = 1e18;

struct Line {
  int a;
  ll b;
  ll operator ()(int x) const {
    return (ll)a * x + b;
  }
};

struct Node {
  Line opt;
  Node *l, *r;
  Node() {
    opt = {0, INF};
    l = r = nullptr;
  }
  void extend() {
    if (!l)
      l = new Node();
    if (!r)
      r = new Node();
  }
};

bool cmp(Line p, Line q, int x) {
  return p(x) < q(x);
}

class LiChao {
  Node* root;
  vector <Line> lines;
public:
  LiChao() {
    root = new Node();
  }
  void update(Node* x, int lo, int hi, Line val) {
    int mid = lo + (hi - lo) / 2;
    bool left = cmp(val, x -> opt, lo);
    bool middle = cmp(val, x -> opt, mid);
    if (middle)
      swap(x -> opt, val);
    if (hi - lo == 1)
      return;
    x -> extend();
    if (left != middle)
      update(x -> l, lo, mid, val);
    else
      update(x -> r, mid, hi, val);
  }
  void addLine(Line val) {
    update(root, -offset, offset, val);
    lines.push_back(val);
  }
  ll query(Node* x, int lo, int hi, int pos) {
    ll curr = (x -> opt)(pos);
    if (hi - lo == 1)
      return curr;
    x -> extend();
    int mid = lo + (hi - lo) / 2;
    if (pos < mid)
      return min(curr, query(x -> l, lo, mid, pos));
    return min(curr, query(x -> r, mid, hi, pos));
  }
  ll query(int pos) {
    return query(root, -offset, offset, pos);
  }
  vector <Line> getLines() const {
    return lines;
  }
  int size() const {
    return lines.size();
  }
};

int N;
ll dp[MAXN];
int a[MAXN], b[MAXN];
vector <int> adj[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d", a + i);
  for (int i = 1; i <= N; i++)
    scanf("%d", b + i);
  for (int i = 1; i < N; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

LiChao* dfs(int x, int p) {
  vector <LiChao*> ch;
  for (auto it : adj[x])
    if (it != p)
      ch.push_back(dfs(it, x));
  if (ch.empty()) 
    ch.push_back(new LiChao());
  else {
    swap(*ch.begin(), *max_element(ch.begin(), ch.end(), [&](const LiChao* lhs, const LiChao* rhs) { return lhs -> size() < rhs -> size(); }));
    for (int i = 1; i < ch.size(); i++) {
      vector <Line> tmp = ch[i] -> getLines();
      for (auto it : tmp)
        ch[0] -> addLine(it);
    }
    dp[x] = ch[0] -> query(a[x]);
  }
  ch[0] -> addLine({b[x], dp[x]});
  return ch[0];
}

void solve() {
  dfs(1, 0);
  for (int i = 1; i <= N; i++)
    printf("%lld ", dp[i]);
  puts("");
}

int main() {
  load();
  solve();
  return 0;
}