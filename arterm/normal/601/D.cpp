#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int A = 27;
const int M = 300100;

struct Tree {
  Tree *a[A];
  int cnt;
  
  Tree() {
    fill(a, a + A, nullptr);
    cnt = 0;
  }

};

int cnt(Tree *t) {
  return t == nullptr ? 0 : t->cnt;
}

Tree* glue(Tree *l, Tree *r) {
  if (l == nullptr)
    return r;
  if (r == nullptr)
    return l;

  if (l->cnt < r->cnt)
    swap(l, r);

  int cur = 1;
  for (int i = 0; i < A; ++i) {
    l->a[i] = glue(l->a[i], r->a[i]);
    cur += cnt(l->a[i]);
  }

  l->cnt = cur;

  //delete r;

  return l;
}


Tree store[M];
int m = 0;

Tree *getOne() {
  return store + m++;
}


int best = -1, ans = 0;
int n, c[M];
string s;
vector<pair<int, int>> g[M];
bool u[M];

void relax(int x) {
  if (best < x) {
    best = x;
    ans = 1;
  } else if (best == x) {
    ++ans;
  }
}

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> c[i];

  cin >> s;

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].emplace_back(s[v] - 'a', v);
    g[v].emplace_back(s[u] - 'a', u);
  }
}
    
Tree *dfs(int v) {
  u[v] = true;
  
  Tree *t = getOne();
  t->cnt = 1;

  for (auto to : g[v])
    if (!u[to.second]) {
      int by = to.first;
      int u = to.second;
      t->a[by] = glue(t->a[by], dfs(u));
    }
    
  for (int i = 0; i < A; ++i)
    t->cnt += cnt(t->a[i]);

  relax(t->cnt + c[v]);

  return t;
}

int main() {
  ios_base::sync_with_stdio(false);
  read();
  dfs(0);
  cout << best << endl << ans << endl;
  return 0;
}