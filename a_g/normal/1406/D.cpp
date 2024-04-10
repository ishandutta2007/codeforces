#include <bits/stdc++.h>
using namespace std;

long long ceil(long long x, int y) {
  if (x >= 0) {
    return (x+y-1)/y;
  }
  return x/y;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  long long first;
  cin >> first;
  long long pr = first;

  vector<long long> d(n-1);
  long long pos = 0;
  for (int i = 0; i < n-1; i++) {
    long long a;
    cin >> a;
    d[i] = a-pr;
    pr = a;
    if (d[i] > 0) pos += d[i];
  }
  d.push_back(-1e18);

  cout << ceil(first+pos, 2) << '\n';

  int q;
  cin >> q;
  while (q--) {
    int l, r, x;
    cin >> l >> r >> x;
    if (l == 1) {
      first += x;
    }

    for (int j: {l-2, r-1}) {
      if (j >= 0 && d[j] > 0) {
        pos -= d[j];
      }
    }
    if (l >= 2) d[l-2] += x;
    d[r-1] -= x;
    for (int j: {l-2, r-1}) {
      if (j >= 0 && d[j] > 0) {
        pos += d[j];
      }
    }
    cout << ceil(first+pos, 2) << endl;
  }
}