#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1e5 + 5;
const int offset = 1 << 17;
const int MOD = 1e9 + 7;

struct Node {
  bool lazy;
  ll hash0, hash1;
  Node *l, *r;
  Node(ll hash0, ll hash1, bool lazy, Node* l, Node* r) : 
    hash0(hash0), hash1(hash1), lazy(lazy), l(l), r(r) {}
  Node() {}
};

int N, M, S, T;
ll vals[offset];
vector <pair <int, int>> adj[MAXN];
Node* dist[MAXN];
int dad[MAXN];

void load() {
  scanf("%d%d", &N, &M);
  while (M--) {
    int u, v, x;
    scanf("%d%d%d", &u, &v, &x);
    adj[u].push_back({v, x});
    adj[v].push_back({u, x});
  }
  scanf("%d%d", &S, &T);
}

Node* flipped(Node* x) {
  return x ? new Node(x -> hash1, x -> hash0, x -> lazy ^ 1, x -> l, x -> r) : nullptr;
}

void prop(Node* &x) {
  if (x -> lazy)
    x = new Node(x -> hash0, x -> hash1, 0, flipped(x -> l), flipped(x -> r));
}

Node* merge(Node* left, Node* right) {
  return new Node(left -> hash0 ^ right -> hash0, left -> hash1 ^ right -> hash1, 0, left, right);
}

Node* update(Node* x, int lo, int hi, int from, int to) {
  if (lo >= to || hi <= from)
    return x;
  if (lo >= from && hi <= to)
    return flipped(x);
  prop(x);
  int mid = (lo + hi) / 2;
  return merge(update(x -> l, lo, mid, from, to), update(x -> r, mid, hi, from, to));
}

int first_zero(Node* x, int lo, int hi, int pos) {
  if (pos >= hi || !(x -> hash0))
    return -1;
  if (hi - lo == 1)
    return lo;
  prop(x);
  int mid = (lo + hi) / 2;
  int res = first_zero(x -> l, lo, mid, pos);
  if (res != -1)
    return res;
  return first_zero(x -> r, mid, hi, pos);
}

Node* add_power(Node* x, int pos) {
  return update(x, 0, offset, pos, first_zero(x, 0, offset, pos) + 1);
}

int cmp(Node* x, Node* y, int lo = 0, int hi = offset) {
  if (x -> hash0 == y -> hash0)
    return -1;
  if (hi - lo == 1)
    return x -> hash0 && y -> hash1;
  prop(x);
  prop(y);
  int mid = (lo + hi) / 2;
  int res = cmp(x -> r, y -> r, mid, hi);
  if (res != -1)
    return res;
  return cmp(x -> l, y -> l, lo, mid);
}

bool get_bit(Node* x, int lo, int hi, int pos) {
  if (hi - lo == 1)
    return x -> hash1;
  prop(x);
  int mid = (lo + hi) / 2;
  if (pos < mid)
    return get_bit(x -> l, lo, mid, pos);
  return get_bit(x -> r, mid, hi, pos);
}

bool get_bit(Node* x, int pos) {
  return get_bit(x, 0, offset, pos);
}

Node* init(int pref, int lo = 0, int hi = offset) {
  if (hi - lo == 1)
    return new Node(lo < pref ? 0 : vals[lo], lo < pref ? vals[lo] : 0, 0, nullptr, nullptr);
  int mid = (lo + hi) / 2;
  return merge(init(pref, lo, mid), init(pref, mid, hi));
}

void solve() {
  for (int i = 0; i < offset; i++)
    vals[i] = uniform_int_distribution <ll> (1, 1e18)(rng);
  auto smaller = [&](int x, int y) -> bool {
    int tmp = cmp(dist[x], dist[y]);
    if (tmp != -1)
      return tmp;
    return x < y;
  };
  dist[S] = init(0);
  Node* inf = init(offset - 1);
  set <int, decltype(smaller)> curr(smaller);
  for (int i = 1; i <= N; i++) {
    if (i != S)
      dist[i] = inf;
    curr.insert(i);
  }
  auto bad = [&](int x) {
    return x != S && !dad[x];
  };
  while (!curr.empty()) {
    int tmp = *curr.begin();
    curr.erase(tmp);
    if (bad(tmp))
      break;
    for (auto it : adj[tmp]) {
      Node* cand = add_power(dist[tmp], it.second);
      if (cmp(cand, dist[it.first]) == 1) {
        curr.erase(it.first);
        dist[it.first] = cand;
        curr.insert(it.first);
        dad[it.first] = tmp;
      }
    }
  }
  if (bad(T)) {
    puts("-1");
    return;
  }
  int sol = 0, pot = 1;
  for (int i = 0; i < offset; i++) {
    auto add = [](int &x, int y) {
      x += y;
      if (x >= MOD)
        x -= MOD;
    };
    if (get_bit(dist[T], i))
      add(sol, pot);
    add(pot, pot);
  }
  stack <int> path;
  for (; T; T = dad[T])
    path.push(T);
  printf("%d\n%d\n", sol, path.size());
  for (; !path.empty(); path.pop())
    printf("%d ", path.top());
  puts("");
}

int main() {
  load();
  solve();
  return 0;
}