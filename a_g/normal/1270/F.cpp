#include <bits/stdc++.h>
#define ll long long
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s;
  cin >> s;
  const int T = 400;
  ll ans = 0;
  int n = s.length();
  vector<int> partials((T+1)*n+1);
  for (int i = 1; i <= T; i++) {
    int sum = n;
    partials[sum] = 1;
    for (int j = 0; j < n; j++) {
      sum += s[j] == '1' ? i-1 : -1;
      ans += partials[sum];
      partials[sum]++;
    }
    for (int j = n-1; j >= 0; j--) {
      partials[sum]--;
      sum -= s[j] == '1' ? i-1 : -1;
    }
  }

  int count = 1;
  vector<int> pos;
  pos.push_back(-1);
  for (int r = 0; r < n; r++) {
    if (s[r] == '1') {
      pos.push_back(r);
      count++;
    }
    for (int i = count-1; i > 0; i--) {
      // use range [r-j+1, r] where pos[i-1] < r-j+1 <= pos[i]
      int ones = count-i;
      if (ones*T > n) break;
      int maxJ = r-pos[i-1];
      int minJ = max((T+1)*ones, r+1-pos[i]);
      ans += max(0, maxJ/ones - (minJ-1)/ones);
    }
  }


  cout << ans << endl;
}