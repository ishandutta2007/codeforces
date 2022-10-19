#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 1010;

int n, a[M], h;
int b[M];

void read() {
  cin >> n >> h;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
}

bool check(int n) {
  copy(a, a + n, b);
  sort(b, b + n, greater<int>());
  ll s = 0;
  for (int i = 0; i < n; i += 2) {
    s += b[i];
  }
  return s <= h;
}

void kill() {
  int l = 0, r = n;
  while (l < r) {
    int m = (l + r) / 2;
    if (check(m + 1))
      l = m + 1;
    else
      r = m;
  }
  cout << l << "\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();

}