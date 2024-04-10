#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

vector <int> vec[N], fenw[N];
int n, k, x[N], r[N], f[N], id[N], rev[N];

void update (int who, int p, int v) {
  while (p < fenw[who].size()) fenw[who][p] += v, p += p & -p;
}

int pref (int who, int p) {
  int ret = 0;
  while (p) ret += fenw[who][p], p -= p & -p;
  return ret;
}

inline int get (int who, int l, int r) {
  if (l > r) return 0;
  return pref(who, r) - (l ? pref(who, l - 1) : 0);
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d %d", x + i, r + i, f + i);
    id[i] = i, vec[f[i]].emplace_back(i);
  }
  for (int i = 0; i < N; ++i) {
    if (vec[i].empty()) continue;
    vec[i].emplace_back(0);
    sort(vec[i].begin(), vec[i].end(), [] (int p, int q) {
      return x[p] < x[q];
    });
    fenw[i].resize(vec[i].size(), 0);
    for (int j = 0; j < vec[i].size(); ++j) {
      rev[vec[i][j]] = j, vec[i][j] = x[vec[i][j]];
    }
  }
  sort(id + 1, id + n + 1, [] (int i, int j) {
    return r[i] > r[j];
  });
  long long ans = 0;
  for (int it = 1; it <= n; ++it) {
    int i = id[it];
    // cout << x[i] << " " << r[i] << " " << f[i] << " " << rev[i] << '\n';
    for (int oth = max(0, f[i] - k); oth <= f[i] + k; ++oth) {
      if (vec[oth].empty()) continue;
      int lt = lower_bound(vec[oth].begin(), vec[oth].end(), x[i] - r[i]) - vec[oth].begin();
      int rt = upper_bound(vec[oth].begin(), vec[oth].end(), x[i] - 1) - vec[oth].begin() - 1;
      // cout << lt << " " << rt << '\n';
      ans += get(oth, lt, rt);
      lt = lower_bound(vec[oth].begin(), vec[oth].end(), x[i] + 1) - vec[oth].begin();
      rt = upper_bound(vec[oth].begin(), vec[oth].end(), x[i] + r[i]) - vec[oth].begin() - 1;
      ans += get(oth, lt, rt);
    }
    update(f[i], rev[i], 1);
  }
  cout << ans << '\n';
  return 0;
}