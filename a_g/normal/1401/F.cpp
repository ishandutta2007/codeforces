#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(1<<n);
  vector<long long> b(1<<(n+1));
  int shift = 0;
  auto upd = [&] (int i, int x) {
    i ^= shift;
    for (int j = i+(1<<n); j > 0; j >>= 1) {
      b[j] += x-a[i];
    }
    a[i] = x;
  };
  auto query = [&] (int r) {
    long long ans = 0;
    if (r == (1<<n)) return b[1];
    int v = 1;
    for (int bit = n-1; bit >= 0; bit--) {
      int sb = (shift>>bit)&1;
      int rb = (r>>bit)&1;
      if ((r>>bit)&1) {
        ans += b[2*v+sb];
        v = 2*v+(1-sb);
      }
      else v = 2*v+sb;
    }
    return ans;
  };

  auto debug = [&] () {
    cout << "Shift: " << shift << '\n';
    for (int bit = 0; bit <= n; bit++) {
      for (int i = (1<<bit); i < (1<<(bit+1)); i++) {
        cout << b[i] << ' ';
      }
      cout << '\n';
    }
  };

  for (int i = 0; i < (1<<n); i++) {
    int x;
    cin >> x;
    upd(i, x);
  }

  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, k;
      cin >> x >> k;
      upd(x-1, k);
    }
    else if (type == 2) {
      int k;
      cin >> k;
      shift ^= (1<<k)-1;
    }
    else if (type == 3) {
      int k;
      cin >> k;
      shift ^= 1<<k;
    }
    else {
      assert(type == 4);
      int l, r;
      cin >> l >> r;
      cout << query(r)-query(l-1) << '\n';
    }
  }
}