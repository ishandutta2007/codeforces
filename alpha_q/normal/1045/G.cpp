#include <bits/stdc++.h>

using namespace std;

#pragma gcc diagnostic warning "-std=c++11"

const int N = 100010;

vector <int> f[N];
vector <vector <int>> t[N];
unordered_map <int, vector <int>> same;
int n, k, x[N], r[N], iq[N], id[N];
unordered_map <int, int> comp;

bool cmp (int i, int j) {
  return x[i] < x[j];
}

int query (int cur_iq, int l, int r, int x) {
  int ret = 0, sz = f[cur_iq].size();
  for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ret += (upper_bound(t[cur_iq][l].begin(), t[cur_iq][l].end(), x) - t[cur_iq][l].begin()), ++l;
    if (r & 1) --r, ret += (upper_bound(t[cur_iq][r].begin(), t[cur_iq][r].end(), x) - t[cur_iq][r].begin());
  }
  return ret;
}

inline int get (int cur_iq, int l, int r) {
  if (comp.find(cur_iq) == comp.end()) return 0;
  // cout << cur_iq << endl;
  // for (int xx : f[cur_iq]) cout << xx << " "; cout << endl;
  // cout << " ----> " << (upper_bound(f[cur_iq].begin(), f[cur_iq].end(), l) - f[cur_iq].begin()) << endl;
  int it = comp[cur_iq];
  return query(it, upper_bound(f[it].begin(), f[it].end(), r) - f[it].begin(), upper_bound(f[it].begin(), f[it].end(), l) - f[it].begin(), r);
}

void brute() {
  int yo = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      int ii = i, jj = j;
      if (x[ii] > x[jj]) swap(ii, jj);
      if (x[jj] <= x[ii] + r[ii] and x[jj] - r[jj] <= x[ii] and abs(iq[ii] - iq[jj]) <= k) {
        ++yo;
        // cout << i << " " << j << endl;
      }
    }
  }
  cout << yo << '\n';
}

vector <int> tmp;

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d %d", x + i, r + i, iq + i);
    same[x[i]].push_back(iq[i]);
    id[i] = i;
    tmp.push_back(iq[i]);
  }
  sort(tmp.begin(), tmp.end());
  tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
  for (int i = 0; i < tmp.size(); ++i) {
    comp[tmp[i]] = i;
  } 
  sort(id + 1, id + n + 1, cmp);
  for (int it = 1; it <= n; ++it) {
    int i = id[it];
    f[comp[iq[i]]].push_back(i);
  }
  for (int it = 0; it < tmp.size(); ++it) {
    int cur_iq = tmp[it];
    int sz = f[it].size();
    vector <vector <int>> &tr = t[it];
    tr.resize(sz + sz);
    for (int j = 0; j < sz; ++j) {
      tr[sz + j].push_back(x[f[it][j]] - r[f[it][j]]);
      f[it][j] = x[f[it][j]];
    }
    for (int j = sz - 1; j; --j) {
      merge(tr[j << 1].begin(), tr[j << 1].end(), tr[j << 1 | 1].begin(), tr[j << 1 | 1].end(), back_inserter(tr[j]));
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    int cur_iq = iq[i];
    for (int j = cur_iq - k; j <= cur_iq + k; ++j) {
      ans += (long long) get(j, x[i] + r[i], x[i]);
    }
    // cout << i << " ##### " << ans << endl;
  }
  // cout << ans << endl;
  for (auto it : same) {
    vector <int> &v = it.second;
    int sz = v.size();
    sort(v.begin(), v.end());
    for (int i = 0, j = 0; i < sz; ++i) {
      while (j + 1 < sz and v[j + 1] - v[i] <= k) {
        ++j;
      }
      ans += (j - i);
    }
  }
  printf("%lld\n", ans);
  // brute();
  return 0;
}