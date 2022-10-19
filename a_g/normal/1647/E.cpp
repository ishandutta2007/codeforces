#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
int p[N], a[N], q[N], b[N], bound[N];
int tmp1[N], tmp2[N];
bool vis[N], cyclelen[N], dist[N];
vector<int> pre[N];
vector<int> preq[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    pre[p[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int missing = 0;
  for (int i = 1; i <= n; i++) {
    if (!pre[i].size()) missing++;
  }
  int M = *max_element(a+1, a+n+1);
  assert((M-n)%(missing) == 0);
  int rounds = (M-n)/missing;
  // q = p^rounds
  iota(q, q+n+1, 0);
  for (int i = 1; i <= n; i++) {
    tmp1[i] = p[i];
  }
  while (rounds) {
    if (rounds&1) {
      for (int i = 1; i <= n; i++) {
        tmp2[i] = q[tmp1[i]];
      }
      for (int i = 1; i <= n; i++) {
        q[i] = tmp2[i];
      }
    }
    for (int i = 1; i <= n; i++) {
      tmp2[i] = tmp1[tmp1[i]];
    }
    for (int i = 1; i <= n; i++) {
      tmp1[i] = tmp2[i];
    }
    rounds >>= 1;
  }

  set<int> s;
  for (int i = 1; i <= n; i++) {
    preq[q[i]].push_back(i);
    s.insert(i);
  }

  for (int i = 1; i <= n; i++) {
    if (preq[i].size()) {
      assert(a[i] <= n);
      b[preq[i][0]] = a[i];
      s.erase(a[i]);
      for (int j: preq[i]) {
        bound[j] = a[i];
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!b[i]) {
      b[i] = *s.lower_bound(bound[i]);
      s.erase(b[i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << b[i] << ' ';
  }
  cout << '\n';
}