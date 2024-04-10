#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 200200;
const int N = 5;
const int T = 133;
int fact[] = {1, 1, 2, 6, 24, 120};

typedef array<int, N> Perm;
typedef array<bool, T> Set;

int n, m;
int F;

Perm operator*(const Perm &a, const Perm &b) {
  Perm c;
  fill(all(c), 0);
  for (int i = 0; i < m; ++i)
    c[i] = a[b[i]];
  return c;
}

Perm I;
vector<Perm> perms;
int x[T][T];
int a[M];
int nx[M][T];
set<set<int>> groups;
map<pair<Set, int>, Set> mem;

int id(const Perm& p) {
  int ans = lower_bound(all(perms), p) - perms.begin();
  //if (ans == perms.size()) {
    //for (int i = 0; i < N; ++i)
      //cerr << p[i] << " ";
    //cerr << "\n";
  //}
  assert(ans < (int) perms.size());
  return ans;
}

void read() {
  cin >> n >> m;

  for (int i = 0; i < m; ++i)
    I[i] = i;

  Perm cur = I;
  F = fact[m];
  for (int i = 0; i < F; ++i) {
    perms.push_back(cur);
    next_permutation(cur.begin(), cur.begin() + m);
  }

  sort(all(perms));

  for (int i = 0; i < F; ++i)
    for (int j = 0; j < F; ++j) {
      x[i][j] = id(perms[i] * perms[j]);
      //cerr << x[i][j] << " \n"[j + 1 == F];
    }

  for (int i = 0; i < n; ++i) {
    Perm cur;
    fill(all(cur), 0);

    for (int j = 0; j < m; ++j) {
      cin >> cur[j];
      --cur[j];
    }
    a[i] = id(cur);
    //cerr << a[i] << "\n";
  }
}

int sz(Set s) {
  int ans = 0;
  for (int i = 0; i < F; ++i)
    if (s[i])
      ++ans;
  return ans;
}

Set add(Set g, int i) {
  pair<Set, int> tut = make_pair(g, i);
  if (mem.count(tut))
    return mem[tut];

  g[i] = true;

  static int q[T];
  int qs = 0, qf = 0;
  for (int i = 0; i < F; ++i)
    if (g[i])
      q[qf++] = i;

  while (qs < qf) {
    int i = q[qs++];
    for (int j = 0; j < F; ++j)
      if (g[j]) {
        if (!g[x[i][j]]) {
          g[x[i][j]] = true;
          q[qf++] = x[i][j];
        }

        if (!g[x[j][i]]) {
          g[x[j][i]] = true;
          q[qf++] = x[j][i];
        }
      }
  }

  return mem[tut] = g;
}


void kill() {
  for (int i = 0; i < F; ++i)
    nx[n][i] = n;

  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < F; ++j)
      nx[i][j] = nx[i + 1][j];
    assert(0 <= a[i] && a[i] < F);
    nx[i][a[i]] = i;
  }

  ll ans = 0;

  for (int i = 0; i < n; ++i) {
    Set cur;
    fill(all(cur), false);
    cur[id(I)] = true;
    cur = add(cur, a[i]);

    int r = i;
    while (r < n) {
      int to = n;
      for (int t = 0; t < F; ++t)
        if (!cur[t])
          to = min(to, nx[i][t]);

      ans += (to - r) * sz(cur);

      if (to < n) {
        cur = add(cur, a[to]);
      }
      r = to;
    }
  }

  cout << ans << "\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  //pre();
  kill();

}