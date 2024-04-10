#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int& x: a) cin >> x;
  set<int, greater<int>> pos, neg;
  function<void(int)> add = [&] (int k) {
    if (neg.count(k)) {
      neg.erase(k);
      return;
    }
    if (pos.count(k)) {
      pos.erase(k);
      add(k+1);
      return;
    }
    pos.insert(k);
  };

  function<void(int)> sub = [&] (int k) {
    if (pos.count(k)) {
      pos.erase(k);
      return;
    }
    if (neg.count(k)) {
      neg.erase(k);
      sub(k+1);
      return;
    }
    neg.insert(k);
  };

  for (int x: a) add(x);

  while (q--) {
    int k, l;
    cin >> k >> l;
    k--;
    sub(a[k]);
    a[k] = l;
    add(a[k]);
    while (neg.size() && *neg.begin() == *pos.begin()-1) {
      int k = *neg.begin();
      sub(k+1);
      add(k);
      add(k);
    }
    assert(pos.size());
    int ans = *pos.begin();
    if (pos.size() == 1 && neg.size() > 0) {
      ans--;
    }
    else if (pos.size() > 1 && neg.size() > 0) {
      if (*next(pos.begin()) < *neg.begin()) {
        ans--;
      }
    }
    cout << ans << '\n';
  }
}