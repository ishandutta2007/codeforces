#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
map<pair<int, long long>, int> memo;

int len(long long x) {
  long long z = 10;
  int ans = 1;
  while (x >= z) {
    z *= 10;
    ans++;
    if (ans > 18) return 19;
  }
  return ans;
}

int calc(int n, long long x) {
  pair<int, long long> p = {n, x};
  if (memo.count(p)) return memo[p];
  if (len(x) == n) return 0;
  set<int> digits;
  long long y = x;
  while (y) {
    if (y%10) digits.insert(y%10);
    y /= 10;
  }
  if (digits.size() == 1 && *digits.begin() == 1) {
    return INF;
  }
  int ans = INF;
  for (int d: digits) {
    if (d > 1) {
      long long z = x*d;
      if (z/d == x) ans = min(ans, calc(n, z)+1);
      else ans = 1;
    }
  }
  memo[p] = ans;
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  long long x;
  cin >> n >> x;
  int k = calc(n, x);
  cout << (k == INF ? -1 : k) << '\n';
}