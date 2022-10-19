#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  string ans;
  ans.push_back(s[0]);
  int index = 1;
  int match = 0;
  while (ans.length() <= k) {
    if (index >= n) break;
    if (s[index] == s[match]) {
      index++;
      match++;
    }
    else if (s[index] > s[match]) break;
    else {
      for (int i = index-match; i <= index; i++) {
        ans.push_back(s[i]);
      }
      match = 0;
      index++;
    }
  }

  string segment = ans;
  while (ans.length() <= k) {
    ans.append(segment);
  }
  ans = ans.substr(0, k);

  cout << ans << endl;
}