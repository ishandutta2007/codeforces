#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int t, n; 
char s[N];
long long k;

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    long long at = 0;
    int first = 2;
    while (true) {
      at += first - 1;
      if (at >= k) break;
    }
    long long lo = 0, hi = n;
    while (lo < hi) {
      long long mid = lo + hi + 1 >> 1;
      if (mid * (mid - 1) / 2 < k) lo = mid;
      else hi = mid - 1;
    }
    for (int i = 1; i <= n; ++i) s[i] = 'a'; s[n + 1] = 0;
    s[lo + 1] = 'b', s[k - lo * (lo - 1) / 2] = 'b';
    reverse(s + 1, s + n + 1); puts(s + 1);
  }
  return 0;
}