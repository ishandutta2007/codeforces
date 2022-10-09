#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1005;
const int inf = 1000000000;
const unsigned int maxrnd = (1LL << 32) - 1;

int greseli[MAXN];

long double lgput(long double a, int b) {
  long double ans = 1.0;
  for (; b; b >>= 1) {
    if (b & 1)
      ans *= a;
    a *= a;
  }
  return ans;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  while (m--) {
    string s;
    cin >> s;

    int mnm = inf;
    for (int i = 1; i <= n; ++i)
      mnm = min(mnm, greseli[i]);

    long double f0 = 0, f1 = 0;
    for (int i = 1; i <= n; ++i) {
      if (greseli[i] - mnm + 1 <= inf) {
        if (s[i - 1] == '0')
          f0 += lgput(0.5, greseli[i] - mnm);
        else
          f1 += lgput(0.5, greseli[i] - mnm);
      }
    }

    double rnd = 1.0 * rng() / maxrnd;

    if (rnd <= f0 / (f0 + f1)) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
    }

    int answer;
    cin >> answer;
    for (int i = 1; i <= n; ++i)
      if (s[i - 1] - '0' != answer)
        greseli[i]++;
  }

  return 0;
}