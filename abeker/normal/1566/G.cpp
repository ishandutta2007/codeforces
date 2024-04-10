#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 1e5 + 5;
const int offset = 1 << 18;
const int INF = 2e9;

struct Query {
  pii edge;
  int type, weight, id;
  void reorder() {
    swap(edge.first, edge.second);
  }
  Query(int type, int id) : type(type), id(id) {
    scanf("%d%d", &edge.first, &edge.second);
    if (edge.first > edge.second)
      reorder();
    if (type)
      scanf("%d", &weight);
    else
      weight = INF;
  }
  Query() : weight(INF) {}
  bool operator <(const Query &rhs) const {
    if (weight != rhs.weight)
      return weight < rhs.weight;
    return id < rhs.id;
  }
};

struct Node {
  int cnt;
  Node *l, *r;
  Node() : cnt(0), l(0), r(0) {}
  void extendLeft() {
    if (!l)
      l = new Node();
  }
  void extendRight() {
    if (!r)
      r = new Node();
  }
};

class Sparse {
  vector <Node*> roots;
public:
  Sparse(int n) {
    for (int i = 0; i <= n; i++)
      roots.push_back(new Node());
  }
  Sparse() {}
  void update(Node* x, int lo, int hi, int pos, int delta) {
    x->cnt += delta;
    if (hi - lo == 1) 
      return;
    int mid = (lo + hi) / 2;
    if (pos < mid) {
      x -> extendLeft();
      update(x->l, lo, mid, pos, delta);
    }
    else {
      x -> extendRight();
      update(x->r, mid, hi, pos, delta);
    }
  }
  void update(int val, int pos, int delta) {
    update(roots[val], 0, offset, pos, delta);
  }
  void modify(int pos, pii edge, int delta) {
    update(edge.first, pos, delta);
    update(edge.second, pos, delta);
    update(0, pos, delta);
  }
  Node* moveLeft(Node* x) {
    return x ? x->l : 0;
  }
  Node* moveRight(Node* x) {
    return x ? x->r : 0;
  }
  int getLeftCnt(Node* x) {
    return x && x->l ? x->l->cnt : 0;
  }
  int find(Node* glob, Node* fst, Node* sec, int lo, int hi, pii edge, int both) {
    if (hi - lo == 1)
      return lo;
    int mid = (lo + hi) / 2;
    int left = getLeftCnt(fst) + getLeftCnt(sec) - (lo <= both && both < mid);
    if (left < getLeftCnt(glob))
      return find(moveLeft(glob), moveLeft(fst), moveLeft(sec), lo, mid, edge, both);
    return find(moveRight(glob), moveRight(fst), moveRight(sec), mid, hi, edge, both);
  }
  int find(pii edge, int both) {
    return find(roots[0], roots[edge.first], roots[edge.second], 0, offset, edge, both);
  }
};

int N, M, Q;
ll sum[MAXN];
Sparse solver;
set <Query> curr;
vector <Query> queries, sorted;
set <pii> adj[MAXN];
map <pii, int> last;
multiset <ll> claws;
int pos[2 * MAXN];

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < M; i++)
    queries.push_back(Query(1, i));
  scanf("%d", &Q);
  for (int i = 0; i < Q; i++) {
    int t;
    scanf("%d", &t);
    queries.push_back(Query(t, i + M));
  }
}

vector <pii> get_three(int x) {
  vector <pii> res;
  for (auto it : adj[x]) {
    res.push_back(it);
    if (res.size() == 3)
      break;
  }
  return res;
}

void recalc(int x) {
  auto it = claws.find(sum[x]);
  if (it != claws.end())
    claws.erase(it);
  vector <pii> three = get_three(x);
  sum[x] = 0;
  for (auto it : three)
    sum[x] += it.first;
  if (three.size() < 3)
    sum[x] = 2ll * INF;
  claws.insert(sum[x]);
}

void add_edge(Query q) {
  curr.insert(q);
  for (int i = 0; i < 2; i++) {
    adj[q.edge.first].insert({q.weight, q.edge.second});
    recalc(q.edge.first);
    q.reorder();
  }
}

void remove_edge(Query q) {
  curr.erase(q);
  for (int i = 0; i < 2; i++) {
    adj[q.edge.first].erase({q.weight, q.edge.second});
    recalc(q.edge.first);
    q.reorder();
  }
}

ll answer() {
  ll res = *claws.begin();
  Query smallest = *curr.begin();
  int idx = solver.find(smallest.edge, pos[smallest.id]);
  if (idx < M + Q)
    res = min(res, (ll)smallest.weight + sorted[idx].weight);
  int u = smallest.edge.first;
  int v = smallest.edge.second;
  vector <pii> three_u = get_three(u);
  vector <pii> three_v = get_three(v);
  for (auto it_u : three_u)
    for (auto it_v : three_v)
      if (it_u.second != v && it_v.second != u && it_u.second != it_v.second)
        res = min(res, (ll)it_u.first + it_v.first);
  return res;
}

void solve() {
  for (int i = 1; i <= N; i++)
    recalc(i);
  sorted = queries;
  sort(sorted.begin(), sorted.end());
  for (int i = 0; i < M + Q; i++) 
    pos[sorted[i].id] = i;
  solver = Sparse(N);
  for (int i = 0; i < M + Q; i++) {
    int &ref = last[queries[i].edge];
    if (queries[i].type) {
      solver.modify(pos[i], queries[i].edge, 1);
      add_edge(queries[i]);
      ref = i;
    }
    else {
      solver.modify(pos[ref], queries[i].edge, -1);
      remove_edge(queries[ref]);
    }
    if (i >= M - 1) 
      printf("%lld\n", answer());
  }
}

int main() {
  load();
  solve();
  return 0;
}