#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll sum[2], tot;
set <ll> s[2], one, two;

inline void insert (ll x) {
  int bad = s[1].size();
  if (two.size() == bad) {
    one.emplace(x);
    if (!two.empty() and *one.rbegin() > *two.begin()) {
      ll y = *one.rbegin(), z = *two.begin();
      one.erase(y), two.erase(z), tot -= z;
      one.emplace(z), two.emplace(y), tot += y;
    }
  } else {
    assert(two.size() == bad - 1);
    two.emplace(x), tot += x;
    if (!one.empty() and *one.rbegin() > *two.begin()) {
      ll y = *one.rbegin(), z = *two.begin();
      one.erase(y), two.erase(z), tot -= z;
      one.emplace(z), two.emplace(y), tot += y;
    }
  }
}

inline void remove (ll x) {
  int bad = s[1].size();
  if (one.count(x)) one.erase(x);
  else two.erase(x), tot -= x;
  if (two.size() != bad) {
    if (two.size() == bad + 1) {
      ll y = *two.begin(); two.erase(y);
      tot -= y, one.emplace(y);
    } else if (two.size() == bad - 1) {
      ll y = *one.rbegin(); one.erase(y);
      two.emplace(y), tot += y;
    } else {
      assert(false);
    }
  } 
}

int main() {
  cin >> n;
  while (n--) {
    int cmd; ll x;
    scanf("%d %lld", &cmd, &x);
    if (x > 0) s[cmd].emplace(x), sum[cmd] += x, insert(x);
    else s[cmd].erase(-x), sum[cmd] += x, remove(-x);
    if (s[1].empty()) {
      // cout << "yo1\n";
      printf("%lld\n", sum[0]);
    } else if (s[0].empty()) {
      // cout << "yo2\n";
      ll ans = 2 * sum[1] - *s[1].begin();
      printf("%lld\n", ans);
    } else {
      // cout << "yo3\n";
      if (*s[0].rbegin() < *s[1].begin()) {
        ll ans = sum[0] + 2 * sum[1] - *s[1].begin() + *s[0].rbegin();
        printf("%lld\n", ans);
      } else {
        // cout << "yo4\n";
        // cout << sum[0] << " " << sum[1] << " " << tot << '\n';
        ll ans = sum[0] + sum[1] + tot;
        printf("%lld\n", ans);
      }
    }
  }
  return 0;
}

// all 2 ---> 2 * sum - minVal
// a b c d e f g --> 


// a b c d e f
// x good y bad

// a0 a1 a2 ..., aq x
// p good q bad --> p + q = y, p > 0 --> q < y
// a b c d e f g h i j k l m