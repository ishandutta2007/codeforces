#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int u, v;
    scanf("%d%d", &u, &v);
    bool ans = u <= v;
    int cnt_u = 0, cnt_v = 0;
    for (int i = 0; i < 30; i++) {
      cnt_u += u >> i & 1;
      cnt_v += v >> i & 1;
      ans &= cnt_u >= cnt_v;
    }
    puts(ans ? "YES" : "NO");
  }
  return 0;
}