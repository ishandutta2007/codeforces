#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int t, n, a[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    vector <int> x;
    for (int i = 1; i <= n; ++i) {
      if (i == 1 or i == n) x.emplace_back(a[i]); 
      else {
        if ((a[i - 1] < a[i]) != (a[i] < a[i + 1])) {
          x.emplace_back(a[i]);
        }
      }
    }
    printf("%d\n", (int) x.size());
    for (auto it : x) printf("%d ", it); puts("");
  }
  return 0;
}