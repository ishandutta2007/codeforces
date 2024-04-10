#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 bigInt;

const int N = 1000010;

bitset <N> vis;
bigInt k, l, r, t, x, y;

inline void get (bigInt &inp) {
  ll tmp; cin >> tmp; inp = tmp;
}

int main() {
  get(k); get(l); get(r);
  get(t); get(x); get(y);
  k -= l, r -= l;
  if (y <= x) {
    if (k + y <= r) k += y;
    k -= x, --t;
    if (k < 0) {
      cout << "No\n";
      return 0;
    }
    bigInt out = x - y;
    if (k - out * t < 0) {
      cout << "No\n";
      return 0;
    }
    cout << "Yes\n";
    return 0; 
  }
  t -= k / x, k %= x, vis[k] = 1;
  while (t > 0) {
    if (k + y > r) {
      cout << "No\n";
      return 0;
    }
    bigInt canAdd = (r - x - k) / (y - x);
    k += canAdd * (y - x), t -= canAdd;
    if (t <= 0) break;
    t -= k / x, k %= x;
    if (vis[k]) break; vis[k] = 1;
  }
  cout << "Yes\n";
  return 0;
}