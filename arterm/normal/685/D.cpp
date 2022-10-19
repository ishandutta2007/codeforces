#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 100100;
const int K = 303;

int n, k;
int x[M], y[M];
int a[M * K], b[M * K];
ll ans[M];
int m = 0;
int pre[M];
int *all;

void read() {
  cin >> n >> k;
  all = a;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
    for (int j = 0; j < k; ++j)
      all[m++] = y[i] + j;
  }

  sort(all, all + m);
  m = unique(all, all + m) - all;
}

int id(int x) {
  return lower_bound(all, all + m, x) - all;
}

void precalc() {
  for (int i = 0; i < n; ++i)
    pre[i] = id(y[i]);
}

void add(int y, int val, int cur) {
  int l = y;
  for (int i = l; i < l + k; ++i) {
    ans[a[i]] += cur - b[i];
    b[i] = cur;
    a[i] += val;
  }
}

void kill() {
  vector<pair<pair<int, int>, int>> events;
  for (int i = 0; i < n; ++i) {
    events.emplace_back(make_pair(x[i], pre[i]), 1);
    events.emplace_back(make_pair(x[i] + k, pre[i]), - 1);
  }

  fill(a, a + (M * K), 0);

  sort(events.begin(), events.end());

  for (int i = 0; i < (int) events.size(); ++i) {
    add(events[i].first.second, events[i].second, events[i].first.first);
  }

  for (int i = 1; i <= n; ++i)
    cout << ans[i] << " ";
  cout << "\n";
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  precalc();
  kill();
}