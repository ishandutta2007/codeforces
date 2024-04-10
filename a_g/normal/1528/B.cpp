#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 1e6+3;

int d[N], s[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j+=i) {
      d[j]++;
    }
  }
  s[0] = 1;
  for (int i = 1; i < N; i++) {
    s[i] = (2*s[i-1] + d[i] - 1) % MOD;
  }
  cout << (s[n]-s[n-1]+MOD)%MOD << '\n';

}