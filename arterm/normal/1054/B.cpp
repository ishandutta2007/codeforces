#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 100100;

bool u[M];
int mex;

bool on(int x) {
  if (x > mex) return false;
  u[x] = true;
  while (u[mex]) ++mex;
  return true;
}

int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  fill(u, u + M, false);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (!on(x)) {
      cout << (i + 1) << "\n";
      return 0;
    }
  }
  cout << "-1\n";
}