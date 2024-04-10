#include <bits/stdc++.h>
using namespace std;

const int N = 20;
using repr = array<int, N>;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    repr offset;
    for (int i = 0; i < N; i++) offset[i] = 0;
    auto digits = [&] (int x) {
      repr ans;
      for (int i = 0; i < N; i++) {
        ans[i] = x%k;
        x /= k;
      }
      return ans;
    };
    auto val = [&] (repr v) {
      int ans = 0;
      for (int i = N-1; i >= 0; i--) {
        ans *= k;
        ans += v[i];
      }
      return ans;
    };

    auto add = [&] (repr x, repr y) {
      repr ans;
      for (int i = 0; i < N; i++) {
        ans[i] = (x[i]+y[i])%k;
      }
      return ans;
    };
    auto sub = [&] (repr x, repr y) {
      repr ans;
      for (int i = 0; i < N; i++) {
        ans[i] = (k+x[i]-y[i])%k;
      }
      return ans;
    };

    for (int i = 0; i < n; i++) {
      repr guess = add(digits(i), offset);
      cout << val(guess) << endl;
      int r;
      cin >> r;
      if (r) break;
      offset = add(offset, guess);
    }
  }
}