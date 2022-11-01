#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int t, n[3]; 
long long a[3][N];

inline long long get (long long x, long long y, long long z) {
  return (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
}

int main() {
  cin >> t;
  while (t--) {
    scanf("%d %d %d", n, n + 1, n + 2);
    for (int i = 0; i < 3; ++i) {
      for (int j = 1; j <= n[i]; ++j) {
        scanf("%lld", a[i] + j);
      }
      sort(a[i] + 1, a[i] + n[i] + 1);
      n[i] = unique(a[i] + 1, a[i] + n[i] + 1) - a[i] - 1;
    }
    vector <int> id(3);
    id[0] = 0, id[1] = 1, id[2] = 2;
    long long ans = LLONG_MAX;
    do {
      int x = id[0], y = id[1], z = id[2];
      for (int i = 1; i <= n[x]; ++i) {
        long long one = a[x][i];
        int twoL = lower_bound(a[y] + 1, a[y] + n[y] + 1, one) - a[y];
        if (twoL > n[y]) continue;
        int thrPos = lower_bound(a[z] + 1, a[z] + n[z] + 1, a[y][twoL]) - a[z];
        if (thrPos > n[z]) continue;
        long long thr = a[z][thrPos];
        int twoR = upper_bound(a[y] + 1, a[y] + n[y] + 1, thr) - a[y] - 1;
        int lo = twoL, hi = twoR;
        while (lo < hi) {
          int mid = lo + hi >> 1;
          if (get(one, a[y][mid], thr) > get(one, a[y][mid + 1], thr)) lo = mid + 1;
          else hi = mid; 
        }
        long long two = a[y][lo];
        ans = min(ans, get(one, two, thr));
      }
    } while (next_permutation(id.begin(), id.end()));
    printf("%lld\n", ans);
  }
  return 0;
}