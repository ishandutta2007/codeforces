#include <bits/stdc++.h>
using namespace std;

const int N = 18;
int dp[1<<N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  vector<long long> mask(n);
  long long s = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i] >> mask[i];
    s += v[i];
  }
  if (s < 0) {
    for (int i = 0; i < n; i++) {
      v[i] = -v[i];
    }
  }
  auto calc = [&] (long long low, long long high) {
    assert((low|high) == high);
    long long ans = 0;

    long long diff = low^high;
    bool cons = 1;
    unordered_map<long long, int> m;

    for (int i = 0; i < n; i++) {
      long long lm = low&mask[i];
      long long hm = high&mask[i];
      if (lm == hm) {
        ans += (__builtin_popcountll(lm)&1 ? -1 : 1)*v[i];
      }
      else {
        m[lm^hm] += (__builtin_popcountll(lm)&1 ? -1 : 1)*v[i];
      }
    }
    for (const pair<long long, int>& p: m) {
      if (p.second != 0) cons = 0;
    }
    return ans+cons;
  };

  long long ans = 0;
  for (int i = 61; i >= 0; i--) {
    // slice the search space in half
    long long low = ans;
    long long high = ans | ((1LL<<i)-1);
    long long z = 1LL<<i;
    if (calc(low, high) > 0) {
      //assert(calc(low|z, high|z) <= 0);
      ans |= z;
    }
  }
  cout << ans << '\n';
}