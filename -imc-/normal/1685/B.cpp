#include <bits/stdc++.h>

using namespace std;

using li = long long;
using ld = long double;

#define all(v) (v).begin(), (v).end()

struct item {
  int base{};
  // AB, BA
  int bonus_a{}, bonus_b{};

  bool operator<(const item& rhs) const {
    return base > rhs.base;
  }
};

void solve(bool read) {
  int _a, _b, a, b;
  string s;
  cin >> _a >> _b >> a >> b >> s;

  int cnt_a = count(all(s), 'A');
  int cnt_b = count(all(s), 'B');
  if (cnt_a != _a + a + b) {
    cout << "NO\n";
    return;
  }
  if (cnt_b != _b + a + b) {
    cout << "NO\n";
    return;
  }

  int n = s.size();
  s += '$';

  vector<item> items;

  int l = 0;
  while (l < n) {
    bool start = false;

    if (s[l] == 'B') {
      start = true;
      ++l;
    }
    int base = 0;
    while (l + 1 < n && s[l] == 'A' && s[l + 1] == 'B') {
      l += 2;
      base += 1;
    }

    bool end = false;
    if (s[l] == 'A') {
      end = true;
      ++l;
    }

    item it{base};
    if (start && end) {
      it.bonus_b = 1;
    }
    if (!start && !end) {
      it.bonus_a = 1;
      assert(it.base > 0);
      --it.base;
    }

    items.push_back(it);
  }

  int mx_a = 0, mx_b = 0;
  int free = 0;
  for (auto it : items) {
    if (it.bonus_a) {
      mx_a += it.bonus_a + it.base;
    } else if (it.bonus_b) {
      mx_b += it.bonus_b + it.base;
    } else {
      free += it.base;
    }
  }

  if (free + mx_a + mx_b < a + b) {
    cout << "NO\n";
    return;
  }

  assert((mx_b + free >= b) || (mx_a + free >= a));
  //cout << "YES?\n";

  if (mx_a + free >= a) {
    swap(a, b);
    swap(mx_a, mx_b);
    for (auto& it : items) swap(it.bonus_a, it.bonus_b);
  }

  assert(mx_b + free >= b);

  int cur_b = mx_b + free;
  int cur_a = mx_a;

  vector<item> sw;
  for (auto it : items) {
    if (it.bonus_b) {
      sw.push_back(it);
    }
  }
  sort(all(sw));

  int pos = 0;
  while (cur_a < a) {
    if (free > 0) {
      --free;
      --cur_b;
      ++cur_a;
      continue;
    }

    if (pos < sw.size()) {
      --cur_b;
      free += sw[pos].base;
      ++pos;
      continue;
    }

    break;
  }

  if (cur_a >= a && cur_b >= b) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }

  //solve(false);

  return 0;
}