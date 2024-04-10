#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int t, n;
char a[N], b[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%d %s %s", &n, a + 1, b + 1);
    vector <int> ans;
    int l = 1, r = n, inv = 0;
    for (int i = n; i >= 1; --i) {
      int st = a[l] ^ inv, en = a[r] ^ inv;
      if (b[i] == en) {
        if (l > r) ++r; else --r;
        continue;
      }
      if (b[i] == st) {
        a[l] ^= 1, ans.emplace_back(1);
      }
      swap(l, r), inv ^= 1;
      if (l > r) ++r; else --r;
      ans.emplace_back(i);
    }
    printf("%d", (int) ans.size());
    for (int x : ans) printf(" %d", x); puts("");
  }
  return 0;
}