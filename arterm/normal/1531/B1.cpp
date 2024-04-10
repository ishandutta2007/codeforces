#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

map<int, int> cnt_open, cnt_close;
map<pair<int, int>, int> cnt;

void add(int l, int r, int by) {
  cnt_open[l] += by;
  if (l < r)
    cnt_close[r] += by;

  cnt[make_pair(l, r)] += by;
}

int main() {
  int n;
  vector<pair<int, int>> segs;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    if (l > r)
      swap(l, r);

    add(l, r, +1);

    segs.emplace_back(l, r);
  }

  ll ans = 0;

  for (const auto& [l, r] : segs) {
    add(l, r, -1);

    if (l < r) {
      ans += cnt_open[l];
      ans += cnt_open[r];
      ans += cnt_close[l];
      ans += cnt_close[r];
      ans -= cnt[make_pair(l, r)];
    } else {
      ans += cnt_open[l];
      ans += cnt_close[l];
    }

    add(l, r, +1);
  }

  assert(ans % 2 == 0);
  ans /= 2;

  cout << ans << "\n";
  return 0;
}