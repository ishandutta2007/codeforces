#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int INF = 1e9;
int L[N], R[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  fill(L, L+N, INF);
  fill(R, R+N, -INF);
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    L[x] = min(L[x], i);
    R[x] = i;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j: {i-1, i, i+1}) {
      if (j < 1 || j > n) continue;
      ans += L[i]>R[j];
    }
  }
  cout << ans << '\n';
}