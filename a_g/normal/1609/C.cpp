#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e6+2;
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  vector<bool> is_prime(maxn, 1);
  is_prime[0] = 0;
  is_prime[1] = 0;
  for (int i = 2; i < maxn; i++) {
    if (is_prime[i]) {
      for (int j = 2*i; j < maxn; j += i) {
        is_prime[j] = 0;
      }
    }
  }
  int T;
  cin >> T;
  while (T--) {
    int e, n;
    cin >> n >> e;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    for (int i = 0; i < e; i++) { 
      for (int j = i; j < n; j += e) {
        if (is_prime[a[j]]) {
          ll left = 0;
          ll right = 0;
          for (int k = j+e; k < n; k += e) {
            if (a[k] != 1) break;
            left++;
          }
          for (int k = j-e; k >=0; k -= e) {
            if (a[k] != 1) break;
            right++;
          }
          ans += (left+1)*(right+1)-1;
        }
      }
    }
    cout << ans << '\n';
  }
}