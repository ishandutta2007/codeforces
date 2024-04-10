#include <bits/stdc++.h>

using namespace std;

string s;
int n, k, cnt[30];

int main() {
  cin >> s >> k;
  n = s.size();
  if (n < k) {
    puts("impossible");
    return 0;
  }
  for (char c : s) {
    ++cnt[c - 'a'];
  }
  int tot = 0;
  for (int i = 0; i < 26; ++i) {
    if (cnt[i] > 0) {
      ++tot;
    }
  } 
  cout << max(0, k - tot) << '\n';
  return 0;
}