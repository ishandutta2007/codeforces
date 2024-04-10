#include "bits/stdc++.h"

using namespace std;

optional<string> combine(const optional<string>& lhs, const optional<string> &rhs) {
  if (rhs.has_value())
    return rhs;
  else
    return lhs;
}

struct Fun {
  int to_flag[2];
  optional<string> to_color[2];

  Fun() {
    for (int b = 0; b < 2; ++b) {
      to_flag[b] = b;
      to_color[b] = nullopt;
    }
  }
};

Fun from_string(const string &s) {
  Fun res;

  if (s == "lock") {
    res.to_flag[0] = 1;
    return res;
  }

  if (s == "unlock") {
    res.to_flag[1] = 0;
    return res;
  }

  res.to_color[0] = optional<string>(s);
  return res;
}

Fun combine(const Fun& lhs, const Fun& rhs) {
  Fun res;
  for (int b = 0; b < 2; ++b) {
    res.to_flag[b] = rhs.to_flag[lhs.to_flag[b]];
    res.to_color[b] = combine(lhs.to_color[b], rhs.to_color[lhs.to_flag[b]]);
  }
  return res;
}

const int M = 100'100;

Fun tree[4 * M];
int n;

Fun add(int v, int l, int r, int at, const Fun& value) {
  assert(l <= at && at < r);

  if (l + 1 == r) {
    return tree[v] = value;
  }

  int m = (l + r) / 2;
  if (at < m) {
    return tree[v] = combine(add(2 * v, l, m, at, value),
                             tree[2 * v + 1]);
  } else {
    return tree[v] = combine(tree[2 * v],
                             add(2 * v + 1, m, r, at, value));
  }
}

string get_color() {
  return tree[1].to_color[0].value_or("blue");
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    Fun f = from_string(s);
    add(1, 0, n, i, f);
  }

  cout << get_color() << "\n";

  int t;
  cin >> t;
  while (t--) {
    int i;
    string s;
    cin >> i >> s;
    --i;
    Fun f = from_string(s);
    add(1, 0, n, i, f);
    cout << get_color() << "\n";
  }
  return 0;
}