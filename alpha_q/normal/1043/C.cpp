#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 1010;

int wat[N][2], par[N][2], ans[N];
string s, small, large, tmpSmall, tmpLarge;

int main() {
  cin >> s;
  int n = s.size();

  small = large = s[0];
  for (int i = 1; i < n; ++i) {
    string one, two;

    one = large + s[i];
    reverse(one.begin(), one.end());
    two = small + s[i];
    
    if (one < two) {
      tmpSmall = one;
      wat[i][0] = 1;
      par[i][0] = 1;
    } else {
      tmpSmall = two;
      par[i][0] = 0;
    }
    
    one = large + s[i];
    reverse(one.begin(), one.end());
    two = small + s[i];

    if (one < two) {
      tmpLarge = one;
      par[i][1] = 1;
    } else {
      tmpLarge = two;
      wat[i][1] = 1;
      par[i][1] = 0;
    }

    small = tmpSmall;
    large = tmpLarge;
    reverse(large.begin(), large.end());

    // cout << small << " " << large << '\n';
  }

  for (int i = n - 1, at = 0; i > 0; --i) {
    ans[i] = wat[i][at];
    at = par[i][at];
  }
  for (int i = 0; i < n; ++i) {
    printf("%d ", ans[i]);
  }
  puts("");
  return 0;
}