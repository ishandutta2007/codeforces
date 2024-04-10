#include <bits/stdc++.h>
using namespace std;

long long dp[55];
char st[55], en[55];

const string S = "ABC";

string f(char start, char end, int len, int internal) {
  string ans(len, ' ');
  ans[0] = start;
  ans[len-1] = end;
  if (len <= 2) return ans;
  int cnt = 0;
  if (start == 'A') {
    for (int i = 1; i < len-1; i++) {
      if (cnt < internal) {
        ans[i] = "AC"[i&1];
        cnt += i&1;
      }
      else ans[i] = 'B';
    }
    return ans;
  }
  for (int i = 1; i < len-1; i++) {
    if (cnt < internal) {
      ans[i] = "AC"[1-(i&1)];
      cnt += 1-(i&1);
    }
    else ans[i] = 'B';
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int k, x, n, m;
  cin >> k >> x >> n >> m;
  for (char start1: S) {
    for (char start2: S) {
      for (char end1: S) {
        for (char end2: S) {
          if (n == 1 && start1 != end1) continue;
          if (m == 1 && start2 != end2) continue;
          int max_internal_1 = (n-1)/2;
          int min_internal_1 = (n == 2 && start1 == 'A' && end1 == 'C');
          if (n&1 && n > 1 && start1 != 'A' && end1 != 'C') max_internal_1--;
          if (!(n&1) && start1 == 'A' && end1 == 'C') max_internal_1++;
          int max_internal_2 = (m-1)/2;
          int min_internal_2 = (m == 2 && start2 == 'A' && end2 == 'C');
          if (m&1 && m > 1 && start2 != 'A' && end2 != 'C') max_internal_2--;
          if (!(m&1) && start2 == 'A' && end2 == 'C') max_internal_2++;
          st[1] = start1;
          en[1] = end1;
          st[2] = start2;
          en[2] = end2;
          for (int i = min_internal_1; i <= max_internal_1; i++) {
            for (int j = min_internal_2; j <= max_internal_2; j++) {
              dp[1] = i;
              dp[2] = j;
              for (int l = 3; l <= k; l++) {
                st[l] = st[l-2];
                en[l] = en[l-1];
                dp[l] = dp[l-2]+dp[l-1] + (en[l-2] == 'A' && st[l-1] == 'C');
              }
              if (dp[k] == x) {
                cout << f(start1, end1, n, i) << '\n';
                cout << f(start2, end2, m, j) << '\n';
                return 0;
              }
            }
          }
        }
      }
    }
  }
  cout << "Happy new year!\n";
}