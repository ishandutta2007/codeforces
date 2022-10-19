#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
const int K = 400;
int s[N], sml[K][K], time_added[N], x[N], y[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];

  for (int t = 1; t <= m; t++) {
    s[t] += s[t-1];
    int op, k;
    cin >> op >> k;
    if (op == 1) {
      time_added[k] = t;
      if (x[k]+y[k] < K) {
        for (int i = x[k]; i < x[k]+y[k]; i++) {
          sml[x[k]+y[k]][(t+i)%(x[k]+y[k])]++;
        }
      }
      else {
        int cur = t;
        while (1) {
          if (cur+x[k] >= N) break;
          s[cur+x[k]]++;
          if (cur+x[k]+y[k] >= N) break;
          s[cur+x[k]+y[k]]--;
          cur += x[k]+y[k];
        }
      }
    }
    else {
      assert(op == 2);
      if (x[k]+y[k] < K) {
        for (int i = x[k]; i < x[k]+y[k]; i++) {
          sml[x[k]+y[k]][(time_added[k]+i)%(x[k]+y[k])]--;
        }
      }
      else {
        int cur = time_added[k];
        while (1) {
          if (cur+x[k] >= N) break;
          if (cur+x[k] > t) s[cur+x[k]]--;
          if (cur+x[k] <= t && cur+x[k]+y[k] >= t) s[t]--;
          if (cur+x[k]+y[k] >= N) break;
          s[cur+x[k]+y[k]]++;
          cur += x[k]+y[k];
        }
      }
    }
    int ans = s[t];
    for (int i = 1; i < K; i++) {
      ans += sml[i][t%i];
    }
    cout << ans << '\n';
  }
}