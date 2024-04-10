#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, b, k, x;
const int MOD = 1000000007;

vector<int> polymul(vector<int>& a, vector<int>& b) {
  vector<int> ans(x);
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < x; j++) {
      ans[(i+j)%x] += 1LL * a[i] * b[j] % MOD;
      ans[(i+j)%x] %= MOD;
    }
  }
  return ans;
}

vector<int> polyexp(vector<int>& a, int n) {
  vector<int> ans(x);
  ans[0] = 1;
  while (n > 0) {
    if (n & 1) {
      ans = polymul(ans, a);
    }
    n >>= 1;
    a = polymul(a, a);
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> b >> k >> x;
  vector<vector<int>> polys(1, vector<int>(x));
  map<vector<int>, int> seenrows;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    polys[0][val % x]++;
  }
  seenrows[polys[0]] = 0;
  int period;
  while (1) {
    vector<int> nextrow(x);
    for (int i = 0; i < x; i++) {
      nextrow[10*i % x] += polys.back()[i];
    }
    if (seenrows.count(nextrow)) {
      period = polys.size() - seenrows[nextrow];
      break;
    }
    seenrows[nextrow] = polys.size();
    polys.push_back(nextrow);
  }
  vector<int> exponents(polys.size());
  int u = min<int>(polys.size(), b);
  for (int i = 0; i < u; i++) {
    exponents[i]++;
  }
  b -= u;
  for (int i = polys.size() - period; i < polys.size(); i++) {
    exponents[i] += b/period;
  }
  b -= period*(b/period);
  for (int i = polys.size() - period; i < polys.size() - period+b; i++) {
    exponents[i]++;
  }
  vector<int> poly(x);
  poly[0] = 1;
  for (int i = 0; i < polys.size(); i++) {
    vector<int> q = polyexp(polys[i], exponents[i]);
    poly = polymul(poly, q);
  }
  cout << poly[k] << endl;
}