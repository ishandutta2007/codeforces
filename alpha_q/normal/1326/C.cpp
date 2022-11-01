#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int MOD = 998244353;

bitset <N> vis;
int n, k, p[N];

int main() {
  cin >> n >> k;
  long long best = 0;
  vector <int> pos;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", p + i);
    if (p[i] >= n - k + 1) {
      best += p[i];
      pos.emplace_back(i);
    } 
  }
  long long tot = 1;
  for (int i = 1; i < pos.size(); ++i) {
    tot = tot * (pos[i] - pos[i - 1]) % MOD;
  }
  cout << best << " " << tot << '\n';
  return 0;
}