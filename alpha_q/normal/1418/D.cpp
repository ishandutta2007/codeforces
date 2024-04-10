#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, q;
set <ll> coo;
multiset <ll> diff;

inline void insert (ll x) {
  auto it = coo.upper_bound(x);
  if (it != coo.end()) {
    diff.emplace(*it - x);
    if (it != coo.begin()) {
      diff.erase(diff.find(*it - *prev(it)));
    }
  }
  if (it != coo.begin()) {
    diff.emplace(x - *prev(it));
  }
  coo.emplace(x);
}

inline void remove (ll x) {
  auto it = coo.find(x);
  if (it != coo.begin()) {
    diff.erase(diff.find(x - *prev(it)));
    if (next(it) != coo.end()) {
      diff.emplace(*next(it) - *prev(it));
    }
  }
  if (next(it) != coo.end()) {
    diff.erase(diff.find(*next(it) - x));
  }
  coo.erase(it);
}

inline ll get() {
  if (coo.size() <= 2) return 0;
  ll ans = *coo.rbegin() - *coo.begin() - *diff.rbegin();
  return ans;
}

int main() {
//  freopen("in.txt", "r", stdin);
  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    ll x;
    scanf("%lld", &x);
    insert(x);
  }
  cout << get() << '\n';
  while (q--) {
    int cmd; ll x;
    scanf("%d %lld", &cmd, &x);
    if (cmd) insert(x);
    else remove(x);
    printf("%lld\n", get());
  }
  return 0;
}