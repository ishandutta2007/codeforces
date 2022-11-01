#include <bits/stdc++.h> 

using namespace std;

const int N = 100010;

int n, k, w[N];

int main (int argc, char const *argv[]) {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", w + i);
  }
  sort(w + 1, w + n + 1, greater <int> ());
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    if (w[i] <= 0) continue;
    res += w[i]/(k + k);
    w[i] %= (k + k);
    if (w[i] == 0) {
      continue;
    } else if (w[i] > k) {
      ++res;
    } else {
      ++res;
      w[i + 1] -= k;
    }
  }
  cout << res << '\n';
  return 0;
}