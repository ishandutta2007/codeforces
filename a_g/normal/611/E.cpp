#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/611/submission/113696532
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  while (a > b || b > c) {
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
  }

  int ans = 0;
  multiset<int, greater<int>> s;
  auto greedy = [&] (int x) {
    auto it = s.lower_bound(x);
    if (it == s.end()) return false;
    s.erase(it);
    return true;
  };

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (a+b+c < x) {
      cout << "-1\n";
      return 0;
    }
    if (b+c < x) {
      ans++;
      continue;
    }
    s.insert(x);
  }

  while (s.size()) {
    int big = *s.begin();
    if (big > a+c) {
      ans++;
      greedy(b+c);
      greedy(a);
    }
    else if (big > max(a+b, c)) {
      ans++;
      greedy(a+c);
      greedy(b);
    }
    else if (big > c) {
      ans++;
      greedy(a+b);
      greedy(c);
    }
    else if (greedy(b)) {
      ans++;
      greedy(a);
      greedy(c);
    }
    else {
      ans++;
      greedy(a+b);
      greedy(c);
    }
  }

  cout << ans << '\n';
}