#include <bits/stdc++.h>

using namespace std;

const int N = 10005;
const int SHIFT = 5002;

vector <int> hor, ver;
int n, x[N][2], y[N][2], f[N];

void update (int p, int v) {
  while (p < N) f[p] += v, p += p & -p;
}

int pref (int p) {
  int ret = 0;
  while (p > 0) ret += f[p], p -= p & -p;
  return ret;
}

inline int get (int l, int r) {
  return pref(r) - pref(l - 1);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d %d %d", x[i], y[i], x[i] + 1, y[i] + 1);
    x[i][0] += SHIFT, y[i][0] += SHIFT;
    x[i][1] += SHIFT, y[i][1] += SHIFT; 
    if (x[i][0] == x[i][1]) {
      ver.emplace_back(i);
      if (y[i][0] > y[i][1]) swap(y[i][0], y[i][1]);
    } else {
      hor.emplace_back(i);
      if (x[i][0] > x[i][1]) swap(x[i][0], x[i][1]);
    }
  }
  sort(ver.begin(), ver.end(), [] (int i, int j) {return x[i][0] < x[j][0];});
  long long ans = 0;
  for (int l = 0; l < ver.size(); ++l) {
    int cur = ver[l];
    memset(f, 0, sizeof f);
    vector <pair <int, int>> vec;
    for (int i : hor) if (x[i][0] <= x[cur][0] and x[cur][0] <= x[i][1] and y[cur][0] <= y[i][0] and y[i][0] <= y[cur][1]) {
      update(y[i][0], +1);
      vec.emplace_back(x[i][1], i);
    }
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    for (int r = l + 1; r < ver.size(); ++r) {
      int rt = ver[r];
      while (!vec.empty() and vec.back().first < x[rt][0]) {
        update(y[vec.back().second][0], -1);
        vec.pop_back();
      }
      long long cnt = get(y[rt][0], y[rt][1]);
      ans += cnt * (cnt - 1) / 2;
    }
  }
  cout << ans << '\n';
  return 0;
}