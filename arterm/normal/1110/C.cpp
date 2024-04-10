#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

int gcd(int x, int y) {
  while (x) {
    y %= x;
    swap(x, y);
  }
  return y;
}

int f(int a) {
  int ans = 0;
  for (int b = 1; b < a; ++b)
    ans = max(ans, gcd(a ^ b, a & b));
  return ans;
}

map<int, int> mem;

int get(int x) {
  int k = 0;
  while ((1 << k) <= x) {
    ++k;
  }
  if ((1 << k) - 1 == x) {
    if (mem.count(x))
      return mem[x];
    int cur = (1 << k) - 1;
    for (int y = 2; y * y <= cur; ++y)
      if (cur % y == 0)
        return mem[x] = cur / y;
    return mem[x] = 1;
  } else {
    return (1 << k) - 1;
  }
}

int main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  //for (int a = 2; a < 2000; ++a) {
    //if (f(a) != get(a)) {
      //cerr << a << ": " << f(a) << " vs " << get(a) << "!\n";
    //}
    //assert(f(a) == get(a));
  //}

  //return 0;

  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    cout << get(x) << "\n";
  }
}