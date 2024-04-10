#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

const int MAX_N = 1e6 + 5;

bool can [MAX_N];

int gcd (int p, int q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    can[x] = 1;
  }

  int ans = 0;
  for (int i = MAX_N - 1; i >= 1; i--) {
    int gc = 0;
    for (int j = i; j < MAX_N; j += i) {
      if (can[j]) {
        gc = gcd(gc, j);
      }
    }
    can[i] |= gc == i;

    if (can[i]) {
      ans++;
    }
  }

  cout << ans - n << '\n';
}