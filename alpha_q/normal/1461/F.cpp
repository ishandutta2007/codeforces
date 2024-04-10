#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100010;
const ll INF = 1e9 + 69;

int n, a[N];
string good;
bitset <N> mul;

void fuck (int ss, int ee) {
  int st = ss, en = ee;
  while (st <= ee and a[st] == 1) ++st;
  while (en >= ss and a[en] == 1) --en;
  ll prod = 1;
  for (int i = ss; i <= ee; ++i) prod = min(INF, prod * a[i]);
  if (prod > 5e5) {
    for (int i = st + 1; i <= en; ++i) mul[i] = 1;
    return;
  }
  vector <ll> vec;
  vector <pair <int, int>> range;
  for (int i = st; i <= en;) {
    int j = i; 
    ll cur = 1, cnt = 0;
    while (j <= en and a[j] != 1) {
      if (j > i) mul[j] = 1;
      cur = min(INF, cur * a[j++]);
    }
    vec.emplace_back(cur);
    if (j > en) break;
    int from = j;
    while (j <= en and a[j] == 1) ++cnt, ++j;
    range.emplace_back(from, j - 1);
    vec.emplace_back(cnt); i = j;
  }
  if (vec.size() > 1) {
    assert(vec.size() & 1);
    int sz = (vec.size() - 1) / 2;
    ll opt = 0; int opt_mask = -1;
    for (int mask = 0; mask < 1 << sz; ++mask) {
      ll cur = vec[0], tot = 0;
      for (int i = 1, j = 0; i + 1 < vec.size(); i += 2, ++j) {
        ll cnt = vec[i], val = vec[i + 1];
        if (mask & 1 << j) tot += cur + cnt, cur = val;
        else cur *= val;
      }
      tot += cur; 
      if (tot > opt) opt = tot, opt_mask = mask;
    }
    for (int i = 1, j = 0; i + 1 < vec.size(); i += 2, ++j) {
      ll cnt = vec[i], val = vec[i + 1];
      if (~opt_mask & 1 << j) {
        auto [l, r] = range[j];
        for (int p = l; p <= r + 1; ++p) mul[p] = 1;
      }
    }
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  cin >> good;
  sort(good.begin(), good.end());
  if (good.size() == 1 or good == "+-") {
    for (int i = 1; i <= n; ++i) {
      if (i > 1) putchar(good[0]);
      printf("%d", a[i]);
    }
    cout << '\n';
    return 0;
  }
  if (good == "*-") {
    int firstZero = 1;
    while (firstZero <= n and a[firstZero]) ++firstZero;
    for (int i = 1; i <= n; ++i) {
      if (i > 1) putchar(i == firstZero ? '-' : '*');
      printf("%d", a[i]);
    }
    cout << '\n';
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 0) continue;
    int j = i;
    while (j <= n and a[j]) ++j;
    fuck(i, j - 1);
    i = j - 1;
  }
  for (int i = 1; i <= n; ++i) {
    if (i > 1) putchar(mul[i] ? '*' : '+');
    printf("%d", a[i]);
  }
  cout << '\n';
  return 0;
}