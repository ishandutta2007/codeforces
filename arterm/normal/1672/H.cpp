#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const int M = 200200;

int n, q;
string s;

struct Fenwick {
  vector<int> t;

  Fenwick() : t(M) {
//    fill(t, t + M, 0);
  }

  void add(int at, int what) {
    for (int i = at; i < M; i |= (i + 1))
      t[i] += what;
  }

  int sum(int r) {
    int ans = 0;
    for (int i = r - 1; i >= 0; i = (i & (i + 1)) - 1)
      ans += t[i];
    return ans;
  }

  int sum(int l, int r) {
    return sum(r) - sum(l);
  }
} F[2];

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> q;
  cin >> s;

  for (int i = 0; i + 1 < n; ++i) {
    if (s[i] == '0' && s[i + 1] == '0') {
      F[0].add(i, 1);
    }

    if (s[i] == '1' && s[i + 1] == '1') {
      F[1].add(i, 1);
    }
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    --l;

    int x = F[0].sum(l, r - 1);
    int y = F[1].sum(l, r - 1);

//    cerr << x << " " << y << endl;

    cout << max(x, y) + 1 << "\n";
  }

  return 0;
}