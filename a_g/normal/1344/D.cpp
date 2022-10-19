#include <bits/stdc++.h>
using namespace std;

long long f(int a, int b) {
  return b*(a-1LL*b*b);
}

long long g(int a, int b) {
  // f(a, b+1)-f(a, b) (avoid overflow)
  if (b == -1) return 5e18;
  return a-3LL*b*b-3LL*b-1;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  long long n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  for (int& x: a) cin >> x;

  long long low = -4e18;
  long long high = 4e18;
  // first step: take everything with benefit >= x, as long as we take <= k
  // things
  auto take = [&] (long long m) {
    for (int i = 0; i < n; i++) {
      int x = a[i];
      int low2 = 0;
      int high2 = x+1;
      while (high2-low2 > 1) {
        int mid2 = (low2+high2)/2;
        if (g(x, mid2-1) >= m) low2 = mid2;
        else high2 = mid2;
      }
      b[i] = low2;
    }
  };

  while (high-low > 1) {
    long long mid = (high+low)/2;
    take(mid);
    if (accumulate(b.begin(), b.end(), 0LL) > k) low = mid;
    else high = mid;
  }

  take(high);
  long long extra = k-accumulate(b.begin(), b.end(), 0LL);
  assert(extra <= n);
  for (int i = 0; i < n; i++) {
    if (!extra) break;
    while (g(a[i], b[i]) == high-1) {
      b[i]++;
      extra--;
    }
  }
  for (int x: b) {
    cout << x << ' ';
  }
  cout << '\n';
}