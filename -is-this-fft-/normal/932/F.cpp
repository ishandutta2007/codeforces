#include <iostream>
#include <set>
#include <vector>
#include <assert.h>
#include <limits.h>

using namespace std;

typedef long long ll;

struct Line {
  mutable ll k, m, p;
  bool operator< (const Line& o) const {
    return k < o.k;
  }
  
  bool operator< (ll x) const {
    return p < x;
  }
};

struct LineContainer : multiset<Line, less<>> {
  // (for doubles, use inf = 1/.0, div(a,b) = a/b)
  static const ll inf = LLONG_MAX;
  ll div (ll a, ll b) { // floored division
    return a / b - ((a ^ b) < 0 && a % b);
  }
  
  bool isect (iterator x, iterator y) {
    if (y == end()) return x->p = inf, 0;
    if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
    else x->p = div(y->m - x->m, x->k - y->k);
    return x->p >= y->p;
  }

  vector<pair<ll, ll>> lines;
  void add (ll k, ll m) {
    lines.push_back(make_pair(k, m));
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p)
      isect(x, erase(y));
  }
  
  ll query (ll x) {
    assert(!empty());
    auto l = *lower_bound(x);
    return l.k * x + l.m;
  }

  void subsume (LineContainer *oth) {
    for (auto pr : oth->lines) {
      add(pr.first, pr.second);
    }
  }
};

const int MAX_N = 1e5 + 5;

ll A [MAX_N], B [MAX_N];
vector<int> adj [MAX_N];

LineContainer *subtree [MAX_N];
ll dp [MAX_N];

void build (int u, int p) {
  pair<int, int> bigcpr = make_pair(-1, -1);
  
  for (int nxt : adj[u]) {
    if (nxt != p) {
      build(nxt, u);
      bigcpr = max(bigcpr, make_pair((int) subtree[nxt]->size(), nxt));
    }
  }

  int bigc = bigcpr.second;
  if (bigc == -1) {
    subtree[u] = new LineContainer();
  } else {
    subtree[u] = subtree[bigc];
    for (int nxt : adj[u]) {
      if (nxt != p && nxt != bigc) {
        subtree[u]->subsume(subtree[nxt]);
      }
    }
    dp[u] = -subtree[u]->query(A[u]);
  }
  subtree[u]->add(-B[u], -dp[u]);
}

int main () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }

  for (int i = 1; i <= n; i++) {
    cin >> B[i];
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  build(1, 0);
  for (int i = 1; i <= n; i++) {
    cout << dp[i] << " ";
  }
  cout << '\n';
}