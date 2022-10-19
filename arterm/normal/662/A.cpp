#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int M = 500500;
const int N = 67;

bitset<M> a[N];

int m;
ull tot = 0;

void read() {
  cin >> m;
  for (int i = 0; i < m; ++i) {
    ull x, y;
    cin >> x >> y;
    x ^= y;
    tot ^= y;
    for (int j = 0; j < N; ++j)
      a[j][i] = (x >> j) & 1;
  }

  for (int j = 0; j < N; ++j)
    a[j][m] = (tot >> j) & 1;
}

void gaub() {
  int r = 0;
  for (int i = 0; i < m; ++i) {
    int x = -1;
    for (int j = r; j < N; ++j)
      if (a[j][i])
        x = j;

    if (x == -1)
      continue;

    swap(a[r], a[x]);
    for (int j = 0; j < N; ++j)
      if (j != r)
        if (a[j][i])
          a[j] ^= a[r];

    ++r;
  }

  for (int j = r; j < N; ++j)
    if (a[j][m]) {
      cout << "1/1\n";
      return;
    }

  ull pw = 1ull << ((ull) r);
  cout << (pw - 1) << "/" << pw << endl;
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);

  read();
  gaub();
}