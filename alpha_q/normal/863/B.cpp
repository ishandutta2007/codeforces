#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> v;

int main() {
  cin >> n;
  for (int i = 0; i < n + n; ++i) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  int best = 2e9 + 5;
  for (int i = 0; i < n + n; ++i) {
    for (int j = i + 1; j < n + n; ++j) {
      vector <int> w;
      for (int k = 0; k < n + n; ++k) {
        if (k == i or k == j) continue;
        w.push_back(v[k]);
      }
      int tot = 0;
      for (int k = 0; k < n + n - 2; k += 2) {
        tot += (w[k + 1] - w[k]);
      }
      best = min(best, tot);
    }
  }
  cout << best << endl;
  return 0;
}