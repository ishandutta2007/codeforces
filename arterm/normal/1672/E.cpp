#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const int inf = 1e9;

int ask(int w) {
  cout << "? " << w << endl;
  int res;
  cin >> res;
  if (res == 0)
    res = inf;
  return res;
}

void say(int x) {
  cout << "! " << x << endl;
  exit(0);
}

int n;

int bin() {
  int l = 1, r = 3000 * 3000;
  while (l < r) {
    int m = (l + r) / 2;
    if (ask(m) == 1)
      r = m;
    else
      l = m + 1;
  }

  return l + 1;
}

int main() {
//  ios_base::sync_with_stdio(false);

  cin >> n;

  int s = bin();
  ll ans = s - 1;

  for (int k = 2; k <= n; ++k) {
    int w = (s + k - 1) / k - 1;

    int h = ask(w);
    if (h <= n)
      ans = min<ll>(ans, 1ll * h * w);
  }

  say(ans);

  return 0;
}