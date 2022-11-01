#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1000000;
const int N = 1000010;

int n, m, f[N];
vector <int> all;
vector <int> ltAdd[N], rtAdd[N];
vector <pair <int, int>> queries[N];

void update (int p, int v) {
  while (p < N) f[p] += v, p += p & -p;
}

int pref (int p) {
  int ret = 0;
  while (p) ret += f[p], p -= p & -p;
  return ret;
}

inline int get (int l, int r) {
  return pref(r) - (l ? pref(l - 1) : 0);
}

int main() {
  cin >> n >> m;
  long long V = 4 * M, E = 4 * M;
  for (int i = 1; i <= n; ++i) {
    int y, l, r;
    scanf("%d %d %d", &y, &l, &r);
    if (l == 0 and r == M) {
      V += M - 1, E += M;
      all.emplace_back(y);
    } else if (l == 0) {
      V += r, E += r;
      ltAdd[r].emplace_back(y);
    } else {
      assert(r == M);
      V += M - r, E += M - r;
      rtAdd[l].emplace_back(y);
    }
  }
  sort(all.begin(), all.end());
  long long inter = 0;
  for (int i = 1; i <= m; ++i) {
    int x, l, r;
    scanf("%d %d %d", &x, &l, &r);
    if (!all.empty()) {
      inter += upper_bound(all.begin(), all.end(), r) - lower_bound(all.begin(), all.end(), l);
    }
    if (l == 0 and r == M) {
      V += M - 1, E += M;
    } else if (l == 0) {
      V += r, E += r;
    } else {
      assert(r == M);
      V += M - r, E += M - r;
    }
    queries[x].emplace_back(l, r);
  }
  for (int i = 0; i < N; ++i) {
    for (int y : rtAdd[i]) {
      update(y, +1);
    }
    for (auto it : queries[i]) {
      inter += get(it.first, it.second);
    }
  }
  memset(f, 0, sizeof f);
  for (int i = N - 1; i >= 0; --i) {
    for (int y : ltAdd[i]) {
      update(y, +1);
    }
    for (auto it : queries[i]) {
      inter += get(it.first, it.second);
    }
  }
  V -= inter;
  cout << E - V + 1 << '\n';
  return 0;
}