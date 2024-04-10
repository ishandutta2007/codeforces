#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int n, ans[N];
bitset <N> out;
vector <int> d[N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j += i) {
      d[i].emplace_back(j);
    }
    reverse(d[i].begin(), d[i].end());
  }
  for (int i = n, j = n; i > 1; --i) {
    int cur;
    while (j > 1) {
      cur = 0;
      for (int x : d[j]) if (!out[x]) {
        ++cur;
        if (cur > 1) break;
      }
      if (cur <= 1) {
        --j; continue;
      } else {
        break;
      }
    }
    ans[i] = j;
    if (j > 1) {
      for (int x : d[j]) if (!out[x]) {
        out[x] = 1; break;
      }
      --cur;
      if (cur <= 1) {
        while (j > 1) {
          cur = 0;
          for (int x : d[j]) if (!out[x]) {
            ++cur;
            if (cur > 1) break;
          }
          if (cur <= 1) {
            --j; continue;
          } else {
            break;
          }
        } 
      }
    }
  }
  for (int i = 2; i <= n; ++i) printf("%d ", ans[i]); puts("");
  return 0;
}