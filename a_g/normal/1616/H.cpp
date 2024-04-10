#include <bits/stdc++.h>
using namespace std;

const int N = 150002;
const int MOD = 998244353;
int x;
int p2[N];

int solve2(vector<int>&a, vector<int>&b, int i) {
  if (!a.size() || !b.size()) return 0;
  if (i == -1) {
    return 1LL * (p2[a.size()]-1) * (p2[b.size()]-1) % MOD;
  }
  vector<int> aparts[2];
  vector<int> bparts[2];
  for (int val: a) {
    aparts[(val>>i)&1].push_back(val);
  }
  for (int val: b) {
    bparts[(val>>i)&1].push_back(val);
  }
  if (x&(1<<i)) {
    int p = (0LL + solve2(aparts[0], bparts[1], i-1) + p2[aparts[0].size()] + p2[bparts[1].size()] - 1) % MOD;
    int q = (0LL + solve2(aparts[1], bparts[0], i-1) + p2[aparts[1].size()] + p2[bparts[0].size()] - 1) % MOD;
    int ans = (1LL * p * q - p2[a.size()] - p2[b.size()] + 1) % MOD;
    return (ans+MOD)%MOD;
  }
  return (solve2(aparts[0], bparts[0], i-1) + solve2(aparts[1], bparts[1], i-1)) % MOD;
}

int solve1(vector<int>& a, int i) {
  if (!a.size()) return 0;
  if (i == -1) {
    return p2[a.size()]-1;
  }
  vector<int> left_part;
  vector<int> right_part;
  for (int val: a) {
    if (val&(1<<i)) right_part.push_back(val);
    else left_part.push_back(val);
  }

  int ans = 0;
  if (x&(1<<i)) {
    ans = (p2[left_part.size()] + p2[right_part.size()] - 2)%MOD;
    ans = (ans + solve2(left_part, right_part, i-1))%MOD;
  }
  else {
    ans = (solve1(left_part, i-1) + solve1(right_part, i-1)) % MOD;
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  p2[0] = 1;
  for (int i = 1; i < N; i++) {
    p2[i] = 2 * p2[i-1] % MOD;
  }

  int n;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  cout << solve1(a, 29) << '\n';
}