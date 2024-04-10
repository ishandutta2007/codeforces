#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    if (n == 2) {
      cout << 2 << '\n';
      continue;
    }
    if (n % 2 == 0) {
      cout << 0 << '\n';
    } else {
      cout << 1 << '\n';
    }
  }
}