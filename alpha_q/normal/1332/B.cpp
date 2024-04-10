#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int t, n, a[N], ans[N];
vector <int> pr = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    memset(ans, 0, sizeof ans);
    int ptr = 0;
    for (int i = 0; i < 11; ++i) {
      int p = pr[i], tot = 0;
      for (int j = 0; j < n; ++j) {
        if (!ans[j] and a[j] % p == 0) ++tot; 
      }
      if (!tot) continue; ++ptr;
      for (int j = 0; j < n; ++j) {
        if (!ans[j] and a[j] % p == 0) ans[j] = ptr; 
      }
    }
    printf("%d\n", ptr);
    for (int i = 0; i < n; ++i) printf("%d ", ans[i]); puts("");
  }
  return 0;
}