#include <bits/stdc++.h>
using namespace std;

const int N = 52;
int gfunc[N*N];
int ans[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, MOD;
  cin >> n >> MOD;

  gfunc[0] = 1;
  for (int m = 2; m < N; m++) {
    ans[m] = 1LL*m*ans[m-1] % MOD;
    int c = ((m-1)*(m-2))/2;
    int k = 0;
    for (int d = 2; d <= c; d++) {
      k += max(m-d+1, 0);
      ans[m] = (ans[m] + 1LL*k*gfunc[c-d]) % MOD;
    }
    for (int i = m*(m-1); i >= 0; i--) {
      for (int j = 1; j <= min(2*m-2, i); j++) {
        gfunc[i] = (gfunc[i]+1LL*min(j+1, 2*m-1-j)*gfunc[i-j]) % MOD;
      }
    }
  }

  cout << ans[n] << endl;
}